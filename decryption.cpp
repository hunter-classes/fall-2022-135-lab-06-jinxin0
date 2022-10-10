#include <cctype>
#include "decryption.h"
#include "caesar.h"
#include "vigenere.h"
#include "funcs.h"

std::string decryptCaesar(std::string ciphertext, int rshift)
{
    return encryptCaesar(ciphertext, 26 - rshift);
}

std::string decryptVigenere(std::string ciphertext, std::string keyword)
{
    std::string anti_keyword;
    for (char c : keyword)
        anti_keyword.push_back('z' - c + 1 + 'a');
    return encryptVigenere(ciphertext, anti_keyword);
}
