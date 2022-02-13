#include "Sale.h"
#include <iostream>


void SALE::setSales(SALE::Sales & s, double * arr, int n = QUARTERS)
{
    s.average = 0;
    s.min = n > 0 ? arr[0] : 0;
    s.max = n > 0 ? arr[0] : 0;
    for (int i = 0; i < n; ++i) {
        s.sales[i] = arr[i];
        if (arr[i] > s.max) {
            s.max = arr[i];
        }
        if (arr[i] < s.min) {
            s.min = arr[i];
        }
        s.average += arr[i];
    }
    s.average /= n;
    if (n < QUARTERS) {
        for (int i = n; i < QUARTERS; ++i) {
            s.sales[i] = 0;
        }
    }
}

void SALE::setSales(SALE::Sales & s)
{
    Sales buffer;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Enter your sales in " << i+1 << " quarter:" << std::endl;
        std::cin >> buffer.sales[i];
    }
    setSales(s,buffer.sales,4);
}

void SALE::showSales(const SALE::Sales & s)
{
    for (int i = 0; i < 4; ++i) {
        std::cout << "Sale #" << i+1 << ":" << s.sales[i] << std::endl;
    }
    std::cout << "Max: " << s.max << std::endl;
    std::cout << "Min: " << s.min << std::endl;
    std::cout << "Average " << s.average << std::endl;
}
