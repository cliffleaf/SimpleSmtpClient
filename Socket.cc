#include "./Socket.hh"
#include <WinSock2.h> // replaced with sys/socket.h if programming in Linux
#include <stdio.h>

Socket::Socket(const char* host, int port)
{
    this->host = host;
    this->port = port;
}

int Socket::connectToHost()
{
    int socketfd, con;

    // socket(int domain, int type, int protocol)
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        printf("undable to open socket\n");
        return socketfd;
    }

    sockaddr_in serverAddress = this->buildServerAddress();

    con = connect(socketfd, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
    if (con < 0) {
        printf("unable to connect to host\n");
    } else {
        printf("connected to host\n");
    }

    return con;
}

sockaddr_in Socket::buildServerAddress()
{
    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.S_un.S_addr = inet_addr(this->host);
    serverAddress.sin_port = htons(this->port);
    

    return serverAddress;
}