#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include "Socket.hh"
#include "Mail.hh"
#include "Util.hh"

class SmtpClient
{
public:
    SmtpClient(const char* hostname, int port);
    void sendMail(Mail mail);

private:
    Socket socket;
    char readBuffer[4096];
    void messageHost(const char* command, const char* param);
    int authenticateCommands();
    int mailCommands(const char* sender, 
                    std::vector<std::string> recipients, 
                    const char* subject,
                    const char* message);
    int getResponse();
};

#endif