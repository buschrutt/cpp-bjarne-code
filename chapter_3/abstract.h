#ifndef CPP_BJARNE_CODE_ABSTRACT_H
#define CPP_BJARNE_CODE_ABSTRACT_H

#include <iostream>
#include <vector>
#include <list>

namespace chapter_3::abstract {

    class Vector {
        double* elem; // elem points to an array of sz doubles
        int sz;
    public:
        explicit Vector(int size);

        Vector(std::initializer_list<double>); // initialize with a list
        // ...
        void push_back(double); // add element at end increasing the size by one
        // ...
        double& operator[](int i);

        [[nodiscard]] int size() const;
    };

    Vector read(std::istream& is);

    void ChapterThree_Initialization();


    /// abstract class here
    class Container {
    public:
        virtual double& operator[](int) = 0; // pure virtual function

        [[nodiscard]] virtual int size() const = 0; // const member function (§3.2.1.1)

        virtual ~Container() = default; // destructor (§3.2.1.2)
    };

    /// use func -- passing Vector_container
    void use(Container& c);

    /// Vector_container class
    class Vector_container : public Container { // Vector_container implements Container
        Vector v;

    public:
        explicit Vector_container(int s) : v(s) { } // Vector of s elements

        ~Vector_container() override = default;

        double& operator[](int i) override { return v[i]; }

        [[nodiscard]] int size() const override { return v.size(); }
    };

    void ChapterThree_Abstract();

    /// abstract2 class List_container
    class List_container : public Container { // List_container implements Container
        std::list<double> ld; // (standard-library) list of doubles (§4.4.2)

    public:
        List_container() = default; // empty List

        List_container(std::initializer_list<double> il) : ld{il} {}

        ~List_container() override = default;

        double& operator[] (int i) override;

        [[nodiscard]] int size() const override { return ld.size(); }
    };

    void h();

    void ChapterThree_Abstract2();

} // chapter_3::abstract

#endif //CPP_BJARNE_CODE_ABSTRACT_H