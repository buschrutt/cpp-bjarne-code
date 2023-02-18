#include <iostream>
#include "arithmetic_type.h"

namespace chapter_3::arithmetic {

    complex operator+(complex a, complex b) { return a += b; }

    complex operator-(complex a, complex b) { return a -= b; }

    complex operator-(complex a) { return {-a.real(), -a.imag()}; } // unary minus

    complex operator*(complex a, complex b) { return a *= b; }

    complex operator/(complex a, complex b) { return a /= b; }

    complex& operator*(double a, complex b)
    {
        b.imag(a * b.imag());
        b.real(a *b.real());
        return b;
    }

    bool operator==(complex a, complex b) // equal
    {
        return a.real()==b.real() && a.imag()==b.imag();
    }

    bool operator!=(complex a, complex b) // not equal
    {
        return !(a==b);
    }

    complex& complex::operator*=(complex z) {
        auto real = (this->re * z.re - this->im * z.im);
        auto imag = (this->im * z.re + this->re * z.im);
        this->re = real;
        this->im = imag;
        return *this;
    }

    complex& complex::operator/=(complex z) {
        auto real = (this->re * z.re + this->im * z.im) / (z.re * z.re + z.im * z.im);
        auto image = (this->im * z.re + this->re * z.im) / (z.re * z.re + z.im * z.im);
        this->re = real;
        this->im = image;
        return *this;
    }

    complex& operator/(double a, complex b) {
        double real = 0;
        double imag = 0;
        if (a == 1)
        {
            real = b.real() / (b.real() * b.real() + b.imag() * b.imag());
            imag = - b.imag() / (b.real() * b.real() + b.imag() * b.imag());
        }
        b.real(real);
        b.imag(imag);
        return b;
    }

    void f(complex z)
    {
        complex a {2.3}; // construct {2.3,0.0} from 2.3
        complex b {1 / a}; // re=0.43478 im=0i
        complex c {a + z * complex{1,2.3}}; // a + re=-1.29999, im=4.3i
        // ...
        if (c != b)
            c = -(b / a) + 2 * b; // -0.18903+0i + 0.86956+0i = c.real = 0.680529; c.imag =
        std::cout << "func result: c.real = " << c.real() << "; c.imag = " << c.imag() << std::endl;
    }

    void ChapterThree_Complex()
    {
        complex z {1.0, 2.0};
        std::cout <<"\nchapter_3::arithmetic::ChapterThree_Complex() --pg.61:\n";
        f(z);
    }


} // namespace chapter_3::arithmetic
