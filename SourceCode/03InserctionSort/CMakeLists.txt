cmake_minimum_required(VERSION 3.13)
project(03InserctionSort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(03InserctionSort
        CMakeLists.txt
        InsertionSort.h
        InsertionSort_Advanced.h
        main.cpp
        SelectionSort.h
        student.h
        TestHelper.h
        ShellSort.h)
