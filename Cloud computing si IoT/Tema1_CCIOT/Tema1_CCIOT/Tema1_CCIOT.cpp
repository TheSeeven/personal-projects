// Lab1_CCIOT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define PI 3.14159265358979323846

class CheckValue {};

class Shape2D {
protected:
    double perimeter = -1.0;
    double area = -1.0;

    void drawATR() {
        if (perimeter > 0.0) std::cout << "The perimeter is: " << getPerimeter() << std::endl;
        if (area > 0.0) std::cout << "The area is: " << getArea() << std::endl;
        std::cout << std::endl;
    }

public:
    Shape2D() {};
    ~Shape2D() {};

    double getPerimeter() { return perimeter; }
    double getArea() { return area; }

    virtual double setArea() = 0;
    virtual double setPerimeter() = 0;
    virtual void draw() = 0;
};

class Quadrilateral : Shape2D {
private:
    double length;
    double width;
public:
    Quadrilateral() {}
    Quadrilateral(double length, double width) : length(length), width(width) {}
    Quadrilateral(double length, double width, bool setShapeATR) : length(length), width(width) {
        if (setShapeATR) { setArea(); setPerimeter(); }
    }
    ~Quadrilateral() {}

    virtual double setArea() {
        if (area < 0.0)
            area = length * width;
        return area;
    }

    virtual double setPerimeter() {
        if (perimeter < 0.0)
            perimeter = 2.0 * length + 2.0 * width;
        return perimeter;
    }

    virtual void draw() {
        std::string isSquare;
        if (this->isSquare()) isSquare = "Square"; else isSquare = "Rectangle";
        std::cout << "The length is: " << length << "\nThe width is: " << width << "\nThe shape is: " << isSquare << std::endl;
        drawATR();
    }

    bool isSquare() {
        if (length == width) return true;
        return false;
    }

    double getLength() { return length; }
    double getWidth() { return length; }
};

class Circle : Shape2D {
private:
    double radius;

public:
    Circle() {}
    Circle(double radius) : radius(radius) {}
    Circle(double radius, bool setShapeATR) : radius(radius) {
        if (setShapeATR) { setPerimeter(); setArea(); }
    }
    ~Circle() {}

    virtual double setPerimeter() {
        if (perimeter < 0.0)
            perimeter = 2.0 * PI * radius;
        return perimeter;
    }

    virtual double setArea() {
        if (area < 0.0)
            area = PI * radius * radius;
        return area;
    }

    virtual void draw() {
        std::cout << "The radius is: " << radius << std::endl;
        drawATR();
    }

    double getRadius() { return radius; }
};


bool checkValue(double& radius, double& length) {
    if (radius <= 0.0 || length <= 0.0) {
        throw CheckValue();
    }
    return true;
}

int main()
{
    int choice;

    Quadrilateral shape;
    double length;
    double width;

    Circle shape2;
    double radius;

    while (1) {
        std::cout << "(1)Circle (2)Quadrilateral (0)Quit: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "\nInsert the radius:";
            std::cin >> radius;
            try
            {

                checkValue(radius, radius);
            }
            catch (CheckValue d)
            {
                std::cin.clear();
                std::cout << "The value must be greater than 0 and positive!\n\n";
                break;
            }

            shape2 = Circle(radius, true);
            shape2.draw();
            break;

        case 2:
            std::cout << "\nInsert the length:";
            std::cin >> length;

            std::cout << "\nInsert the width:";
            std::cin >> width;

            try
            {
                checkValue(length, width);
            }
            catch (CheckValue d)
            {
                std::cin.clear();
                std::cout << "The values must be greater than 0 and positive!\n\n";
                break;
            }

            shape = Quadrilateral(length, width, true);
            shape.draw();
            break;

        default:
            std::cout << "\nProgram quit..." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
