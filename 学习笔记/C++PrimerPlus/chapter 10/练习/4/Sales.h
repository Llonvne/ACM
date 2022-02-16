//
// Created by 华邵钶 on 2022/2/15.
//

#ifndef SALES_H
#define SALES_H

namespace SALES {
    class Sales
    {
    private:
        enum class QUARTERS : int {quarters = 4};
        double sales[(int)QUARTERS::quarters]{};
    public:
        Sales();
        double max() const;
        double min() const;
        double average() const;
        explicit Sales(const double sourceQuarterSales[]);
        void display() const;
        // 交互式输入
        static void setSales(Sales & s);
    };
}



#endif //SALES_H
