#include <fstream>
#include "templates.h"

namespace chapter_3::templates
{

    void write(const Vector<std::string>& vs) // Vector of some strings
    {
        for (const auto & v : vs)
            std::cout << v << '\n';
    }

    void f2(const Vector<std::string>& vs) // Vector of some strings
    {
        for (auto& s : vs)
            std::cout << s << '\n';
    }

    void ChapterThree_TemplateVector() {
        std::cout <<"\nchapter_3::templates::ChapterThree_TemplateVector() --pg.78:\n";
        Vector<std::string> vs(3);
        std::string str;
        for (auto & v : vs) {
            str += "X";
            v = str;
        }
        write(vs);
        f2(vs);
    }

    /// Function Templates

    void user(Vector<int>& vi, std::list<double>& ld, std::vector<std::complex<double>>& vc)
    {
        int x = sum(vi,0); // the sum of a vector of ints (add ints)
        double d = sum(vi,0.0); // the sum of a vector of ints (add doubles)
        double dd = sum(ld,0.0); // the sum of a list of doubles
        auto z = sum(vc,std::complex<double>{}); // the sum of a vector of complex<double>
        // the initial value is {0.0,0.0}
        std::cout << "x-- " << x << "; d-- " << d << "; dd-- " << dd << "; " << std::endl;
        std::cout << "z.real-- " << z.real() << "; z." << z.imag() << "; " << std::endl;
    }

    void ChapterThree_FunctionTemplates()
    {
        std::cout <<"\nchapter_3::templates::ChapterThree_FunctionTemplates() --pg.80:\n";
        Vector<int> vi(3);
        for (int i = 0; i < vi.size(); ++i)
            vi[i] = i + 1;
        std::list<double> ld{1.0, 2.0, 3.0};
        std::vector<std::complex<double>> vc{1.0, 2.0, 3.0};
        user(vi, ld, vc);
    }

    /// Function Objects

    using Lti = Less_than<int>;
    using Lts = Less_than<std::string>;

    void fct(int n, const std::string & s)
    {
        Lti lti {42}; // lti(i) will compare i to 42 using < (i<42)
        Lts lts {"Backus"}; // lts(s) will compare s to "Backus" using < (s<"Backus")
        bool b1 = lti(n); // true if n<42
        bool b2 = lts(s); // true if s<"Backus"
        if (b1)
            std::cout << "b1 == true; ";
        if (b2)
            std::cout << "b2 == true; ";
        if (!b1)
            std::cout << "b1 != true; ";
        if (!b2)
            std::cout << "b2 != true; ";
        // ...
    }

    void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
    {
        std::cout << "\nf (Less_than call):\n";
        std::cout << "number of values less than " << x
                  << ": " << count(vec,Less_than<int>{x})
                  << '\n';
        std::cout << "number of values less than " << s
                  << ": " << count(lst,Less_than<std::string>{s});
    }

    void f2(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
    {
        std::cout << "\nf2 (lambda call):\n";
        std::cout << "number of values less than " << x
                  << ": " << count(vec,[&](int a){ return a < x; })
                  << '\n';
        std::cout << "number of values less than " << s
                  << ": " << count(lst,[&](const std::string& a){ return a < s; })
                  << '\n';
    }

    void DrawSvgUptr(std::unique_ptr<chapter_3::hierarchies::Shape>&& shape)
    {
        std::string filename  = "files/smile.svg";
        std::ofstream svg_f_stream(filename);
        if (svg_f_stream.is_open())
        {
            std::cout <<"check debug/release folder for files/smile.svg for output\n";
            svg_f_stream << R"(<?xml version="1.0" encoding="UTF-8" ?>)" << "\n";
            svg_f_stream << R"(<svg xmlns="http://www.w3.org/2000/svg" version="1.1">)" << "\n";
            svg_f_stream << shape->draw() << R"(</svg>)";
        } else
        {
            std::cerr << "--No file --found"<< std::endl;
        }
    }

    void user()
    {
        std::vector<std::unique_ptr<chapter_3::hierarchies::Shape>> v;
        std::istringstream is ("0 80 80 40");
        while (is) {
            try {
                v.push_back(chapter_3::hierarchies::read_shape_uptr(is));
            } catch (...) {
                break;
            }
        }
        for_all(v,[](std::unique_ptr<chapter_3::hierarchies::Shape> s){
            DrawSvgUptr(std::move(s));
        }); // draw_all()
    }

    void ChapterThree_FunctionObjects() {
        std::cout <<"\nchapter_3::templates::ChapterThree_FunctionObjects() --pg.80:\n";
        fct(41, "Back-them");
        fct(43, "Them");
        Vector<int> vec(3);
        for (int i = 0; i < vec.size(); ++i)
            vec[i] = i + 1;
        std::list<std::string> lst{"abc", "bbc", "cbs"};
        f(vec, lst, 2, "bbc");
        f2(vec, lst, 2, "bbc");
        user();
    }

    /// Variadic Templates

    void f_variadic() {std::cout << "no-arg-left";}

    int main_f()
    {
        std::cout << "first: ";
        f_variadic(1, 2.2,"hello");
        std::cout << "\nsecond: ";
        f_variadic(0.2, 'c', "yuck!" ,0 , 1, 2);
        std::cout << "\n";
        return 0;
    }

    void ChapterThree_TemplateVariadic() {
        std::cout <<"\nchapter_3::templates::ChapterThree_TemplateVariadic() --pg.83:\n";
        main_f();
    }

} // chapter_3::templates