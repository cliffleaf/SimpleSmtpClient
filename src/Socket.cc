#include "../include/Socket.hh"

Socket::Socket(const char* hostname, int port)
{
    this->hostname = hostname;
    this->port = port;
}

int Socket::connectToHost()
{
    char hostaddr[100];
    this->hostnameToIp( (char*) this->hostname, hostaddr);

    // socket(int domain, int type, int protocol)
    this->socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        printf("undable to open socket\n");
        return socketfd;
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

    return con;
}

int Socket::write(const char* text)
{
    return send(this->socketfd, text, strlen(text), 0);
}

sockaddr_in Socket::buildServerAddress(char* hostaddr)
{
    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    if (inet_pton(AF_INET, hostaddr, &serverAddress.sin_addr) <= 0)
        printf("invalid address\n");

    serverAddress.sin_port = htons(this->port);

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