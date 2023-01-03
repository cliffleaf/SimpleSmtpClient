#ifndef SOCKET_H
#define SOCKET_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <stdio.h>
#include <string.h>

class Socket
{
public:
    Socket(const char* hostname, int port);

    int connectToHost();
    // int read();
    int write(const char* text);
    // void terminate();

private:
    const char* hostname;
    int port;
    int socketfd;
    sockaddr_in buildServerAddress(char* hostaddr);
    void hostnameToIp(char* hostname , char* hostaddr);
};

#endif