#include <cctype>
#include "vigenere.h"
#include "funcs.h"

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
    std::size_t i = 0;
    std::string s;
    for (auto& c : plaintext)
    {
        s.push_back(shiftChar(c, keyword[i % keyword.size()] - 'a'));
        i += (std::isalpha(c) != 0);
    }
    return s;
}
