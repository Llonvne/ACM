cmake_minimum_required(VERSION 3.21)
project(Vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(Vector main.cpp Vector.h Vector_Dynamic_Capacity_Adjustment.h Vector_Constructors_Destructor.h Vector_Debug_Only.h Vector_Static_Operation.h Vector_Dynamic_Operations.h Vector_Includes.h)
