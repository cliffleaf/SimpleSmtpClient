# SmtpClient
custom smtp client application

```

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
}

```
