#include "./Socket.hh"

Socket::Socket(const char* host, int port)
{
    this->host = host;
    this->port = port;
}

int Socket::connectToHost()
{
    // combine socket() and connect() with some pre-defined parameters
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddress = this->buildServerAddress();

    int con = connect(socketfd, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
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