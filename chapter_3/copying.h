#ifndef CPP_BJARNE_CODE_COPYING_H
#define CPP_BJARNE_CODE_COPYING_H

#include <iostream>
#include <vector>
#include <thread>

namespace chapter_3::copying
{

    class Vector {
    private:
        double* elem; // elem points to an array of sz doubles
        int sz;

    public:
        explicit Vector(int s): elem{new double[s]}, sz{s} { } // constructor: establish invariant, acquire resources

        ~Vector() { delete[] elem; } // destructor: release resources

        Vector(const Vector& a); // copy constructor

        Vector(Vector&& a) noexcept ; // move constructor

        Vector& operator=(const Vector& a); // copy assignment

        Vector& operator=(Vector&& a) noexcept ; // move assignment

        double& operator[](int i) { return elem[i]; };

        const double& operator[](int i) const { return elem[i]; };

        [[nodiscard]] int size() const  { return sz; };
    };

    void ChapterThree_CopyingContainers();

    void ChapterThree_MovingContainers();

    void heartbeat();

    Vector init(int n);

    void ChapterThree_Thread();

} // chapter_3::copying

#endif //CPP_BJARNE_CODE_COPYING_H
