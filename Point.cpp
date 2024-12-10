#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point()
{
	_x = 0.0;
	_y = 0.0;
}

Point::Point(double x, double y) : _x(x) , _y(y) {}


Point::~Point(){}


Point Point::operator+(const Point& other)
{
	return Point(_x + other._x, _y + other._y);
}

Point& Point::operator+=(const Point& other)
{
	_x += other._x;
	_y += other._y;

	return *this;
}

bool Point::operator==(const Point& other)
{
	return (_x == other._x) && (_y == other._y);
}


double Point::getX() const
{
	return _x;
}

double Point::getY() const
{
	return _y;
}

double Point::distance(const Point& other)const
{
	double dx = _x - other._x;
	double dy = _y - other._y;

	return std::sqrt(dx * dx + dy * dy);
}

std::istream& operator>>(std::istream& in, Point& p)
{
	in >> p._x >> p._y;
	return in;
}
