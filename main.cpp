#include <iostream>
#include "chapter_2/chapter_2.h"
#include "chapter_3/chapter_3.h"

using namespace std; /// make names from std visible without std:: (§2.4.2)


int main() { /// pg.54 int main() {} --the minimal C++ program

    std::cout << "Hello world! ^_^\n";

    /// CHAPTER 2
    /// !-- Uncomment the desired method
    std::cout << "\nRun Chapter --Two code! ^_^\n";
    //chapter_2::RunChapterTwo_Square();
    //chapter_2::RunChapterTwo_Accept2();
    //chapter_2::RunChapterTwo_Accept3();
    //chapter_2::RunChapterTwo_CopyPrintIncrement();
    //chapter_2::RunChapterTwo_CountX();
    //chapter_2::RunChapterTwo_UserType();
    //chapter_2::RunChapterTwo_MakeAndVector();
    //chapter_2::RunChapterTwo_Enumerations();
    //chapter_2::RunChapterTwo_VectorDefinition();
    //chapter_2::RunChapterTwo_Namespaces();
    //chapter_2::exceptions::ChapterTwo_Exceptions();
    //chapter_2::invariants::ChapterTwo_Invariants();

    /// CHAPTER 3
    /// !-- Uncomment the desired method
    std::cout << "\nRun Chapter --Three code! ^_^\n";
    chapter_3::arithmetic::ChapterThree_Complex();

    std::cout << "\nAll good! ^_^";

}