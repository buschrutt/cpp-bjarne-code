#ifndef CPP_BJARNE_CODE_CONTAINER_H
#define CPP_BJARNE_CODE_CONTAINER_H

#include <stdexcept>
#include <iostream>
#include <utility>

namespace chapter_3::container {

    class Vector {
    private:
        double* elem; // elem points to an array of sz doubles
        int sz;
        std::string name_;

    public:
        explicit Vector(int s, std::string name) :elem{new double[s]}, sz{s}, name_{std::move(name)} // constructor: acquire resources
        {
            std::cout << "class: " << name_ << " is created here\n";
            for (int i=0; i!=s; ++i) elem[i]=0; // initialize elements
        }

        ~Vector()
        {
            std::cout << "class: " << name_ << " is destroyed here\n";
            delete[] elem;
        } // destructor: release resources

        double& operator[](int i);

        [[nodiscard]] int size() const;
    };

    void fct(int n);

    void ChapterThree_Container();

} // chapter3::container

#endif //CPP_BJARNE_CODE_CONTAINER_H
