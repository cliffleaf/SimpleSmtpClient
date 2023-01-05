# SmtpClient
A simple SMTP client, allow users to send emails through an existing SMTP server

### Quick Start
Clone the project, and create a new file in root directory for int main() 

```c++

#include "headers.hh"

int main(int argc, char *argv[])
{
    return 0;
}
```

Build an email with sending address, subject, message and a list of recipients

```c++

    const char* sender = "your@email";
    const char* subject = "subject";
    const char* message = "message";
    std::vector<std::string> recipients;

    // for testing purpose, the recipient email is the same as sending email
    recipients.push_back(sender);

    Mail mail(sender, recipients, subject, message);

```

The SMTP server is mailchimp, we need some configurations in [mandrillapp settings](mandrillapp.com)

- username: your primary email address 
- password: the api key for mandrillapp

They have to be encoded into base64 format. We are still working on automatic base64 conversion, 
for now you have to do it on your own

```c++
    const char* hostname = "smtp.mandrillapp.com";
    int port = 2525;
    const char* username = "base64 username";
    const char* password = "base64 password";

    SmtpClient client(hostname, port, username, password);
    client.sendMail(mail);

```

Then compile with ```g++ -o client main.cc src/SmtpClient.cc src/Socket.cc src/Mail.cc src/Util.cc```

Run ```./client```

### Helpful Article
[SMTP commands](https://mailtrap.io/blog/smtp-commands-and-responses)

[Mailchimp SMTP documentation](https://mailchimp.com/developer/transactional/docs/smtp-integration/#send-via-smtp-with-your-programming-language-of-choice)

[Troubleshooting common SMTP issues](https://www.juniper.net/documentation/en_US/cso5.0/topics/task/troubleshooting/troubleshooting-smtp-issues.html)

[RFC 3207 if you need TLS connection](https://www.rfc-editor.org/rfc/rfc3207)
