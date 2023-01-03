#include "./Socket.hh"
#include <stdio.h>

int main(int argc, char *argv[])
{
    const char* host = "64.233.185.108";
    int port = 587;

    Socket socket(host, port);
    printf("%d\n", socket.connectToHost());
 
    return 0;
}

// g++ -o main main.cc Socket.cc -lws2_32
// ./main.exe