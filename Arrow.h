#pragma once
#include "Shape.h"

class Arrow : public Shape
{
public:

	// Constructor
	Arrow(Point a, Point b, std::string type, std::string name);

	// Destructor
	virtual ~Arrow();

	// Getters
	Point getSource() const;
	Point getDestination() const;
	double getArea()const override;
	double getPerimeter()const override;

	void move(const Point& other)override;
	
	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

	// override functions if need (virtual + pure virtual)

private:
	Point _source;
	Point _destination;
};
