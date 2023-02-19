#include "container.h"

namespace chapter_3::container {

    /// addition
    double &Vector::operator[](int i) {
        {
            if (i<0 || size()<=i) throw std::out_of_range{"Vector::operator[]"};
            return elem[i];
        }
    }

    /// addition
    int Vector::size() const {
        return sz;
    }

    void fct(int n)
    {
        Vector v(n, "v");
        std::cout << "class has size of: " << v.size() << '\n';
        // ... use v ...
        {
            Vector v2(2 * n, "v2");
            std::cout << "class has size of: " << v2.size() << '\n';
            // ... use v and v2 ...
        } // v2 is destroyed here
        // ... use v ..
    } // v is destroyed here

    void ChapterThree_Container()
    {
        std::cout <<"\nchapter_3::container::ChapterThree_Container() --pg.63:\n";
        fct(5);
    }


} // chapter3::container