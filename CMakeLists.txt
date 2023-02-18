cmake_minimum_required(VERSION 3.22)
project(cpp-bjarne-code)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-bjarne-code main.cpp

        chapter_2/chapter_2.cpp chapter_2/chapter_2.h
        chapter_2/exceptions.cpp chapter_2/exceptions.h
        chapter_2/invariants.cpp chapter_2/invariants.h)