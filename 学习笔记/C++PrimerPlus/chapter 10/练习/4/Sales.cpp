//
// Created by 华邵钶 on 2022/2/15.
//

#include "Sales.h"
#include <iostream>
#include <limits>

SALES::Sales::Sales(const double * sourceQuarterSales)
{
    for (int quarter = 0; quarter < (int) QUARTERS::quarters; ++quarter) {
        sales[quarter] = sourceQuarterSales[quarter];
    }
}

void SALES::Sales::display() const
{
    std::cout << "Your " << (int) QUARTERS::quarters << " quarters sales report:" << std::endl;
    for (int quarter = 0; quarter < (int) QUARTERS::quarters; ++quarter) {
        printf("#%d: %f\n",quarter,sales[quarter]);
    }
    std::cout << "Max sales: " << max() << std::endl;
    std::cout << "Min sales: " << min() << std::endl;
    std::cout << "Average sales: " << average() << std::endl;
}

void SALES::Sales::setSales(SALES::Sales & s)
{
    std::cout << "Enter your " << (int)QUARTERS::quarters << " sales" << std::endl;
    int no = 1;
    for (double & sale : s.sales) {
        printf("#%d:",no++);
        std::cin >> sale;
        while (!std::cin) {
            std::cin.clear();
            while (std::cin.get() != '\n') {};
            std::cin >> sale;
        }
    }
    std::cout << "Done!" << std::endl;
}

SALES::Sales::Sales()
{
    for (double & sale : sales) {
        sale = 0.0;
    }
}

double SALES::Sales::max() const
{
    return *std::max_element(sales,sales + (int)QUARTERS::quarters);
}

double SALES::Sales::min() const
{
    return *std::min_element(sales,sales + (int)QUARTERS::quarters);
}

double SALES::Sales::average() const
{
    double sum = 0;
    for (const double i : sales){
        sum += i;
    }
    return sum / (int)QUARTERS::quarters;
}
