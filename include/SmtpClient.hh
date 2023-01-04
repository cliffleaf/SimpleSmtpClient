#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include "Socket.hh"
#include "Mail.hh"

class SmtpClient
{
public:
    SmtpClient(const char* hostname, int port);
    void sendMail(Mail mail);

private:
    Socket socket;
    char readBuffer[4096];
    void messageHost(const char* text);
    void getResponse();
};

#endif