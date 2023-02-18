#include <iostream>
#include <complex>
#include "chapter_2.h"

/// ^^_^^ nice
/// Runs all chapter code
namespace chapter_2 {

    /// Begin of %%%%%%%%%% RunChapter funcs
    void RunChapterTwo_Square()
    {
        /// pg.55 chapter_2 square(2.0)
        std::cout <<"\nchapter_2::RunChapterTwoSquare() --pg.55:\n";
        std::cout << "pg.54 pg.54 pg.55  chapter_2::square(2.0) func returns: ";
        std::cout << chapter_2::square(2.0) << '\n' << std::endl;
    }

    void RunChapterTwo_Accept2()
    {
        /// pg.59 bool accept2()
        std::cout <<"\nchapter_2::RunChapterTwoAccept2() --pg.59:\n";
        chapter_2::accept2();
    }

    void RunChapterTwo_Accept3()
    {
        /// pg.59 bool accept3()
        std::cout <<"\nchapter_2::RunChapterTwoAccept3() --pg.59:\n";
        chapter_2::accept3();
    }

    void RunChapterTwo_CopyPrintIncrement()
    {
        /// pg.60 - pg.61 Three funcs combined: copy_fct, increment, print
        std::cout <<"\nchapter_2::RunChapterTwoCopyPrintIncrement() --pg.59:\n";
        chapter_2::copy_print_increment_fct();
    }

    void RunChapterTwo_CountX()
    {
        /// pg.61 count_x Counts char entries &--check that a pointer argument that is
        /// pg.61 chapter_2::count_x Check that a pointer argument that is supposed to point to something --must be 3
        /// supposed to point to something
        std::cout <<"\nchapter_2::RunChapterTwoCountX() --must be 3 --pg.61:\n";
        std::string alibaba = "alibaba";
        auto p = &alibaba[0];
        std::cout << chapter_2::count_x(p, 'a') << '\n';
    }

    void RunChapterTwo_UserType()
    {
        /// pg.62 - pg.64 User-defined type --struct Vector initialization
        /// For struct declaration please see the .h file
        /// Func that uses initialized Vector, calculates sum of entered 5 int numbers
        std::cout <<"\nchapter_2::RunChapterTwoUserType() --must entered 5 int numbers --pg.62-pg.64:\n";
        auto sum = chapter_2::read_and_sum(5);
        std::cout << "sum: " << sum << '\n';
    }

    void RunChapterTwo_MakeAndVector()
    {
        /// pg.64 Make a vector of s elements, read into elements, gets sum
        std::cout <<"\nchapter_2::RunChapterTwoMakeAndVector() --must entered 5 int numbers --pg.64:\n";
        auto sum = chapter_2::read_and_sum_2(5);
        std::cout << "sum: " << sum << '\n';
    }

    void RunChapterTwo_Enumerations()
    {
        /// pg.65 - pg.66 Enumerations
        std::cout <<"\nchapter_2::RunChapterTwoEnumerations() --pg.64:\n";
        chapter_2::TrafficLightChange();
    }

    void RunChapterTwo_VectorDefinition()
    {
        /// %%%%%%%%%% pg.67 Class Vector definition and example of use %%%%%%%%%%
        /// Example of use, initialization with 3 elems & Assignment 1, 2, 3
        /// & Printing the values and size()
        std::cout <<"\nchapter_2::RunChapterTwoVectorDefinition() --pg.67:\n";
        chapter_2::SampleOfVectorUse();
        /// Example of use from the book
        auto v = chapter_2::Vector(3);
        std::cout << "sqrt_sum(chapter_2::Vector) = " << chapter_2::sqrt_sum(v) << '\n';
    }

    void RunChapterTwo_Namespaces()
    {
        /// pg.69 Namespaces
        std::cout <<"\nchapter_2::RunChapterTwoVectorDefinition() --pg.69:\n";
        chapter_2::My_code::main();
    }
    /// ^^^ End of RunChapter funcs


    /// pg.54: square func -- a double precision floating-point number
    double square(double x)
    {
        return x * x;
    }


    /// pg.59: accept2 func
    bool accept2()
    {
        std::cout << "Do you want to proceed (y or n)?\n"; /// write question
        char answer = 0;
        std::cin >> answer; /// read answer
        /// *p.58 code accept() silenced*
        //if (answer == 'y') return true;
        //return false;
        /// ^^^ *p.58 code silenced*
        switch (answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                std::cout << "I'll take that for a no.\n";
                return false;
        }
    }


