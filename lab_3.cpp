#include <iostream>
#include <fstream>

using namespace std;

struct Figure
{
    string stroke = "none";
    double stroke_width = 1;
    string fill = "none";
    string opacity;

    Figure
    (
        string stroke,
        double stroke_width,
        string fill,
        string opacity
    ) :
        stroke(stroke),
        stroke_width(stroke_width),
        fill(fill), 
        opacity(opacity) {};
};

struct Rect : Figure
{
    double width;
    double height;
    double x;
    double y;

    Rect
    (
        double width,
        double height,
        double x,
        double y,
        string stroke,
        double stroke_size,
        string fill,
        string opacity
    ) : 
        width(width),
        height(height),
        x(x),
        y(y),
        Figure(stroke, stroke_size, fill, opacity) {};
};

struct Line : Figure
{
    double x1;
    double y1;
    double x2;
    double y2;

    Line
    (
        double x1,
        double y1,
        double x2,
        double y2,
        string color,
        double stroke_size,
        string fill,
        string opacity
    ) :
        x1(x1),
        y1(y1),
        x2(x2),
        y2(y2),
        Figure(color, stroke_size, fill, opacity) {};
};

struct Circle : Figure
{
    double r;
    double x;
    double y;
    Circle
    (
        double r,
        double x,
        double y,
        string stroke,
        double stroke_size,
        string fill,
        string opacity
    ) :
        r(r),
        x(x),
        y(y),
        Figure(stroke, stroke_size, fill, opacity) {};
};

struct Triangle : Figure
{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;

    Triangle
    (
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3,
        string stroke,
        double stroke_size,
        string fill,
        string opacity
    ) :
        x1(x1),
        y1(y1),
        x2(x2),
        y2(y2),
        x3(x3),
        y3(y3),
        Figure(stroke, stroke_size, fill, opacity) {};
};

struct Box : Figure
{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
    double x4;
    double y4;

    Box
    (
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3,
        double x4,
        double y4,
        string stroke,
        double stroke_size,
        string fill,
        string opacity
    ) :
        x1(x1),
        y1(y1),
        x2(x2),
        y2(y2),
        x3(x3),
        y3(y3),
        x4(x4),
        y4(y4),
        Figure(stroke, stroke_size, fill, opacity) {};
};

ofstream& operator<<(ofstream& os, const Line& l)
{
    os << "<line x1=\"" << l.x1 << "\"" <<
        " y1=\"" << l.y1 << "\"" << 
        " x2=\"" << l.x2 << "\"" <<
        " y2=\"" << l.y2 << "\"" <<
        " stroke=\"" << l.stroke << "\"" <<
        " stroke-width=\"" << l.stroke_width << "\"" <<
        " opacity=\"" << l.opacity << "\"" <<
        " />" << endl;

    return os;
}

ofstream& operator<<(ofstream& os, const Circle& c)
{
    os << "<circle r=\"" << c.r << "\"" <<
        " cx=\"" << c.x << "\"" << 
        " cy=\"" << c.y << "\"" << 
        " stroke=\"" << c.stroke << "\"" <<
        " stroke-width=\"" << c.stroke_width << "\"" <<
        " fill=\"" << c.fill << "\"" << 
        " opacity=\"" << c.opacity << "\"" << 
        " />" << endl;

    return os;
}

ofstream& operator<<(ofstream& os, const Triangle& t)
{
    os << "<polyline points=\"" << 
        t.x1 << "," << 
        t.y1 << " " << 
        t.x2 << "," << 
        t.y2 << " " << 
        t.x3 << "," <<
        t.y3 << "\"" <<
        " stroke=\"" << t.stroke << "\"" <<
        " stroke-width=\"" << t.stroke_width << "\"" << 
        " fill=\"" << t.fill << "\"" <<
        " opacity=\"" << t.opacity << "\""<<
        " />" << endl;

    return os;
}

ofstream& operator<<(ofstream& os, const Box& b)
{
    os << "<polyline points=\"" << 
        b.x1 << "," << 
        b.y1 << " " << 
        b.x2 << "," << 
        b.y2 << " " << 
        b.x3 << "," <<
        b.y3 << " " <<
        b.x4 << "," <<
        b.y4 << "\"" <<
        " stroke=\"" << b.stroke << "\"" <<
        " stroke-width=\"" << b.stroke_width << "\"" << 
        " fill=\"" << b.fill << "\"" <<
        " opacity=\"" << b.opacity << "\""<<
        " />" << endl;

    return os;
}

ofstream& operator<<(ofstream& os, const Rect& r)
{
    os << "<rect width=\"" << r.width << "\"" <<
        " height=\"" << r.height << "\"" << 
        " rx=\"" << r.x << "\"" << 
        " ry=\"" << r.y << "\"" << 
        " stroke=\"" << r.stroke << "\"" << 
        " stroke-width=\"" << r.stroke_width << "\"" <<
        " fill=\"" << r.fill << "\"" <<
        " opacity=\"" << r.opacity << "\"" <<
        " />" << endl;

    return os;
}

int main()
{
    ofstream os("img.svg");

    os << "<svg  viewBox=\"0 0 170 256\">" << endl;

    Rect background(170, 256, 0, 0, "none", 0, "#cecece", "100%");
    os << background;

    Box box_03(45, 0, 20, 139, 73, 150, 110, 0, "none", 0, "#8d5c5c", "80%");
    os << box_03;

    Triangle triangle_01(80, 130, 48, 143, 45, 256, "none", 0, "#5f5f5f", "100%");
    os << triangle_01;

    Triangle triangle_02(110, 190, 55, 0, 145, 0, "none", 0, "#464242", "100%");
    os << triangle_02;

    Triangle triangle_03(35, 65, 0, 50, 0, 70, "none", 0, "#363636", "100%");
    os << triangle_03;

    Box box_01(90, 80, 110, 0, 170, 0, 170, 100, "none", 0, "#cecece", "100%");
    os << box_01;

    Box box_02(90, 80, 78, 130, 170, 153, 170, 100, "none", 0, "#363636", "100%");
    os << box_02;

    Circle circle_01(34, 80, 130, "none", 0, "#0050e4", "45%");
    os << circle_01;

    Circle circle_02(70, 40, 73, "none", 0, "#ff4000", "60%");
    os << circle_02;

    Circle circle_03(23, 170, 126, "none", 0, "#cecece", "100%");
    os << circle_03;

    os << "</svg>";

    return 0;
}
