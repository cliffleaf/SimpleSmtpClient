#include "headers.hh"
#include "include/Util.hh"

void tryClient();

int main(int argc, char *argv[])
{
    tryClient();

    return 0;
}

void tryClient()
{
    const char* sender = "kevinliang0430@gmail.com";
    const char* subject = "hello";
    const char* message = "lol";
    std::vector<std::string> recipients;
    recipients.push_back("kevinliang0430@gmail.com");

    Mail mail(sender, recipients, subject, message);

    const char* hostname = "smtp.mandrillapp.com";
    int port = 2525;
    SmtpClient client(hostname, port);
    client.sendMail(mail);

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
}

// g++ -o main main.cc src/Socket.cc src/SmtpClient.cc src/Mail.cc src/Util.cc
// ./main