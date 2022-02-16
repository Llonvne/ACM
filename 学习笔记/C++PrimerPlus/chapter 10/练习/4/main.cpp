#include <iostream>
#include "Sales.h"

int main()
{
    using SALES::Sales;
    double sales_data[] = {1.22, 1.32, 1.34, 12.1};
    Sales s(sales_data);
    s.display();

    Sales g;
    g.display();
    Sales::setSales(g);
    g.display();
}
