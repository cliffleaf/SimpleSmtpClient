#ifndef UTIL_H
#define UTIL_H

#include <string.h>
#include <stdio.h>
#include <string>

class Util
{
public:
    static std::string substring(const char* word, int start, int end);
};

#endif