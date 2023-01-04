#ifndef MAIL_H
#define MAIL_H

#include <iostream>
#include <string>
#include <vector>

class Mail
{
public:
    Mail(const char* sender, std::vector<std::string> recipients, const char* message);
    Mail(const char* sender, std::vector<std::string> recipients, const char* subject, const char* message);

    const char* getSender();
    std::vector<std::string> getRecipients();
    const char* getSubject();
    const char* getMessage();

private:
    const char* sender;
    std::vector<std::string> recipients;
    const char* subject;
    const char* message;
};

#endif