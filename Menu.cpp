#include "Menu.h"
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"
#include "MyRectangle.h"
#include "Polygon.h"
#include "Point.h"
#include <iostream>

Menu::Menu(){}

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
    std::string shapeName;

    // Ask user to choose shape type
    std::cout << "Enter 0 to add a circle.\nEnter 1 to add an arrow.\nEnter 2 to add a triangle.\nEnter 3 to add a rectangle. ";
    std::cin >> choice;

    switch (choice)
    {
    case 0:
    {
        double radius, x, y;
        std::cout << "Please enter X: ";
        std::cin >> x;
        std::cout << "Please enter Y: ";
        std::cin >> y;
        std::cout << "Please enter radius: ";
        std::cin >> radius;
        std::cout << "Enter the name of the shape: ";
        std::cin >> shapeName;

        Point center(x, y);
        newShape = new Circle(center, radius, "Circle", shapeName);
        break;
    }
    case 1:
    {
        double ax, ay, bx, by;
        std::string type;

        std::cout << "Enter the X of point number: 1";
        std::cin >> ax;
        std::cout << "Enter the Y of point number: 1";
        std::cin >> ay;

        std::cout << "Enter the X of point number: 2 ";
        std::cin >> bx;
        std::cout << "Enter the Y of point number: 2 ";
        std::cin >> by;

        std::cout << "Enter the name of the shape: ";
        std::cin >> shapeName;
        Point a(ax, ay);
        Point b(bx, by);
        newShape = new Arrow(a, b, type, shapeName);
        break;
    }
    case 2:
    {
        double ax, ay, bx, by, cx, cy;
        Point a, b, c;
        std::cout << "Enter the X of point number: 1 ";
        std::cin >> ax;
        std::cout << "Enter the Y of point number: 1 ";
        std::cin >> ay;

        std::cout << "Enter the X of point number: 2 ";
        std::cin >> bx;
        std::cout << "Enter the Y of point number: 2 ";
        std::cin >> by;

        std::cout << "Enter the X of point number: 3 ";
        std::cin >> cx;
        std::cout << "Enter the Y of point number: 3 ";
        std::cin >> cy;

        std::cout << "Enter the name of the shape: ";
        std::cin >> shapeName;

        newShape = new Triangle(a, b, c, "Triangle", shapeName);
        break;
    }
    case 3:
    {
        double x, y, length, width;

        // Input for the top-left corner
        std::cout << "Enter the X of the top-left corner: ";
        std::cin >> x;
        std::cout << "Enter the Y of the top-left corner: ";
        std::cin >> y;

        // Input for dimensions
        std::cout << "Please enter the length of the shape: ";
        std::cin >> length;
        std::cout << "Please enter the width of the shape: ";
        std::cin >> width;

        // Input for the name of the shape
        std::cout << "Enter the name of the shape: ";
        std::cin >> shapeName;

        // Create the top-left corner point
        Point topLeftCorner(x, y);

        // Construct the Rectangle object
        newShape = new myShapes::MyRectangle(topLeftCorner, length, width, "Rectangle", shapeName);
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
    if (_shapes.empty())
    {
        std::cout << "No shapes available to modify.\n";
        return;
    }
    int i = 0;
    for (i = 0; i < _shapes.size(); i++)
    {
        std::cout << "Enter " << i  << " for " << _shapes[i]->getName() << "(" << _shapes[i]->getType() << ")\n";
    }

    size_t choice;
    std::cin >> choice;

    // Validate choice
    if (choice < 0 || choice > _shapes.size())
    {
        std::cout << "Invalid choice. Returning to menu.\n";
        return;
    }

    // Get the selected shape
    Shape* selectedShape = _shapes[choice - 1];

    // Display modification options
    std::cout << "Enter 0 to Move the shape\n";
    std::cout << "Enter 1 to Get shape details\n";
    std::cout << "Enter 3 to Remove the shape\n";

    int action;
    std::cin >> action;

    switch (action)
    {
    case 1:
    {
        // Move the shape
        double newX, newY;
        std::cout << "Please enter the X moving scale: ";
        std::cin >> newX;
        std::cout << "Please enter the Y moving scale: ";
        std::cin >> newY;
        Point cord(newX, newY);
        selectedShape->move(cord);
        std::cout << "Shape moved.\n";
        break;
    }
    case 2:
    {
        // Get shape details
        std::cout << selectedShape->getName() << "    ";
        std::cout << selectedShape->getType() << "    ";
        std::cout << selectedShape->getArea() << "    ";
        std::cout << selectedShape->getPerimeter() << "    ";
        break;
    }
    case 3:
        // Remove the shape
    {
        _shapes.erase(_shapes.begin() + (choice - 1));
        std::cout << "Shape removed.\n";
        break;
    }
    default:
        std::cout << "Invalid action.\n";
        break;
    }
}

void Menu::deleteAllShapes()
{
    if (_shapes.empty())
    {
        std::cout << "No shapes to delete.\n";
        return;
    }
    int i = 0;
    for (i = 0; i < _shapes.size();i++)
    {
        delete _shapes[i];
    }
    _shapes.clear();
}

