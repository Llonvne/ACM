cmake_minimum_required(VERSION 3.22)
project(heap)

set(CMAKE_CXX_STANDARD 14)

add_executable(heap main.cpp heap/HeapOperations.h heap/MaxHeap.cpp heap/MaxHeap.h heap/BuildMaxHeap.cpp heap/BuildMaxHeap.h heap/MaxHeapIteration.cpp heap/MaxHeapIteration.h heap/HeapSort.cpp heap/HeapSort.h heap/MaxPriorityQueue.cpp heap/MaxPriorityQueue.h)
