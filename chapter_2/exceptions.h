#pragma once

#ifndef CPP_BJARNE_CODE_EXCEPTIONS_H
#define CPP_BJARNE_CODE_EXCEPTIONS_H

#include <stdexcept>
#include <iostream>

namespace chapter_2::exceptions {

    /// Begin Of %%%%%%%%%% user class Vector definition
    class Vector {
    public:
        explicit Vector(int s); // see definition of the constructor in cpp

        double& operator[](int i); // definition of subscripting in cpp

        [[nodiscard]] int size() const; // see definition of size()

    private:
        double* elem; // elem points to an array of sz doubles

        int sz;
    };
    /// End Of ^^^ user class Vector definition

    void f(Vector& v);

    void ChapterTwo_Exceptions();


} // chapter_2::exceptions

#endif //CPP_BJARNE_CODE_EXCEPTIONS_H