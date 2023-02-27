#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
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

    /// Begin Of %%%%%%%%%% %%%%%%%%%% Triangle

    void Triangle::move(Point to) {
        int x_shift = to.x - p1_.x;
        int y_shift = to.y - p1_.y;
        p1_ = to;
        p2_.x += x_shift;
        p2_.y += y_shift;
        p3_.x += x_shift;
        p3_.y += y_shift;
    }

    std::string Triangle::draw() const {
        std::string triangle_str;
        triangle_str = "<line x1=\"" + std::to_string(p1_.x) + "\" y1=\"" + std::to_string(p1_.y) + "\" ";
        triangle_str += "x2=\"" + std::to_string(p2_.x) + "\" y2=\"" + std::to_string(p2_.y) + "\" ";
        triangle_str += R"( stroke="black" stroke-width="3" fill="none"/>)";
        triangle_str += "<line x1=\"" + std::to_string(p2_.x) + "\" y1=\"" + std::to_string(p2_.y) + "\" ";
        triangle_str += "x2=\"" + std::to_string(p3_.x) + "\" y2=\"" + std::to_string(p3_.y) + "\" ";
        triangle_str += R"( stroke="black" stroke-width="3" fill="none"/>)";
        triangle_str += "<line x1=\"" + std::to_string(p3_.x) + "\" y1=\"" + std::to_string(p3_.y) + "\" ";
        triangle_str += "x2=\"" + std::to_string(p1_.x) + "\" y2=\"" + std::to_string(p1_.y) + "\" ";
        triangle_str += R"( stroke="black" stroke-width="3" fill="none"/>)";
        triangle_str += "\n";
        return triangle_str;
    }

    /// End Of ^^^^^ %%%%%%%%%% %%%%%%%%%% Triangle

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

    void DrawSvgUptr(std::string& filename, std::unique_ptr<Shape>&& shape)
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

    Shape* read_shape(std::istream& is) // read shape descriptions from input stream is
    {
        Kind k;
        {
            // ... read shape header from is and find its Kind k ...
            int kind_code;
            is >> kind_code;
            k = static_cast<Kind>(kind_code);
        }
        Point p, p1, p2, p3;
        int r;

        switch (k) {
            case Kind::circle:
            {
                // read circle data {Point, int} into p and r
                is >> p.x >> p.y >> r;
            }
                return new Circle{p, r};
            case Kind::triangle:
            {
                // read triangle data {Point,Point,Point} into p1, p2, and p3
                is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
            }
                return new Triangle{p1, p2, p3};
            case Kind::smiley:
                int e1_x, e1_y, e1_r;
                int e2_x, e2_y, e2_r;
                int m_x, m_y, m_shift_x, m_shift_y, e_shift_x, e_shift_y;
                {
                    // read smiley data {Point, int, Shape, Shape, Shape} into p, r, e1 ,e2, and m
                    is >> p.x >> p.y >> r >> e1_x >> e1_y >> e1_r >> e2_x >> e2_y >> e2_r;
                    is >> m_x >> m_y >> m_shift_x >> m_shift_y >> e_shift_x >> e_shift_y;
                }
                auto* ps = new Smiley{p, r};
                ps->add_eye(new Circle({e1_x, e1_y}, e1_r));
                ps->add_eye(new Circle({e2_x, e2_y}, e2_r));
                ps->set_mouth(new Path({m_x, m_y}, {m_shift_x, m_shift_y}, {e_shift_x, e_shift_y}));
                return ps;
        }
        throw std::exception ("no return");
    }

    void draw_all(std::vector<Shape*>& shapes, std::string& filename) {
        for (auto shape : shapes)
            DrawSvg(filename, shape);
    }

    void user(std::string filename)
    {
        std::vector<Shape*> v;
        std::istringstream is ("1 100 100 200 200 100 200");
        while (is) {
            try {
                v.push_back(read_shape(is));
            } catch (...){
                break;
            }
        }
        draw_all(v, filename); //call draw() for each element
        rotate_all(v,45); //call rotate(45) for each element
        for (auto p : v) delete p; // remember to delete elements
    }

    std::unique_ptr<Shape> read_shape_uptr(std::istream& is) // read shape descriptions from input stream is
    {
        Kind k;
        {
            // ... read shape header from is and find its Kind k ...
            int kind_code;
            is >> kind_code;
            k = static_cast<Kind>(kind_code);
        }
        Point p;
        int r;
        switch (k) {
            case Kind::circle:
            {
                // read circle data {Point, int} into p and r
                is >> p.x >> p.y >> r;
            }
                return std::unique_ptr<Shape>{new Circle{p, r}}; // §5.2.1
                // ...
            default:
                throw std::exception ("no return");
        }
    }

    void draw_all_uptr(std::vector<std::unique_ptr<Shape>>& shapes, std::string& filename) {
        for (auto & shape : shapes)
            DrawSvgUptr(filename, std::move(shape));
    }

    void rotate_all_uptr(std::vector<std::unique_ptr<Shape>>& shapes, int angle) {
        std::string drawing;
        for (const auto & shape : shapes)
            shape->rotate(angle);
    }

    void user_uptr(std::string& filename)
    {
        std::vector<std::unique_ptr<Shape>> v;
        std::istringstream is ("0 80 80 40"); // draw circle
        while (is)
            try {
                v.push_back(read_shape_uptr(is));
            } catch (...) {
                break;
            }
        draw_all_uptr(v, filename); // call draw() for each element
        rotate_all_uptr(v, 45); //call rotate(45) for each element
    } // all Shapes implicitly destroyed

    void ChapterThree_DrawShapes() {
        std::cout <<"\nchapter_3::hierarchies::ChapterThree_DrawShapes() --pg.71:\n";
        std::cout <<"check debug/release folder for files/smile.svg for output\n";
        std::string filename  = "files/smile.svg";
        user(filename);
        user_uptr(filename);
    }

} // chapter_3::hierarchies