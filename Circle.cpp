#include "Circle.h"
#include <iostream>
#include <cstdlib>

Circle::Circle(Point center, double radius, std::string type, std::string name) : Shape(name, type) , _center(center), _radius(radius){}

Circle::~Circle(){}

Point Circle::getCenter() const
{
	return _center;
}

double Circle::getRadius() const
{
	if (_radius < 0)
	{
		std::cerr << "negative radius!" << std::endl;
		exit(1);
	}
	return _radius;
}

double Circle::getPerimeter() const
{
	return 2 * PI * _radius;
}

double Circle::getArea() const
{
	return PI * (_radius * _radius);
}

void Circle::move(const Point& other)
{
	_center += other;
}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}
