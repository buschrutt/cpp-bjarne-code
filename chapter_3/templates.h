#ifndef CPP_BJARNE_CODE_TEMPLATES_H
#define CPP_BJARNE_CODE_TEMPLATES_H

#include <stdexcept>
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <complex>
#include <memory>
#include "hierarchies.h"


namespace chapter_3::templates
{

    /// Parameterized Types
    template<typename T>
    class Vector {
    private:
        T* elem; // elem points to an array of sz elements of type T
        int sz;

    public:
        explicit Vector(int s); // constructor: establish invariant, acquire resources

        ~Vector() { delete[] elem; } // destructor: release resources

        // ... copy and move operations ...
        T& operator[](int i);

        const T& operator[](int i) const;

        [[nodiscard]] int size() const { return sz; }

        T* begin()
        {
            return &elem[0]; // pointer to first element
        }

        T* end()
        {
            return &elem[sz]; // pointer to first element
        }

        T* begin() const
        {
            return &elem[0]; // pointer to first element
        }

        T* end() const
        {
            return &elem[sz]; // pointer to first element
        }

    };

    template<typename T>
    Vector<T>::Vector(int s)
    {
        if (s < 0) throw std::out_of_range{"Negative_size{}"};
        elem = new T[s];
        sz = s;
    }

    template<typename T>
    const T& Vector<T>::operator[](int i) const
    {
        if (i < 0 || size() <= i)
            throw std::out_of_range{"Vector::operator[]"};
        return elem[i];
    }

    template<typename T>
    T &Vector<T>::operator[](int i) {
        if (i < 0 || size() <= i)
            throw std::out_of_range{"Vector::operator[]"};
        return elem[i];
    }

    void write(const Vector<std::string>& vs);

    void f2(const Vector<std::string>& vs);

    void ChapterThree_TemplateVector();


    /// Function Templates

    template<typename Container, typename Value>
    Value sum(const Container& c, Value v)
    {
        for (auto x : c)
            v += x;
        return v;
    }

    void user(Vector<int>& vi, std::list<double>& ld, std::vector<std::complex<double>>& vc);

    void ChapterThree_FunctionTemplates();


    /// Function Objects

    template<typename T>
    class Less_than {
        const T val; // value to compare against
    public:
        explicit Less_than(T  v) :val(std::move(v)) { }
        bool operator()(const T& x) const { return x<val; } // call operator
    };

    void fct(int n, const std::string & s);

    template<typename C, typename P>
    int count(const C& c, P pred)
    {
        int cnt = 0;
        for (const auto& x : c)
            if (pred(x))
                ++cnt;
        return cnt;
    }

    void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s);

    void f2(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s);

    void DrawSvgUptr(std::unique_ptr<chapter_3::hierarchies::Shape>&& shape);

    template<class C, class Oper>
    void for_all(C& c, Oper op) // assume that C is a container of pointers
    {
        for (auto& x : c)
            op(std::move(x)); //pass op() a reference to each element pointed to
    }

    void user();

    void ChapterThree_FunctionObjects();

    /// Variadic Templates

    template<typename T, typename ... Tail>
    void f_variadic(T head, Tail... tail)
    {
        g(head); // do something to head
        f_variadic(tail...); // try again with tail
    }

    void f_variadic(); // do nothing

    template<typename T>
    void g(T x)
    {
        std::cout << x << " ";
    }

    int main_f();

    void ChapterThree_TemplateVariadic();

} // templates

#endif //CPP_BJARNE_CODE_TEMPLATES_H
