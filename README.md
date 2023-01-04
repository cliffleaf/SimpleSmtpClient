# SmtpClient
A simple SMTP client, allow users to build and send an email to a SMTP server

## Quick Start
clone the project, and create file main.cc, modify as below. 

The SMTP server is mailchimp, also remember to change the AUTH details in ```SmtpClient::mailCommands()```

```c++

#include "headers.hh"

void tryClient()
{
    const char* sender = "your@email";
    const char* subject = ?;
    const char* message = ?;
    std::vector<std::string> recipients;
    recipients.push_back("recipient@email");

    Mail mail(sender, recipients, subject, message);

    const char* hostname = "smtp.mandrillapp.com";
    int port = 2525;
    SmtpClient client(hostname, port);
    client.sendMail(mail);
}

int main(int argc, char *argv[])
{
    tryClient();

    return 0;
}

```
