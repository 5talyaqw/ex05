#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name) : Polygon(type, name)
{
    //checking if the area is not 0 if it is then the points arent valid(all on the same line)

    double area = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());

    if (area == 0)
    {
        std::cerr << "Error: The points do not form a valid triangle (collinear points)." << std::endl;
        exit(1);
    }
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
}


Triangle::~Triangle()
{
}

double Triangle::getArea() const
{
    // Get the coordinates of the points
    double x1 = _points[0].getX();
    double y1 = _points[0].getY();
    double x2 = _points[1].getX();
    double y2 = _points[1].getY();
    double x3 = _points[2].getX();
    double y3 = _points[2].getY();

    //formula
    double area = 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    return area;
}

void Triangle::draw(const Canvas& canvas)
{
    canvas.draw_triangle(_points[0], _points[1], _points[2]);
}


void Triangle::clearDraw(const Canvas& canvas)
{
    canvas.clear_triangle(_points[0], _points[1], _points[2]);
}
