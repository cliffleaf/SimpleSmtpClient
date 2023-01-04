#include "../include/SmtpClient.hh"

SmtpClient::SmtpClient(const char* hostname, int port)
{
    this->socket.setHostname(hostname);
    this->socket.setPort(port);
}

void SmtpClient::sendMail(Mail mail)
{
    int responseCode;
    
    this->socket.connectToHost();
    if ( (responseCode = getResponse()) != 220) {
        std::cout << "server connected with error code " << responseCode << std::endl;
        return;
    }

    messageHost("EHLO client");
    if ( (responseCode = getResponse()) != 250) {
        std::cout << "EHLO failed with error code " << responseCode << std::endl;
        return;
    } 

    messageHost("STARTTLS");
    if ( (responseCode = getResponse()) != 220) {
        std::cout << "STARTTLS failed with error code " << responseCode << std::endl;
        return;
    } 

    // login with AUTH

    // send smtp commands
    const char* sender = mail.getSender();
    std::vector<std::string> recipients = mail.getRecipients();
    const char* subject = mail.getSubject();
    const char* message = mail.getMessage();

    // quit connection
    messageHost("QUIT");
}

void SmtpClient::messageHost(const char* text)
{
    char msg[strlen(text)+2];
    strcpy(msg, text);
    strcat(msg, "\r\n");

    this->socket.write(msg);
}

int SmtpClient::getResponse()
{
    // socket reads the server response, then copy it to readBuffer
    // this->socket.read(this->readBuffer);
    this->socket.read(&(readBuffer[0]));
    printf("here\n");

    std::string responseCode = Util::substring(readBuffer, 0, 3);
    int code = std::stoi(responseCode);
    printf("%s\n", this->readBuffer);

    return code;
}