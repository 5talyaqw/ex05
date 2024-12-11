#include "MyRectangle.h"
#include <iostream>

myShapes::MyRectangle::MyRectangle(Point a, double length, double width, std::string type, std::string name)
	: Polygon(type, name)
{
	_points.push_back(a); // bottom left
	_points.push_back(Point(a.getX() + length, a.getY()));
	_points.push_back(Point(a.getX(), a.getY() + width));
	_points.push_back(Point(a.getX() + length, a.getY() + width));
}

myShapes::MyRectangle::~MyRectangle()
{}

void myShapes::MyRectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[1]);
}

void myShapes::MyRectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[1]);
}

double myShapes::MyRectangle::getArea() const
{
	double len = _points[1].getX() - _points[0].getX();
	double wid = _points[2].getY() - _points[0].getY();

	return len * wid;
}

