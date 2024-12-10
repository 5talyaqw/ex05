#include "Arrow.h"
#include <iostream>
#include <cstdlib>

//Constructor
Arrow::Arrow(Point a, Point b, std::string type, std::string name) : Shape(name, type), _source(a), _destination(b) \
{
	if (a == b)
	{
		std::cerr << "Error: The source and destination points are identical" << std::endl;
		exit(1);
	}
}


Arrow::~Arrow(){}

Point Arrow::getSource() const
{
	return _source;
}

Point Arrow::getDestination() const
{
	return _destination;
}

double Arrow::getArea() const
{
	return 0.0; // the area of a line is 0
}

double Arrow::getPerimeter() const
{
	return _source.distance(_destination);
}

void Arrow::move(const Point& other)
{
	_source += other;
	_destination += other;
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_source, _destination);
}

void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_source, _destination);
}