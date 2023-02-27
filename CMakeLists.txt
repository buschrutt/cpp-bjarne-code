cmake_minimum_required(VERSION 3.22)
project(cpp-bjarne-code)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-bjarne-code main.cpp
        chapter_2/chapter_2.cpp chapter_2/exceptions.cpp chapter_2/invariants.cpp #chapter_2

        chapter_3/chapter_3.h
        chapter_3/arithmetic_type.cpp
        chapter_3/container.cpp
        chapter_3/abstract.cpp
        chapter_3/hierarchies.cpp
        chapter_3/copying.cpp
        chapter_3/templates.cpp
        )