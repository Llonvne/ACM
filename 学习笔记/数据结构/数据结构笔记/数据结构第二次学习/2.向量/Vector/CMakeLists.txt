cmake_minimum_required(VERSION 3.21)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector main.cpp Vector.h Dynamic_Operations/Vector_Dynamic_Capacity_Adjustment.h Dynamic_Operations/Vector_Constructors_Destructor.h For_Debug/Vector_Debug_Only.h Static_Operations/Vector_Static_Operations.h Dynamic_Operations/Vector_Dynamic_Operations.h Vector_Includes.h Error/SimpleError.cpp Error/SimpleError.h Search/Vector_Fib_Binary_Search.h Search/Vector_Search_Interface.h Search/Vector_Interpolation_Search.h)
