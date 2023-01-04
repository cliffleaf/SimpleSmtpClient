#include "../include/SmtpClient.hh"

SmtpClient::SmtpClient(const char* hostname, int port)
{
    this->socket.setHostname(hostname);
    this->socket.setPort(port);
}

void SmtpClient::sendMail(Mail mail)
{
    // https://mailtrap.io/blog/smtp-commands-and-responses/
    int responseCode;
    
    this->socket.connectToHost();
    if ( (responseCode = getResponse()) != 220) {
        std::cout << "server connected with error code " << responseCode << std::endl;
        return;
    }

    messageHost("EHLO client", "");
    if ( (responseCode = getResponse()) != 250) {
        std::cout << "EHLO failed with error code " << responseCode << std::endl;
        return;
    } 

    if (this->authenticateCommands() == -1) return;

    const char* sender = mail.getSender();
    std::vector<std::string> recipients = mail.getRecipients();
    const char* subject = mail.getSubject();
    const char* message = mail.getMessage();

    if (this->mailCommands(sender, recipients, subject, message) == -1) return;

    // quit connection
    messageHost("QUIT ", "");
}

int SmtpClient::authenticateCommands()
{
    int responseCode;

    // login with AUTH
    messageHost("AUTH LOGIN", "");
    if ( (responseCode = getResponse()) != 334) {
        std::cout << "AUTH failed with error code " << responseCode << std::endl;
        return -1;
    } 

    messageHost("a2V2aW5saWFuZzA0MzBAZ21haWwuY29t", "");
    if ( (responseCode = getResponse()) != 334) {
        std::cout << "wrong username " << responseCode << std::endl;
        return -1;
    } 

    messageHost("NTZjZTBjODFjMDRiODJkMGVlOTgyNjlkNTU3MzhkYzAtdXMx", "");
    if ( (responseCode = getResponse()) != 235) {
        std::cout << "wrong password " << responseCode << std::endl;
        return -1;
    } 

    return 0;
}

int SmtpClient::mailCommands(const char* sender, 
                    std::vector<std::string> recipients, 
                    const char* subject,
                    const char* message)
{
    int responseCode;

    messageHost("MAIL FROM ", sender); 
    if ( (responseCode = this->getResponse()) != 250) {
        std::cout << "wrong sender address " << responseCode << std::endl;
        return -1;
    } 

    for (int i = 0; i < recipients.size(); i++) {
        messageHost("RCPT TO ", recipients[i].c_str());
        if ( (responseCode = this->getResponse()) != 250) {
            std::cout << "wrong recipient address " << responseCode << std::endl;
            return -1;
        } 
    }

    messageHost("DATA", "");
    if ( (responseCode = this->getResponse()) != 354) {
        std::cout << "DATA command error " << responseCode << std::endl;
        return -1;
    }

    messageHost(message, "");
    messageHost(".", "");
    if ( (responseCode = this->getResponse()) != 250) {
        std::cout << "email content error " << responseCode << std::endl;
        return -1;
    }

    return 0;
}

void SmtpClient::messageHost(const char* command, const char* param)
{
    char msg[strlen(command) + strlen(param) + 2];
    strcpy(msg, command);
    strcat(msg, param);
    strcat(msg, "\r\n");

    this->socket.write(msg);
}

int SmtpClient::getResponse()
{
    // socket reads the server response, then copy it to readBuffer
    this->socket.read(&(readBuffer[0]));

    std::string responseCode = Util::substring(readBuffer, 0, 3);
    int code = std::stoi(responseCode);
    printf("%s\n", this->readBuffer);

    return code;
}