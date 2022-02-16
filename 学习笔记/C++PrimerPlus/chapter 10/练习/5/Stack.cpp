//
// Created by 华邵钶 on 2022/2/16.
//

#include "Stack.h"

template<typename Item>
Stack<Item>::Stack()
{
    _top = 0;
}

template<typename Item>
void Stack<Item>::push(const Item & item)
{
    if (full()) {
        return;
    }
    _data[_top++] = item;
}

template<typename Item>
bool Stack<Item>::pop()
{
    if (empty()) {
        return false;
    }
    --_top;
    return true;
}

template<typename Item>
const Item & Stack<Item>::top() const
{
    if (empty()) {
        return {"Stack is empty."};
    }
    return _data[_top - 1];
}

template<typename Item>
bool Stack<Item>::full() const
{
    return _top == _data.size() - 1;
}

template<typename Item>
bool Stack<Item>::empty() const
{
    return _top == 0;
}