    /// pg.59: accept3 func
    bool accept3()
    {
        int tries = 1;
        while (tries<4) {
            std::cout << "Do you want to proceed (y or n)?\n"; /// write question
            char answer = 0;
            std::cin >> answer; /// read answer
            switch (answer) {
                case 'y':
                    return true;
                case 'n':
                    return false;
                default:
                    std::cout << "Sorry, I don't understand that.\n";
                    ++tries; /// increment
            }
        }
        std::cout << "I'll take that for a no.\n";
        return false;
    }


    /// pg.60 copy_fct: copying ten elements from one array to another
    /// pg.61 increment: increment within loop by reference
    /// pg.60 print: simpler for-statement, called a range-for-statement
    /// Three funcs combined
    void copy_print_increment_fct()
    {
        int v1[10] = {0,1,2,3,4,5,6,7,8,9};
        int v2[10]; // to become a copy of v1
        for (auto i=0; i!=10; ++i) // copy elements
            v2[i]=v1[i];
        for (auto& x : v2)
            ++x;
        for (auto x : v2) // for each x in v
            std::cout << x << '\n';
        for (auto x : {10,21,32,43,54,65})
            std::cout << x << '\n';
        // ...
    }


    int count_x(char* p, char x)
    // count the number of occurrences of x in p[]
    // p is assumed to point to a zero-ter minated array of char (or to nothing)
    {
        if (p==nullptr) return 0;
        int count = 0;
        for (; *p!=0; ++p)
            if (*p==x)
                ++count;
        return count;
    }


    /// pg.62 - pg.64 User-defined type --struct Vector initialization
    /// For struct declaration please see the .h file
    void vector_init(VectorStruct& v, int s)
    {
        v.elem = new double[s]; // allocate an array of s doubles
        v.sz = s;
    }
    /// pg.62 - pg.64 Func that uses initialized Vector
    double read_and_sum(int s)
    // read s integers from cin and return their sum; s is assumed to be positive
    {
        VectorStruct v{};
        vector_init(v,s); //allocate s elements for v
        for (int i=0; i!=s; ++i)
            std::cin>>v.elem[i]; // read into elements
        double sum = 0;
        for (int i=0; i!=s; ++i)
            sum+=v.elem[i]; // take the sum of the elements
        return sum;
    }


    /// pg.64 Make a vector of s elements, read into elements, gets sum
    double read_and_sum_2(int s)
    {
        VectorClass v(s); // make a vector of s elements
        for (int i=0; i!=v.size(); ++i)
            std::cin>>v[i]; //read into elements
        double sum = 0;
        for (int i=0; i!=v.size(); ++i)
            sum+=v[i]; //take the sum of the elements
        return sum;
    }


    /// pg.65 - pg.66 Enumerations
    Traffic_light& operator++(Traffic_light& t)
    // prefix increment: ++
    {
        switch (t) {
            case Traffic_light::green: return t=Traffic_light::yellow;
            case Traffic_light::yellow: return t=Traffic_light::red;
        }
        return t=Traffic_light::green;
    }
    /// Function created for example
    void TrafficLightChange()
    {
        Traffic_light current_light = Traffic_light::red;
        for (int i = 0; i < 3; ++i) {
            ++current_light;
            if (current_light == Traffic_light::red)
                std::cout << "Red\n";
            if (current_light == Traffic_light::yellow)
                std::cout << "Yellow\n";
            if (current_light == Traffic_light::green)
                std::cout << "Green\n";
        }
    }


    /// %%%%%%%%%% pg.67 Class Vector definition and example of use %%%%%%%%%%
    Vector::Vector(int s) // definition of the constructor
            :elem{new double[s]}, sz{s} // initialize members
    {
    }
    double& Vector::operator[](int i) // definition of subscripting
    {
        return elem[i];
    }
    int Vector::size() // definition of size()
    {
        return sz;
    }
    /// Example of use, initialization with 3 elems & Assignment 1, 2, 3
    /// & Printing the values and size()
    void SampleOfVectorUse()
    {
        auto v = Vector(3);
        v[0] = 2;
        v[1] = 4;
        v[2] = 6;
        for (int i = 0; i < 3; ++i)
            std::cout << "v[" << i << "] = " << v[i] << '\n';
        std::cout << "size-- " << v.size() << '\n';
    }
    /// Example of use from the book
    double sqrt_sum(Vector& v)
    {
        v[0] = 1;
        v[1] = 4;
        v[2] = 9;
        double sum = 0;
        for (int i = 0; i != v.size(); ++i)
            sum += std::sqrt(v[i]); // sum of square roots
        return sum;
    }


    /// pg.69 Namespaces
    int My_code::main()
    {
        std::complex<double> z {1, 2};
        auto z2 = std::sqrt(z);
        std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
        // ...
        return 0;
    }

} // namespace chapter_2
