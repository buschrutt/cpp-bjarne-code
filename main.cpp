#include <iostream>
#include "chapter_2.h"
#include "chapter_2/exceptions.h"

using namespace std; /// make names from std visible without std:: (§2.4.2)


int main() { /// pg.54 int main() {} --simple cpp program

    std::cout << "Hello world! ^_^\n";

    //RunChapterTwo();
    cout <<"\nchapter_2::exceptions::ChapterTwoExceptions():\n"; chapter_2::exceptions::ChapterTwoExceptions();

}