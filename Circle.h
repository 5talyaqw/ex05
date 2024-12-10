#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
private:
	Point _center;
	double _radius;
public:

	// Constructor
	Circle(Point center, double radius, std::string type, std::string name);

	// Destructor
	virtual ~Circle();

	// Getters
	Point getCenter()const;
	double getRadius()const;
	double getPerimeter()const;
	double getArea()const;
	void move(const Point& other);

	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

};
