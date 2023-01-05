#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include "Socket.hh"
#include "Mail.hh"
#include "Util.hh"

class SmtpClient
{
public:
    SmtpClient(const char* hostname, 
                int port, 
                const char* username, 
                const char* password);
    void sendMail(Mail mail);

    void setUsername(const char* username);
    void setPassword(const char* password);

private:
    Socket socket;
    const char* username;
    const char* password;
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