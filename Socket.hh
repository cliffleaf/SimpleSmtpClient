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

    // combine socket() and connect() with some pre-defined parameters
    int connectToHost();
    // void read();
    // void write(const char* text);
    // void terminate();

private:
    const char* hostname;
    int port;
    sockaddr_in buildServerAddress(char* hostaddr);
    void hostnameToIp(char* hostname , char* hostaddr);
};

#endif