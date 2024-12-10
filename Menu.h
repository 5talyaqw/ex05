#pragma once
#include "Shape.h"
#include "Canvas.h"
#include <vector>



class Menu
{
public:

	Menu();
	~Menu();
	void runMenu();
	

private:
	void addShape();
	void modifyShape();
	void deleteAllShapes();
	void displayShapes();
	void getShapeDetails(Shape* shape);
	void removeShape(Shape* shape);
	Canvas _canvas;
	std::vector<Shape*> _shapes;
};
