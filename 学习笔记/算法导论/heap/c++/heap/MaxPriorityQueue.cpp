//
// Created by 华邵钶 on 2022/5/23.
//

#include "MaxPriorityQueue.h"
#include "MaxHeapIteration.h"
#include "BuildMaxHeap.h"
#include "HeapOperations.h"
#include <memory>
#include <vector>
using std::vector;

MaxPriorityQueue::MaxPriorityQueue(int elem[], int n)
{
    this->elem = std::make_unique<vector<int> >(elem, elem + n);
    build_max_heap(this->elem->data(), (int) this->elem->size());
}

MaxPriorityQueue::MaxPriorityQueue(vector<int> a)
{
    this->elem = std::make_unique<vector<int> >(a.begin(), a.end());
    build_max_heap(this->elem->data(), (int) this->elem->size());
}

int MaxPriorityQueue::top()
{
    return this->elem->at(0);
}

int MaxPriorityQueue::pop()
{
    int top = this->top();
    this->elem->operator[](0) = this->elem->operator[](
        this->elem->size() - 1);
    this->elem->pop_back();
    max_heapify_iteration(this->elem->data(), this->elem->size(), 0);
    return top;
}

int MaxPriorityQueue::size()
{
    return this->elem->size();
}

int MaxPriorityQueue::push(int x)
{
    this->elem->push_back(x);
    int i = this->elem->size() - 1;
    while (i >= 1 && this->elem->at(i) > this->elem->at(root(i))){
        std::swap(this->elem->operator[](i),this->elem->operator[](root(i)));
        i = root(i);
    }
}

