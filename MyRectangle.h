#pragma once
#include "Polygon.h"


namespace myShapes
{
	// Calling it MyRectangle becuase Rectangle is taken by global namespace.
	class MyRectangle : public Polygon
	{
	public:

		// Constructor
		// There's a need only for the top left corner 
		MyRectangle(Point a, double length, double width, std::string type, std::string name);

		// Destructor
		~MyRectangle();

		// Methods
		void draw(const Canvas& canvas) override;
		void clearDraw(const Canvas& canvas) override;
		
		double getArea()const override;
	};
}
