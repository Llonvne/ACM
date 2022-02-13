

#ifndef SALE_H
#define SALE_H

namespace SALE
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    void setSales(Sales & s,double arr[],int n);
    void setSales(Sales & s);
    void showSales(const Sales & s);
}

#endif //SALE_H
