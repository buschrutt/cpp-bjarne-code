#pragma once

#ifndef CPP_BJARNE_CODE_ARITHMETIC_TYPE_H
#define CPP_BJARNE_CODE_ARITHMETIC_TYPE_H


namespace chapter_3::arithmetic {

    class complex {
        double re, im; // representation: two doubles

    public:
        complex(double r, double i) :re{r}, im{i} {} // construct complex from two scalars

        explicit complex(double r) :re{r}, im{0} {} // construct complex from one scalar

        complex() :re{0}, im{0} {} // default complex: {0,0}

        [[nodiscard]] double real() const { return re; }

        void real(double d) { re=d; }

        [[nodiscard]] double imag() const { return im; }

        void imag(double d) { im=d; }

        complex& operator+=(complex z) { re += z.re , im += z.im; return *this; } // add to re and im and return the result

        complex& operator-=(complex z) { re -= z.re , im -= z.im; return *this; }

        complex& operator*=(complex); // defined out-of-class somewhere

        complex& operator/=(complex); // defined out-of-class somewhere

        complex& operator*(double x) {re *= x , im -= x; return *this; };

    };

    complex operator+(complex a, complex b);

    complex operator-(complex a, complex b);

    complex operator-(complex a);

    complex operator*(complex a, complex b);

    complex operator/(complex a, complex b);

    complex& operator*(double a, complex b);

    complex& operator/(double a, complex b);

    bool operator==(complex a, complex b);

    bool operator!=(complex a, complex b);


    complex sqrt(complex);
    // ...

    void f(complex z);

    void ChapterThree_Complex();

} // namespace chapter_3::arithmetic


#endif //CPP_BJARNE_CODE_ARITHMETIC_TYPE_H
