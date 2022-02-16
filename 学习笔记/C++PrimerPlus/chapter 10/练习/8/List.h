//
// Created by 华邵钶 on 2022/2/16.
//

#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
    enum class LIST_C{SIZE = 100000};
    T m_elem[(int)LIST_C::SIZE];
    int m_size = 0;
public:
    List();
    void push_back(const T&);
    bool empty() const;
    bool fulfill() const;
    void visit(void (*pf)(T &));
    int size() const;
};


#endif //LIST_H
