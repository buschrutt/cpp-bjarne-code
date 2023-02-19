#include <sstream>
#include "abstract.h"

namespace chapter_3::abstract {

    Vector::Vector(int size) // initialize with a list
            : elem{new double[size]}, sz{size}
    {
        std::vector<double> lst;
        for (int i = 1; i <= size; ++i)
            lst.push_back(i);
        std::copy(lst.begin(), lst.end(), elem); // copy from lst into elem
    }

    Vector::Vector(std::initializer_list<double> lst) // initialize with a list
            : elem{new double[lst.size()]}, sz{int(lst.size())}
    {
        std::copy(lst.begin(), lst.end(), elem); // copy from lst into elem
    }

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

    void Vector::push_back(double d)
    {
        std::vector<double> e;
        for (int i = 0; i < sz; ++i)
            e.push_back(elem[i]);
        e.push_back(d);
        delete[] elem;
        sz += 1;
        elem = new double[sz];
        std::copy(e.begin(), e.end(), elem);
    }

    Vector read(std::istream& is)
    {
        Vector v{1, 2, 3};
        for (double d; is>>d;) // read floating-point values into d
            v.push_back(d); // add d to v
        return v;
    }

    void ChapterThree_Initialization()
    {
        std::cout <<"\nchapter_3::abstract::ChapterThree_Initialization() --pg.64:\n";
        std::istringstream is("4 5");
        auto v = read(is);
        double sum = 0.0;
        for (int i = 0; i < v.size(); ++i)
            sum += v[i];
        std::cout << "v vector sum --must be 15-- : "<< sum << '\n';
    }

    void use(Container& c)
    {
        double sum = 0.0;
        for (int i = 0; i < c.size(); ++i)
            sum += c[i];
        std::cout << "c container sum --must be 10-- : "<< sum << '\n';
    }

    void ChapterThree_Abstract()
    {
        std::cout <<"\nchapter_3::abstract::ChapterThree_Abstract() --pg.65:\n";
        Vector_container v(4);
        use(v);
    }

    double& List_container::operator[](int i)
    {
        for (auto& x : ld) {
            if (i==0) return x;
            --i;
        }
        throw std::out_of_range("List container");
    }

    void h()
    {
        List_container lc = {1, 2, 3, 4};
        use(lc);
    }

    void ChapterThree_Abstract2()
    {
        std::cout <<"\nchapter_3::abstract::ChapterThree_Abstract() --pg.66:\n";
        h();
    }

} // abstract