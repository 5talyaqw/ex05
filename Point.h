#pragma once

class Point
{
private:
	double _x;
	double _y;
public:

	// Constructors
	Point(); // initialize values to 0
	Point(double x, double y);

	// Destructor
	~Point();

	// Operators
	Point operator+(const Point& other);
	Point& operator+=(const Point& other);
	bool operator==(const Point& other);

	// Getters
	double getX() const;
	double getY() const;

	// Methods
	double distance(const Point& other)const;
};