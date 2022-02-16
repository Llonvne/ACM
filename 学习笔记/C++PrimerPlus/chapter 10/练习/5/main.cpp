#include "customer.h"
#include "Stack.h"
#include <iostream>

int main()
{
    Stack<customer> cus;
    cus.push({"Llonvne",100});
    cus.push({"Lcosvle",109});
    double total = 0;
    while (!cus.empty()){
        total += cus.top().payment;
        std::cout << "customer: " << cus.top().fullname << " ";
        std::cout << "payment:" << cus.top().payment << std::endl;
        std::cout << "Total:" << total << std::endl;
        cus.pop();
    }
    return 0;
}
