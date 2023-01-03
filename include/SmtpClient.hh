#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include "Socket.hh"
#include "Mail.hh"

class SmtpClient
{
public:
    SmtpClient(const char* sender, const char* password);
    void sendMail(Mail mail);

private:
    const char* sender;
    const char* password;
    Socket socket;
    void messageHost(const char* text);
};

#endif