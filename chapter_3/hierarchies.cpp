#include <string>
#include <iostream>
#include <fstream>
#include "hierarchies.h"

namespace chapter_3::hierarchies
{

    void DrawCircle(std::string & circle_str, Point x, int r, const std::string& fill = "black") {
        circle_str = "<circle cx=\"";
        circle_str += std::to_string(x.x);
        circle_str += "\" cy=\"";
        circle_str += std::to_string(x.y);
        circle_str += "\" r=\"";
        circle_str += std::to_string(r);
        circle_str += R"(" stroke="black" stroke-width="3" fill=")";
        circle_str += fill;
        circle_str +="\" />\n";
    }

    /// Begin Of %%%%%%%%%% %%%%%%%%%% Circle
    Circle::Circle(Point p, int rr): x{p}, r{rr} {}

    std::string Circle::draw() const {
        std::string circle_str;
        DrawCircle(circle_str, x, r);
        return circle_str;
    }

    void Circle::rotate(int angle) {}
    /// End Of ^^^^^ %%%%%%%%%% %%%%%%%%%% Circle

    /// Begin Of %%%%%%%%%% %%%%%%%%%% Path
    std::string Path::draw() const {
        std::string path_str = "<path d=\"M ";
        path_str += std::to_string(p_.x) + " ";
        path_str += std::to_string(p_.y) + " Q ";
        path_str += std::to_string(p_.x + m_shift_.x) + " ";
        path_str += std::to_string(p_.y + m_shift_.y) + " ";
        path_str += std::to_string(p_.x + end_shift_.x) + " ";
        path_str += std::to_string(p_.y + end_shift_.y);
        path_str += R"(" stroke="black" stroke-width="3" fill="none"/>)";
        path_str += "\n";
        return path_str;
    }

    void Path::rotate(int angle) {

    }
    /// End Of ^^^^^ %%%%%%%%%% %%%%%%%%%% Path

    /// Begin Of %%%%%%%%%% %%%%%%%%%% Smiley
    void Smiley::move(Point to) {
        int x_shift = to.x - x.x;
        int y_shift = to.y - x.y;
        x = to;
        mouth->move({mouth->center().x + x_shift, mouth->center().y + y_shift});
        for (auto eye : eyes)
            eye->move({eye->center().x + x_shift, eye->center().y + y_shift});
    }

    std::string Smiley::draw() const {
        std::string smiley_str;
        DrawCircle(smiley_str, x, r, "none");
        if (mouth != nullptr)
            smiley_str += mouth->draw();
        for (auto eye : eyes)
            smiley_str += eye->draw();
        return smiley_str;
    }

    /// nice algorithm is not implemented --dummy
    void Smiley::rotate(int angle) {
        // ...
    }

    void Smiley::set_mouth(Shape *s) {
        mouth = s;
    }

    void Smiley::wink(int i) {
        if (eyes.size() >= i)
        {
            eyes[i - 1] = new Path({eyes.at(i - 1)->center().x - 5, eyes.at(i - 1)->center().y},
                                {5, 5}, {10, 0});
        }
    }
    /// End Of ^^^^^ %%%%%%%%%% %%%%%%%%%% Smiley

    /// DrawSvg supporting method
    void DrawSvg(std::string& filename, const Shape* shape)
    {
        std::ofstream svg_f_stream(filename);
        if (svg_f_stream.is_open())
        {
            svg_f_stream << R"(<?xml version="1.0" encoding="UTF-8" ?>)" << "\n";
            svg_f_stream << R"(<svg xmlns="http://www.w3.org/2000/svg" version="1.1">)" << "\n";
            svg_f_stream << shape->draw() << "</svg>";
        } else
        {
            std::cerr << "--No file --found"<< std::endl;
        }
    }

    /// check debug/release folder for files/smile.svg for output
    void ChapterThree_DrawSmiley()
    {
        std::cout <<"\nchapter_3::hierarchies::ChapterThree_DrawSmiley() --pg.69:\n";
        std::cout <<"check debug/release folder for files/smile.svg for output\n";
        std::string filename  = "files/smile.svg";
        Smiley smiley({100, 100}, 50);
        smiley.set_mouth(new Path({70, 110}, {30, 35}, {60, 0}));
        smiley.add_eye(new Circle({85, 90}, 5));
        smiley.add_eye(new Circle({115, 90}, 5));
        smiley.wink(2);
        DrawSvg(filename, &smiley);
        smiley.move({70, 70});
        DrawSvg(filename, &smiley);
    }

    /// nice algorithm is not implemented --dummy
    [[maybe_unused]] void rotate_all(std::vector<Shape*>& v, int angle) // rotate v’s elements by angle degrees
    {
        for (auto p : v)
            p->rotate(angle);
    }

} // chapter_3::hierarchies