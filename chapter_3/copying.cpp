#include "copying.h"

namespace chapter_3::copying {

    Vector::Vector(const Vector& a) // copy constructor
            :elem{new double[a.sz]}, // allocate space for elements
             sz{a.sz}
    {
        for (int i=0; i!=sz; ++i) // copy elements
            elem[i] = a.elem[i];
    }


    Vector::Vector(Vector &&a) noexcept
            :elem{a.elem}, // "grab the elements" from a
             sz{a.sz}
    {
        a.elem = nullptr; // now a has no elements
        a.sz = 0;
    }

    Vector& Vector::operator=(const Vector& a) // copy assignment
    {
        auto* p = new double[a.sz];
        for (int i=0; i!=a.sz; ++i)
            p[i] = a.elem[i];
        delete[] elem; // delete old elements
        elem = p;
        sz = a.sz;
        return *this;
    }

    Vector &Vector::operator=(Vector &&a) noexcept {
        elem = a.elem; // "grab the elements" from a
        sz = a.sz;
        a.elem = nullptr; // now a has no elements
        a.sz = 0;
        return *this;
    }

    Vector operator+(const Vector& a, const Vector& b)
    {
        if (a.size() != b.size())
            throw std::out_of_range("Vector_size_mismatch{}");
        Vector res(a.size());
        for (int i = 0; i != a.size(); ++i)
            res[i] = a[i] + b[i];
        return res;
    }

    void ChapterThree_CopyingContainers()
    {
        std::cout <<"\nchapter_3::copying::ChapterThree_CopyingContainers() --pg.73:\n";
        Vector v2(0);
        {
            Vector v0(3); // make a vector of 3 elements
            for (int i = 0; i < v0.size(); ++i)
                v0[i] = i + 1; //each element equals i + 1
            Vector v1(v0);
            v2 = v1;
        }
        double sum = 0;
        for (int i = 0; i != v2.size(); ++i)
            sum += v2[i]; //take the sum of the elements
        std::cout << "After copying and assigning container of 3 elems, sum must be --6 = " << sum << std::endl;
    }

    void ChapterThree_MovingContainers()
    {
        std::cout <<"\nchapter_3::copying::ChapterThree_MovingContainers() --pg.75:\n";
        Vector v2(0);
        Vector v0(3); // make a vector of 3 elements
        for (int i = 0; i < v0.size(); ++i)
            v0[i] = i + 1; //each element equals i + 1
        Vector v1(std::move(v0));
        v2 = std::move(v1);
        double sum = 0;
        for (int i = 0; i != v2.size(); ++i)
            sum += v2[i]; //take the sum of the elements
        std::cout << "After moving and moving assigning container of 3 elems, sum must be --6 = " << sum << std::endl;
    }

    std::vector<std::thread> my_threads;

    void heartbeat() {
        std::cout << "Run heartbeat concurrently (on its own thread)" << std::endl;
    }

    Vector init(int n)
    {
        std::thread t {heartbeat}; // run heartbeat concurrently (on its own thread)
        t.detach();
        my_threads.push_back(move(t)); // move t into my_threads
        // ... more initialization ...
        Vector vec(n);
        for (int i=0; i<vec.size(); ++i) vec[i] = i + 1;
        return vec; // move res out of init()
    }

    void ChapterThree_Thread()
    {
        std::cout <<"\nchapter_3::copying::ChapterThree_Thread() --pg.76:\n";
        auto v = init(3); // start heartbeat and initialize v
        double sum = 0;
        for (int i = 0; i != v.size(); ++i)
            sum += v[i]; //take the sum of the elements
        std::cout << "After moving and moving assigning container of 3 elems, sum must be --6-- = " << sum << std::endl;
        std::cout << "my_threads size is --must be 1-- = " << my_threads.size() << std::endl;
    }

} // copying