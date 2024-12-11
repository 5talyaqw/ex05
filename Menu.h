#pragma once
#include "Shape.h"
#include "Canvas.h"
#include <vector>



class Menu
{
public:
	//constructor 
	Menu();

	// Destructor
	~Menu();
	
	//Menu runner
	void runMenu();
	

private:
	void addShape();
	void modifyShape();
	void deleteAllShapes();
	Canvas _canvas;
	std::vector<Shape*> _shapes;
};
