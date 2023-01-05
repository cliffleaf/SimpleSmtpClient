#include "../include/SmtpClient.hh"

SmtpClient::SmtpClient(const char* hostname, 
                int port, 
                const char* username, 
                const char* password)
{
    this->socket.setHostname(hostname);
    this->socket.setPort(port);
    this->username = username;
    this->password = password;
}

void SmtpClient::sendMail(Mail mail)
{
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

    std::cout << this->username << std::endl;
    messageHost(this->username, "");
    if ( (responseCode = getResponse()) != 334) {
        std::cout << "wrong username " << responseCode << std::endl;
        return -1;
    } 

    messageHost(this->password, "");
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

    messageHost("MAIL FROM: ", sender); 
    if ( (responseCode = this->getResponse()) != 250) {
        std::cout << "wrong sender address " << responseCode << std::endl;
        return -1;
    } 

    for (int i = 0; i < recipients.size(); i++) {
        messageHost("RCPT TO: ", recipients[i].c_str());
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
    // impossible to concatenate const char*, therefore append them to a new char[]
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
    std::cout << responseCode << std::endl;
    int code = std::stoi(responseCode);
    printf("%s\n", this->readBuffer);

    return code;
}