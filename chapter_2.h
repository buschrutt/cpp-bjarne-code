#pragma once
#ifndef CPP_BJARNE_CODE_CHAPTER_2_H
#define CPP_BJARNE_CODE_CHAPTER_2_H

namespace chapter_2 {

    class chapter_2 {

    };

    double square(double x);

    bool accept2();

    bool accept3();

    void copy_print_increment_fct();

    int count_x(char* p, char x);

    /// pg.62 - pg.64 We can define a variable of our new type Vector --struct
    struct VectorStruct {
        int sz; // number of elements
        double* elem; // pointer to elements
    };
    /// pg.62 - pg.64 Vector initialization
    void vector_init(VectorStruct& v, int s);
    /// pg.62 - pg.64 Func that uses initialized Vector
    double read_and_sum(int s);

    /// pg.64 Vector with constructor
    class VectorClass {
    public:
        explicit VectorClass(int s) :elem{new double[s]}, sz{s} { } // construct a Vector
        double& operator[](int i) { return elem[i]; } // element access: subscripting
        int size() { return sz; }
    private:
        double* elem; // pointer to the elements
        int sz; // the number of elements
    };
    double read_and_sum_2(int s);

    /// pg.65 - pg.66 Enumerations
    enum class Traffic_light { green, yellow, red };
    Traffic_light& operator++(Traffic_light& t);
    /// Function created for example
    void TrafficLightChange();


    /// pg.67 Class Vector definition and example of use
    double sqrt(double); // the square root function takes a double and returns a double
    class Vector {
    public:
        explicit Vector(int s); // see definition of the constructor in cpp
        double& operator[](int i); // definition of subscripting in cpp
        int size(); // see definition of size()
    private:
        double* elem; // elem points to an array of sz doubles
        int sz;
    };
    /// Function created for example
    void SampleOfVectorUse();
    /// Example of use from the book
    double sqrt_sum(Vector& v);

    /// pg.69 Namespaces
    namespace My_code {
        class complex {};
        complex sqrt(complex);
        // ...
        int main();
    }


}

void RunChapterTwo();

#endif //CPP_BJARNE_CODE_CHAPTER_2_H

