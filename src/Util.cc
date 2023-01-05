#include "../include/Util.hh"

std::string Util::substring(const char* word, int start, int end)
{
    char substring[strlen(word)];
    strncpy(substring, word+start, end-start);

    std::string out = (const char*) substring;
    return out;
}

std::string Util::base64_encode(char const* bytes, unsigned int length) {
    // credit to https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];
    std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/ ";

    while (length--) {
        char_array_3[i++] = *(bytes++);
        if (i == 3) {
        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for(i = 0; (i <4) ; i++)
            ret += base64_chars[char_array_4[i]];
        i = 0;
        }
    }

    if (i)
    {
        for(j = i; j < 3; j++)
        char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
        ret += base64_chars[char_array_4[j]];

        while((i++ < 3))
        ret += '=';

    }

    return ret;

}