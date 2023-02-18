#include <iostream>
#include "chapter_2/chapter_2.h"

using namespace std; /// make names from std visible without std:: (§2.4.2)


int main() { /// pg.54 int main() {} --simple cpp program

    std::cout << "Hello world! ^_^\n";

    /// CHAPTER 2
    //RunChapterTwo();
    chapter_2::exceptions::ChapterTwoExceptions();
    chapter_2::invariants::ChapterTwoInvariants();

    std::cout << "\nAll good! ^_^";

}