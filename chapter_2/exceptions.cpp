#include "exceptions.h"

namespace chapter_2::exceptions {

    /// Begin Of %%%%%%%%%% user class Vector
    Vector::Vector(int s) // definition of the constructor
            :elem{new double[s]}, sz{s} // initialize members
    {
    }

    double& Vector::operator[](int i)
    {
        if (i<0 || size()<=i) throw std::out_of_range{"Vector::operator[]"};
        return elem[i];
    }

    int Vector::size() const // definition of size()
    {
        return sz;
    }
    /// End Of ^^^ user class Vector

    void f(Vector& v)
    {
        // ...
        try { // exceptions here are handled by the handler defined below
            v[v.size()] = 7; // try to access beyond the end of v
        }
        catch (std::out_of_range&) { // oops: out_of_range error
            // ... handle range error ...
            std::cout << "oops: out_of_range error --IT SHOULD BE\n";
        }
        // ...
    }

    void ChapterTwo_Exceptions()
    {
        std::cout <<"\nchapter_2::exceptions::ChapterTwo_Exceptions() --pg.55:\n";
        Vector v(1);
        f(v);
    }

} // chapter_2::exceptions