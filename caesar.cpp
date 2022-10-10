#include <string>
#include <cctype>
#include "funcs.h"

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift)
{
    std::string s;
    for (auto& c : plaintext)
        s.push_back(shiftChar(c, rshift));
    return s;
}

