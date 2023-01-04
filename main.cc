#include "include/Socket.hh"
#

int main(int argc, char *argv[])
{
    char* hostname = (char*) "smtp.gmail.com";
    int port = 587;

    Socket socket(hostname, port);
    socket.connectToHost();
    socket.read();

    // socket.write("EHLO client.net\r\n");
    // socket.read();
    // socket.write("AUTH PLAIN")
    // socket.write("MAIL FROM kevinliang0430@gmail.com");
    // socket.write("RCPT TO kevinliang0430@gmail.com");
    // socket.write("DATA\n354\nhello\n.");

    return 0;
}

// g++ -o main main.cc src/Socket.cc
// ./main