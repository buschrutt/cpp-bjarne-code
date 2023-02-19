#include "invariants.h"

namespace chapter_2::invariants {

    Vector::Vector(int s)
    {
        if (s<0) throw std::length_error{"length_error thrown"};
        elem = new double[s];
        sz = s;
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

    void test()
    {
        try {
            Vector v(-27);
        }
        catch (std::length_error&) {
            // handle negative size
            std::cout <<"error: negative size --IT SHOULD BE\n";
            return;
        }
        catch (std::bad_alloc&) {
            // handle memory exhaustion
            std::cout <<"error: handle memory exhaustion --\n";
            return;
        }
        std::cout <<"-- no error was thrown\n";
    }

    void ChapterTwo_Invariants()
    {
        std::cout <<"\nchapter_2::invariants::ChapterTwo_Invariants() --pg.56:\n";
        test();
    }

}