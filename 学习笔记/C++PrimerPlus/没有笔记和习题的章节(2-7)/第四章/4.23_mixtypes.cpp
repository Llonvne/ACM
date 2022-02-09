// mixtype.cpp -- some types combinations
#include <iostream>
struct antarctica_years_end {
    int year;
};

int main(){
    antarctica_years_end s01,s02,s03;
    s01.year = 1998;
    antarctica_years_end * pa = & s02;
    pa->year = 1999;
    antarctica_years_end trio[3];
    // array<antarctica_years_end,3> trio // use C++ template array instead
    trio[0].year =  2000;
    // trio 默认表示首地址 也就是第一个元素
    std::cout << trio->year << std::endl;

    const antarctica_years_end * arp[3] = {&s01,&s02,&s03};
    std::cout << arp[1]->year << std::endl;
    const antarctica_years_end* * ppa = arp;
    auto ppb = arp;
    std::cout << (*ppa)->year << std::endl;
    std::cout << (*(ppb+1))->year << std::endl;
    return 0;

}