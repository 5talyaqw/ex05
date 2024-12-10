#include "Menu.h"
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Point.h"
#include <iostream>

Menu::Menu()
{

}

Menu::~Menu()
{
    // Delete all shapes in the vector
    for (int i = 0; i < _shapes.size(); i++)
    {
        delete _shapes[i];  // Free memory for each dynamically allocated shape
    }
}

void Menu::runMenu()
{
    int choice = -1;  // Initialize choice with an invalid value

    do
    {
        // Print menu options
        std::cout << "Enter 0 to add a new shape.\n"
            << "Enter 1 to modify or get information from a current shape.\n"
            << "Enter 2 to delete all of the shapes.\n"
            << "Enter 3 to exit." << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            addShape();
            break;

        case 1:
            modifyShape();
            break;

        case 2:
            deleteAllShapes();
            break;

        case 3:
            return;  // Exit the program
            break;

        default:
            std::cout << "Invalid option, try again!" << std::endl;
        }

    } while (choice != 3);
}

void Menu::addShape()
{
    int choice;
    Shape* newShape = nullptr;
    std::string shapeType, shapeName;

    // Ask user to choose shape type
    std::cout << "Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle. ";
    std::cin >> choice;

    switch (choice)
    {
    case 0:
    {
        Point center;
        double radius;
        std::cout << "Enter center point (x, y): ";
        std::cin >> center;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        std::cout << "Enter the name of the shape: ";
        std::cin >> shapeName;
        newShape = new Circle(center, radius, "Circle", shapeName);
        break;
    }
    case 1:
    {
        Point a, b;
        std::string type;
        std::cout << "Enter the source point (x, y): ";
        std::cin >> a;
        std::cout << "Enter the destination point (x, y): ";
        std::cin >> b;
        std::cout << "Enter type of arrow: ";
        std::cin >> type;
        newShape = new Arrow(a, b, type, shapeName);
        break;
    }
    case 2:
    {
        Point a, b, c;
        std::cout << "Enter point 1 (x, y): ";
        std::cin >> a;
        std::cout << "Enter point 2 (x, y): ";
        std::cin >> b;
        std::cout << "Enter point 3 (x, y): ";
        std::cin >> c;
        newShape = new Triangle(a, b, c, "Triangle", shapeName);
        break;
    }
    case 3:
    {
        Point topLeft;
        double length, width;
        std::cout << "Enter top left point (x, y): ";
        std::cin >> topLeft;
        std::cout << "Enter length: ";
        std::cin >> length;
        std::cout << "Enter width: ";
        std::cin >> width;
        newShape = new myShapes::Rectangle(topLeft, length, width, "Rectangle", shapeName);
        break;
    }
    default:
        std::cout << "Invalid shape choice!" << std::endl;
        return;
    }

    if (newShape)
    {
        _shapes.push_back(newShape);  // Add new shape to vector
        newShape->draw(_canvas);  // Draw shape on the canvas
    }
}

void Menu::modifyShape()
{
    // Implement modification logic here
}

void Menu::deleteAllShapes()
{
    //to do
}

void Menu::displayShapes()
{
    // Display all shapes
    for (Shape* shape : _shapes)
    {
        std::cout << "Shape Name: " << shape->getName() << std::endl;
        std::cout << "Shape Type: " << shape->getType() << std::endl;
        std::cout << "Area: " << shape->getArea() << std::endl;
        std::cout << "Perimeter: " << shape->getPerimeter() << std::endl;
    }
}

void Menu::getShapeDetails(Shape* shape)
{
    if (shape)
    {
        std::cout << "Shape Name: " << shape->getName() << std::endl;
        std::cout << "Shape Type: " << shape->getType() << std::endl;
        std::cout << "Area: " << shape->getArea() << std::endl;
        std::cout << "Perimeter: " << shape->getPerimeter() << std::endl;
    }
}

void Menu::removeShape(Shape* shape)
{
    if (shape)
    {
        // Clear the shape from the canvas and delete it from the vector
        if (shape->getType() == "Circle")
        {
            _canvas.clear_circle(); //
        }
        _shapes.erase(std::remove(_shapes.begin(), _shapes.end(), shape), _shapes.end());
        delete shape;
    }
}
