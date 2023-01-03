#include "RecipientsList.hh"

RecipientsList::RecipientsList()
{
    // recipients attribute is initialised with empty vector
}

RecipientsList::RecipientsList(std::vector<std::string> recipients)
{
    this->recipients = recipients;
}

void RecipientsList::addRecipient(std::string recipient)
{
    this->recipients.push_back(recipient);
}

std::vector<std::string> RecipientsList::getRecipients()
{
    return this->recipients;
}