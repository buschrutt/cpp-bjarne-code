#include <iostream>
#include "square.h"

namespace chapter_2::square {

    /// pg.54 pg.55 chapter_2 square(2.0)
    void ChapterTwoSquare()
    {
        std::cout <<"\nchapter_2::square::ChapterTwoSquare() --pg.55:\n";
        std::cout << square(2.0) << std::endl;
    }

    /// pg.54: square func -- a double precision floating-point number
    double square(double x)
    {
        return x * x;
    }

} // chapter_2::square
