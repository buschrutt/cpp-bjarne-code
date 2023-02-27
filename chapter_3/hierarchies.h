#ifndef CPP_BJARNE_CODE_HIERARCHIES_H
#define CPP_BJARNE_CODE_HIERARCHIES_H

#include <vector>

namespace chapter_3::hierarchies
{

    struct Point {
       int x = 0;
       int y = 0;
    };

    class Shape {
    public:
        [[nodiscard]] virtual Point center() const = 0; // pure virtual

        virtual void move(Point to) = 0;

        [[nodiscard]] virtual std::string draw() const = 0; // draw on current "Canvas"

        virtual void rotate(int angle) = 0;

        virtual ~Shape() = default; // destructor
        // ...
    };

    [[maybe_unused]] void rotate_all(std::vector<Shape*>& v, int angle);

    class Circle : public Shape {
    public:
        Circle(Point p, int rr); // constructor

        [[nodiscard]] Point center() const override { return x; }

        void move(Point to) override { x = to; }

        [[nodiscard]] std::string draw() const override;

        void rotate(int angle) override; // nice simple algorithm

        // radius
    protected:
        Point x;
        // center
        int r;
        std::string fill_ = "none";
    };

    class Path : public Shape {
    public:
        Path(Point p, Point m_shift, Point end_shift): p_{p}, m_shift_{m_shift}, end_shift_{end_shift} {}; // constructor

        [[nodiscard]] Point center() const override { return p_; }

        void move(Point to) override { p_ = to; };

        [[nodiscard]] std::string draw() const override;

        void rotate(int angle) override; // nice simple algorithm

    private:
        Point p_; // start point
        Point m_shift_; // control point
        Point end_shift_; // end point
    };

    class Smiley : public Circle { // use the circle as the base for a face
    public:
        Smiley(Point p, int r) : Circle{p,r}, mouth{nullptr} { }

        ~Smiley() override
        {
            delete mouth;
            for (auto p : eyes) delete p;
        }

        void move(Point to) override;

        [[nodiscard]] std::string draw() const override;

        void rotate(int angle) override;

        void add_eye(Shape* s) { eyes.push_back(s); }

        void set_mouth(Shape* s);

        virtual void wink(int i); // wink eye number i
    // ...
    private:
        std::vector<Shape*> eyes; //usually two eyes
        Shape* mouth;
    };

    void DrawSvg(std::string & filename, const Shape & shape);

    void ChapterThree_DrawSmiley();

    /// --!-- ChapterThree_DrawShapes handling

    class Triangle : public Shape {
    public:
        Triangle(Point p1, Point p2, Point p3): p1_{p1}, p2_{p2}, p3_{p3} {}; // constructor

        [[nodiscard]] Point center() const override { return p1_; }

        void move(Point to) override;

        [[nodiscard]] std::string draw() const override;

        void rotate(int angle) override {}

    private:
        Point p1_, p2_, p3_; // Triangle points
    };

    enum class Kind { circle, triangle , smiley };

    Shape* read_shape(std::istream& is); // read shape descriptions from input stream is

    void draw_all(std::vector<Shape*>& shapes, std::string& filename);

    void user(std::string filename);

    std::unique_ptr<Shape> read_shape_uptr(std::istream& is); // read shape descriptions from input stream is

    void draw_all_uptr(const std::vector<std::unique_ptr<Shape>>& shapes, std::string& filename);

    void rotate_all_uptr(std::vector<std::unique_ptr<Shape>>& shapes, int angle);

    void user_uptr(std::string& filename);

    void ChapterThree_DrawShapes();

} // chapter_3::hierarchies

#endif //CPP_BJARNE_CODE_HIERARCHIES_H
