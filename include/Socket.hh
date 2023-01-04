#ifndef SOCKET_H
#define SOCKET_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <string>

class Socket
{
public:
    Socket();
    Socket(const char* hostname, int port);

    void connectToHost();
    void write(const char* text);
    void read(char* returnMsg);
    void setHostname(const char* hostname);
    void setPort(int port);

private:
    const char* hostname;
    int port;
    int socketfd;

    sockaddr_in buildServerAddress(char* hostaddr);
    void hostnameToIp(char* hostname , char* hostaddr);
};

#endif