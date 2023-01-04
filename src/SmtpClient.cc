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

    // login with AUTH
    messageHost("AUTH LOGIN");
    if ( (responseCode = getResponse()) != 334) {
        std::cout << "AUTH failed with error code " << responseCode << std::endl;
        return;
    } 

    messageHost("a2V2aW5saWFuZzA0MzBAZ21haWwuY29t");
    if ( (responseCode = getResponse()) != 334) {
        std::cout << "wrong username " << responseCode << std::endl;
        return;
    } 

    messageHost("NTZjZTBjODFjMDRiODJkMGVlOTgyNjlkNTU3MzhkYzAtdXMx");
    if ( (responseCode = getResponse()) != 235) {
        std::cout << "wrong password " << responseCode << std::endl;
        return;
    } 

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
    this->socket.read(&(readBuffer[0]));

    std::string responseCode = Util::substring(readBuffer, 0, 3);
    int code = std::stoi(responseCode);
    printf("%s\n", this->readBuffer);

    return code;
}

void SmtpClient::wrongResponseMsg(int code, std::string message)
{
    int responseCode;
    if ( (responseCode = this->getResponse()) != code) {
        std::cout << message << " " << responseCode << std::endl;
    } 
}