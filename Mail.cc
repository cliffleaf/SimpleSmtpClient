#include "Mail.hh"

Mail::Mail(RecipientsList recipients, const char* message)
{
    this->recipients = recipients;
    this->subject = "";
    this->message = message;
}

Mail::Mail(RecipientsList recipients, const char* subject, const char* message)
{
    this->recipients = recipients;
    this->subject = subject;
    this->message = message;
}

RecipientsList Mail::getRecipients()
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