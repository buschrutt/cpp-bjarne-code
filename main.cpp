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
    //chapter_3::arithmetic::ChapterThree_Complex();
    //chapter_3::container::ChapterThree_Container();
    //chapter_3::abstract::ChapterThree_Initialization();
    //chapter_3::abstract::ChapterThree_Abstract();
    //chapter_3::abstract::ChapterThree_Abstract2();
    //chapter_3::hierarchies::ChapterThree_DrawSmiley();
    //chapter_3::hierarchies::ChapterThree_DrawShapes();
    //chapter_3::copying::ChapterThree_CopyingContainers();
    //chapter_3::copying::ChapterThree_MovingContainers();
    //chapter_3::copying::ChapterThree_Thread();
    //chapter_3::templates::ChapterThree_TemplateVector();
    //chapter_3::templates::ChapterThree_FunctionTemplates();
    //chapter_3::templates::ChapterThree_FunctionObjects();
    //chapter_3::templates::ChapterThree_TemplateVariadic();


    std::cout << "\nAll good! ^_^";

}