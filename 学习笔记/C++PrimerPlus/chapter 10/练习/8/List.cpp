//
// Created by 华邵钶 on 2022/2/16.
//

#include "List.h"

template<typename T>
void List<T>::push_back(const T & e)
{
    if (!fulfill()){
        m_elem[m_size++] = e;
    }
}

template<typename T>
bool List<T>::empty() const
{
    return m_size == 0;
}

template<typename T>
bool List<T>::fulfill() const
{
    return m_size == (int)LIST_C::SIZE - 1;
}

template<typename T>
void List<T>::visit(void (* pf)(T &))
{
    for (int i = 0; i < m_size; ++i) {
        pf(m_elem[i]);
    }
}

template<typename T>
int List<T>::size() const
{
    return m_size;
}

template<typename T>
List<T>::List()
{
    m_size = 0;
}
