#ifndef SOCKET_H
#define SOCKET_H

#include <WinSock2.h> // replaced with sys/socket.h if programming in Linux

class Socket
{
public:
    Socket(const char* host, int port);

    // combine socket() and connect() with some pre-defined parameters
    int connectToHost();
    void read();
    void write(const char* text);
    void terminate();

private:
    const char* host;
    int port;
    sockaddr_in buildServerAddress();
};

#endif