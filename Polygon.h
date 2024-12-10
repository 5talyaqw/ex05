#pragma once

#include "Shape.h"
#include <vector>

class Polygon : public Shape
{
public:

	// Constructor
	Polygon(std::string type, std::string name);

	// Destructor
	virtual ~Polygon();

	// Methods
	void move(const Point& other);

	// Getters
	std::vector<Point> getPoints() const;
	double getPerimeter() const;


protected:
	std::vector<Point> _points;
};
