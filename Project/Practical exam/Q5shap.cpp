#include <iostream>
using namespace std;

class Shape {
    public:
        virtual void draw() = 0; 
        virtual double calculateArea() = 0;
};

class Circle : public Shape {
    public:
        double radius;

        Circle(double r) {
            radius = r;
        }

        void draw() {
            cout << "Drawing a Circle" << endl;
        }

        double calculateArea() {
            return 3.14 * radius * radius; 
        }
};

class Rectangle : public Shape {
    public:
        double width, height;

        Rectangle(double w, double h) {
            width = w;
            height = h;
        }

        void draw() {
            cout << "Drawing a Rectangle" << endl;
        }

        double calculateArea() {
            return width * height;
        }
};

int main() {
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    Shape* shapePointer;

    // Circle 
    shapePointer = &myCircle;
    shapePointer->draw();
    cout << "Area of Circle: " << shapePointer->calculateArea() << "\n\n";

    // Rectangle
    shapePointer = &myRectangle;
    shapePointer->draw();
    cout << "Area of Rectangle: " << shapePointer->calculateArea() << "\n";

    return 0;
}
