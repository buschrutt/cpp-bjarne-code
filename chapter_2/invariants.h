#pragma once

#ifndef CPP_BJARNE_CODE_INVARIANTS_H
#define CPP_BJARNE_CODE_INVARIANTS_H

#include <new>
#include <stdexcept>
#include <iostream>

namespace chapter_2::invariants {

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

    void test();

    void ChapterTwoInvariants();

} // chapter_2::invariants





#endif //CPP_BJARNE_CODE_INVARIANTS_H
