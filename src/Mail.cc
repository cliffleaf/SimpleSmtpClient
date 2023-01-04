#include "../include/Mail.hh"

Mail::Mail(const char* sender, std::vector<std::string> recipients, const char* message)
{
    this->sender = sender;
    this->recipients = recipients;
    this->subject = "";
    this->message = message;
}

Mail::Mail(const char* sender, std::vector<std::string> recipients, const char* subject, const char* message)
{
    this->sender = sender;
    this->recipients = recipients;
    this->subject = subject;
    this->message = message;
}

const char* Mail::getSender()
{
    return this->sender;
}

std::vector<std::string> Mail::getRecipients()
{
    return this->recipients;
}

const char* Mail::getSubject()
{
    return this->subject;
}

const char* Mail::getMessage()
{
    return this->message;
}