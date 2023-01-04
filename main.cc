#include "include/Socket.hh"

int main(int argc, char *argv[])
{
    char* hostname = (char*) "smtp.gmail.com";
    int port = 587;

    Socket socket(hostname, port);
    socket.connectToHost();
    socket.read();

    // socket.write("EHLO client.net\r\n");
    // socket.read();
    // socket.write("STARTTLS\r\n");
    // socket.read();
    // socket.write("EHLO client.net\r\n");

    // socket.write("AUTH PLAIN AGtsaWE0NDdAYXVja2xhbmR1bmkuYWMubnoAS0hhcmJpbjMw=\r\n");
    // socket.read();
    // socket.write("MAIL FROM kevinliang0430@gmail.com\r\n");
    // socket.write("RCPT TO kevinliang0430@gmail.com\r\n");
    // socket.write("DATA\n354\nhello\n.\r\n");
    // socket.write("QUIT\r\n");
    // socket.read();

    return 0;
}

// g++ -o main main.cc src/Socket.cc
// ./main