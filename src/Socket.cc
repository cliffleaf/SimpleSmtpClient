#include "../include/Socket.hh"

Socket::Socket()
{

}

Socket::Socket(const char* hostname, int port)
{
    this->hostname = hostname;
    this->port = port;
}

void Socket::connectToHost()
{
    char hostaddr[100];
    this->hostnameToIp( (char*) this->hostname, hostaddr);

    // socket(int domain, int type, int protocol)
    this->socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        printf("undable to open socket\n");
    } else {
        printf("opened socket\n");
    } 

    sockaddr_in serverAddress = this->buildServerAddress(hostaddr);

    int con = connect(socketfd, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
    if (con < 0) {
        printf("unable to connect to hostname\n");
    } else {
        printf("connected to hostname\n");
    }
}

void Socket::write(const char* text)
{
    if (send(this->socketfd, text, strlen(text), 0) != strlen(text)) 
        printf("send error");
    printf("C: %s\n", text);
}

void Socket::read(char* returnMsg) {
    int recvBytes = 100;
    char recvBuffer[recvBytes];

    // zero out the content from last read
    strcpy(returnMsg, "");
    while ( (recv(socketfd, recvBuffer, recvBytes - 1, 0)) > 0 )
    {
        strcat(returnMsg, recvBuffer);
        // if ends with \r\n, then read is completed
        if ((recvBuffer[strlen(recvBuffer)-2] == '\r') && recvBuffer[strlen(recvBuffer)-1] == '\n') {  
            printf("\n");
            return;
        }
        memset(recvBuffer, 0, recvBytes);
    }
}

sockaddr_in Socket::buildServerAddress(char* hostaddr)
{
    struct sockaddr_in serverAddress;
    bzero(&serverAddress, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    if (inet_pton(AF_INET, hostaddr, &serverAddress.sin_addr) <= 0)
        printf("invalid address\n");

    serverAddress.sin_port = htons(this->port);
    bzero(&(serverAddress.sin_zero), sizeof(serverAddress.sin_zero));

    return serverAddress;
}

void Socket::hostnameToIp(char* hostname , char* ip)
{
    struct hostent *he = gethostbyname( hostname );
	if (he == NULL) 
	{
		printf("hostname name invalid\n");
		return;
	}

	struct in_addr ** addr_list = (struct in_addr **) he->h_addr_list;
	for(int i = 0; addr_list[i] != NULL; i++) 
	{
		strcpy(ip , inet_ntoa(*addr_list[i]) );
		return;
	}
}

void Socket::setHostname(const char* hostname)
{
    this->hostname = hostname;
}

void Socket::setPort(int port)
{
    this->port = port;
}