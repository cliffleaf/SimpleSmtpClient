#include "../include/Util.hh"

std::string Util::substring(const char* word, int start, int end)
{
    char substring[strlen(word)];
    strncpy(substring, word+start, end-start);

    std::string out = (const char*) substring;
    return out;
}