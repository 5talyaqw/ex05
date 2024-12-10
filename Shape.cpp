#include "Shape.h"
#include <iostream>

Shape::Shape(std::string name, std::string type) : _name(name), _type(type) {}

Shape::~Shape(){}

std::string Shape::getType() const
{
	return _type;
}

std::string Shape::getName() const
{
	return _name;
}

void Shape::printDetails() const
{
	std::cout << "Shape: " << _name << "\n";
	std::cout << "Type: " << _type << "\n";
	std::cout << "Area: " << getArea() << "\n";
	std::cout << "Perimeter: " << getPerimeter() << "\n";
}
