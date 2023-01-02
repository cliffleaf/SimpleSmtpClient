#include "./Socket.hh"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Socket socket("127.0.0.1", 8080);
    printf("%d", socket.connectToHost());
 
    return 0;
}