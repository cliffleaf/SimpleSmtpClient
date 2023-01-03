#include "../include/SmtpClient.hh"

SmtpClient::SmtpClient(const char* sender, const char* password) 
    : socket("smtp.gmail.com", 587)
{
    this->sender = sender;
    this->password = password;
}

void SmtpClient::sendMail(Mail mail)
{
    // connect to host
    this->socket.connectToHost();
    // send HELO
    messageHost("HELO message");
    // login with AUTH

    // send smtp commands
    RecipientsList recipients = mail.getRecipients();
    const char* subject = mail.getSubject();
    const char* message = mail.getMessage();
    // quit connection
}

void SmtpClient::messageHost(const char* text)
{
    this->socket.write(text);
}