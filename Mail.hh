#ifndef MAIL_H
#define MAIL_H

#include "RecipientsList.hh"

class Mail
{
public:
    Mail(RecipientsList recipients, const char* message);
    Mail(RecipientsList recipient, const char* subject, const char* message);

    RecipientsList getRecipients();
    const char* getSubject();
    const char* getMessage();

private:
    RecipientsList recipients;
    const char* subject;
    const char* message;
};

#endif