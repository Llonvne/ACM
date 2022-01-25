//choices.cpp -- array variation
#include <iostream>
#include <array>
#include <vector>

int main()
{
    // C / original C++
    // typename arrayname[arraysize];
    double intarray[1000] = {1.2, 2.4, 3.6, 4.8};

    // C++98 STL vector
    // std::vector<typename> arrayname;
    std::vector<int> intvector(4);
    // use () construction function to initialize vector size;

    // C++ 11 STL array ~ C array
    // std::array<typename,size> arrayname;
    std::array<int, 1000> cppintarray;
    return 0;
}