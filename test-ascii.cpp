#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::getline(std::cin, s);
    for (auto c : s)
        std::cout << c << ' ' << (int)c << '\n';
    return 0;
}
