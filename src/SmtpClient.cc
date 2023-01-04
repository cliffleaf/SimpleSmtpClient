#include "../include/SmtpClient.hh"

SmtpClient::SmtpClient(const char* hostname, int port)
{
    this->socket.setHostname(hostname);
    this->socket.setPort(port);
}

void SmtpClient::sendMail(Mail mail)
{
    // connect to host
    this->socket.connectToHost();

    messageHost("EHLO client");
    getResponse();
    messageHost("STARTTLS");
    getResponse();

    // login with AUTH

    // send smtp commands
    const char* sender = mail.getSender();
    std::vector<std::string> recipients = mail.getRecipients();
    const char* subject = mail.getSubject();
    const char* message = mail.getMessage();
    // quit connection
}

void SmtpClient::messageHost(const char* text)
{
    char msg[strlen(text)+2];
    strcpy(msg, text);
    strcat(msg, "\r\n");

    this->socket.write(msg);
}

void SmtpClient::getResponse()
{
    // socket reads the server response, then copy it to readBuffer
    this->socket.read(this->readBuffer);
    printf("%s\n", this->readBuffer);
}