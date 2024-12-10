#include "Rectangle.h"
#include <iostream>

myShapes::Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name)
	: Polygon(type, name)
{
	_points.push_back(a); // bottom left
	_points.push_back(Point(a.getX() + length, a.getY()));
	_points.push_back(Point(a.getX(), a.getY() + width));
	_points.push_back(Point(a.getX() + length, a.getY() + width));
}

myShapes::Rectangle::~Rectangle()
{}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[1]);
}

double myShapes::Rectangle::getArea() const
{
	double len = _points[1].getX() - _points[0].getX();
	double wid = _points[2].getY() - _points[0].getY();

	return len * wid;
}

