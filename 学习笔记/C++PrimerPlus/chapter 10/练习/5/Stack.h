//
// Created by 华邵钶 on 2022/2/16.
//

#ifndef STACK_H
#define STACK_H
#include <array>
template <typename Item>
class Stack
{
    enum class STACK_SIZE:unsigned int {SIZE = 10000};
    std::array<Item,(int)STACK_SIZE::SIZE> _data;
    int _top;
public:
    Stack();
    void push(const Item& item);
    bool pop();
    const Item & top() const;
    bool full() const;
    bool empty() const;
};
#endif //STACK_H
