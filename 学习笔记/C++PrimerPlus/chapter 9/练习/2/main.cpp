#include <iostream>
#include <string>
void strcount(const std::string &);

void strcount(const std::string & str)
{
    static int total = 0;
    int count = str.length();
    total += count;
    std::cout << "Count: " << count << std::endl;
    std::cout << "Total: " << total << std::endl;
}

int main()
{
    std::string input;
    while (std::getline(std::cin,input)){
        strcount(input);
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}

