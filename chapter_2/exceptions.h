#ifndef CPP_BJARNE_CODE_EXCEPTIONS_H
#define CPP_BJARNE_CODE_EXCEPTIONS_H

#include <stdexcept>

namespace chapter_2::exceptions {

        class Vector {
        public:
            explicit Vector(int s); // see definition of the constructor in cpp

            double& operator[](int i); // definition of subscripting in cpp

            [[nodiscard]] int size() const; // see definition of size()

        private:
            double* elem; // elem points to an array of sz doubles

            int sz;
        };

        void f(Vector& v);

        void ChapterTwoExceptions();

} // chapter_2::exceptions

#endif //CPP_BJARNE_CODE_EXCEPTIONS_H
