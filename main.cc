#include "./Socket.hh"

void hostname_to_ip(char* hostname , char* ip);

int main(int argc, char *argv[])
{
    char* hostname = (char*) "smtp.gmail.com";
    int port = 587;

    Socket socket(hostname, port);
    printf("%d\n", socket.connectToHost());
    return 0;
}

// g++ -o main main.cc Socket.cc
// ./main.exe