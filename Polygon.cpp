#include "Polygon.h"
#include <cmath>


Polygon::Polygon(std::string type, std::string name) : Shape(name, type){}


Polygon::~Polygon(){}


void Polygon::move(const Point& other)
{
	int i = 0;
	for (i = 0; i < _points.size(); i++)
	{
		_points[i] += other;
	}
}

std::vector<Point> Polygon::getPoints() const
{
	return _points;
}

double Polygon::getPerimeter() const
{
	double peri = 0.0;
	int i = 0;
	int nextIndex = 0;
	for (i = 0; i < _points.size(); i++)
	{
		nextIndex = (i + 1) % _points.size();
		peri += _points[i].distance(_points[nextIndex]);
	}
	return peri;
}
