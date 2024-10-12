#include <iostream>
#include <memory>
#include <cmath>

// Base class for shapes
class Shape {
public:
    virtual ~Shape() = default; // Virtual destructor

    /*
     * A pure virtual function is declared by assigning 0 to it,
     * indicating that it has no implementation in the base class
     * (Shape, in this case). This enforces that any derived class
     * must provide its own implementation of this function to be
     * instantiated. If a derived class fails to implement this
     * function, it too becomes an abstract class and cannot be
     * instantiated.
     */

    [[nodiscard]] virtual float area() const = 0;
    [[nodiscard]] virtual float perimeter() const = 0;
};




class Circle : public Shape {
public:
    Circle(float radius) : radius(radius) {}

    [[nodiscard]] float area() const override { return M_PI * radius * radius; }
    [[nodiscard]] float perimeter() const override { return 2 * M_PI * radius;  }

private:
    float radius;
};





class Rectangle : public Shape {
public:
    Rectangle(float width, float height) : width(width), height(height) {}

    [[nodiscard]] float area() const override { return width * height; }
    [[nodiscard]] float perimeter() const override { return 2 * (width + height); }

private:
    float width;
    float height;
};





class Triangle : public Shape {
public:
    Triangle(float base, float height, float side1, float side2)
        : base(base), height(height), side1(side1), side2(side2) {}

    [[nodiscard]] float area() const override { return 0.5f * base * height;  }
    [[nodiscard]] float perimeter() const override { return base + side1 + side2;  }

private:
    float base;
    float height;
    float side1;
    float side2;
};




// Function to display shape information
void displayShapeInfo(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
    std::cout << "Perimeter: " << shape.perimeter() << std::endl;
}





int main() {
    // Create shapes using smart pointers
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(5.0f);
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(4.0f, 6.0f);
    std::unique_ptr<Shape> triangle = std::make_unique<Triangle>(3.0f, 4.0f, 5.0f, 6.0f);

    // Display information about each shape
    std::cout << "Circle:" << std::endl;
    displayShapeInfo(*circle); // pass the dereferenced unique_ptr pointing to the Circle object
                                // i'm literally passing the data contained in circle.

    std::cout << "\nRectangle:" << std::endl;
    displayShapeInfo(*rectangle);

    std::cout << "\nTriangle:" << std::endl;
    displayShapeInfo(*triangle);

    return 0;
}
