#include <utility>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"

TEST_CASE("Caesar Cipher")
{
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("Hello, World!", 36) == "Rovvy, Gybvn!");
}

TEST_CASE("Vigenere Cipher")
{
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
}

TEST_CASE("Decrypt Caesar")
{
    const std::pair<std::string, int> test1{"Secret TEXT!", 10};
    const std::pair<std::string, int> test2{" The Quick Brown Fox Jumps Over the Lazy Dog", 3};

    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar(encryptCaesar(test1.first, test1.second), test1.second) == test1.first);
    CHECK(decryptCaesar(encryptCaesar(test2.first, test2.second), test2.second) == test2.first);
}

TEST_CASE("Decrypt Vigenere")
{
    const std::pair<std::string, std::string> test1{"Secret TEXT!", "key"};
    const std::pair<std::string, std::string> test2{" The Quick Brown Fox Jumps Over the Lazy Dog", "apple"};

    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
    CHECK(decryptVigenere(encryptVigenere(test1.first, test1.second), test1.second) == test1.first);
    CHECK(decryptVigenere(encryptVigenere(test2.first, test2.second), test2.second) == test2.first);
}
