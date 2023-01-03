#ifndef RECIPIENTS_LIST_H
#define RECIPIENTS_LIST_H

#include <iostream>
#include <string>
#include <vector>

class RecipientsList
{
public:
    RecipientsList(std::vector<std::string> recipients);
    
    void addRecipient(std::string recipient);

private:
    std::vector<std::string> recipients;
};

#endif