#include <iostream>
#include <memory>
#include <cmath>

// Abstract base class for shapes
// Contains pure virtual methods that must be implemented by derived classes
class Shape {
public:
    virtual ~Shape() = default; // Virtual destructor to allow derived classes to clean up properly

    /*
     * Pure virtual function to calculate the area of the shape.
     * Every class that inherits from Shape must provide its own
     * implementation of this method.
     */
    [[nodiscard]] virtual float area() const = 0;

    /*
     * Pure virtual function to calculate the perimeter of the shape.
     * This forces derived classes to implement their own perimeter
     * calculation logic.
     */
    [[nodiscard]] virtual float perimeter() const = 0;
};

// Derived class representing a circle
class Circle : public Shape {
public:
    // Constructor initializes the circle with a radius
    explicit Circle(float radius) : radius(radius) {}

    // Implementation of the area() method specific to a circle
    [[nodiscard]] float area() const override { return M_PI * radius * radius; }

    // Implementation of the perimeter() method specific to a circle
    [[nodiscard]] float perimeter() const override { return 2 * M_PI * radius;  }

private:
    float radius; // The radius of the circle
};

// Derived class representing a rectangle
class Rectangle : public Shape {
public:
    // Constructor initializes the rectangle with a width and height
    Rectangle(float width, float height) : width(width), height(height) {}

    // Implementation of the area() method specific to a rectangle
    [[nodiscard]] float area() const override { return width * height; }

    // Implementation of the perimeter() method specific to a rectangle
    [[nodiscard]] float perimeter() const override { return 2 * (width + height); }

private:
    float width;  // The width of the rectangle
    float height; // The height of the rectangle
};

// Derived class representing a triangle
class Triangle : public Shape {
public:
    // Constructor initializes the triangle with a base, height, and two other sides
    Triangle(float base, float height, float side1, float side2)
        : base(base), height(height), side1(side1), side2(side2) {}

    // Implementation of the area() method specific to a triangle
    [[nodiscard]] float area() const override { return 0.5f * base * height;  }

    // Implementation of the perimeter() method specific to a triangle
    [[nodiscard]] float perimeter() const override { return base + side1 + side2;  }

private:
    float base;   // The base of the triangle
    float height; // The height of the triangle
    float side1;  // The first side of the triangle
    float side2;  // The second side of the triangle
};

// Function to display the area and perimeter of a given shape
// Parameters:
// - const Shape& shape: A reference to a shape object (polymorphic behavior is used)
void displayShapeInfo(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
    std::cout << "Perimeter: " << shape.perimeter() << std::endl;
}

int main() {
    /*
     * Memory management explanation:
     * In this program, we are using smart pointers (std::unique_ptr) to manage the memory
     * for the shape objects. Smart pointers automatically handle memory allocation and deallocation,
     * ensuring there are no memory leaks.
     * 
     * std::unique_ptr is used here for exclusive ownership. Each shape object (Circle, Rectangle, Triangle)
     * is owned by only one std::unique_ptr, and the memory will be automatically freed when the pointer
     * goes out of scope. This eliminates the need to manually delete objects.
     * 
     * std::make_unique is used to create instances of shapes and wrap them in std::unique_ptr.
     * This is safer than using raw pointers because the memory is managed automatically.
     */

    // Create shapes using smart pointers for automatic memory management
    std::unique_ptr<Shape> circle = std::make_unique<Circle>(5.0f); // Circle with radius 5
    std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(4.0f, 6.0f); // Rectangle with width 4 and height 6
    std::unique_ptr<Shape> triangle = std::make_unique<Triangle>(3.0f, 4.0f, 5.0f, 6.0f); // Triangle with base 3, height 4, sides 5 and 6

    /*
     * Memory management continues here:
     * Once the unique_ptr goes out of scope (i.e., when the function ends or the block where
     * the pointer is declared ends), the destructor of std::unique_ptr will automatically call
     * delete on the object it points to. This guarantees that there are no memory leaks.
     * 
     * Note: std::unique_ptr ensures that only one unique_ptr can point to a given object,
     * enforcing exclusive ownership.
     */

    // Display information about the circle
    std::cout << "Circle:" << std::endl;
    displayShapeInfo(*circle); // Pass the dereferenced unique_ptr pointing to the Circle object

    // Display information about the rectangle
    std::cout << "\nRectangle:" << std::endl;
    displayShapeInfo(*rectangle); // Pass the dereferenced unique_ptr pointing to the Rectangle object

    // Display information about the triangle
    std::cout << "\nTriangle:" << std::endl;
    displayShapeInfo(*triangle); // Pass the dereferenced unique_ptr pointing to the Triangle object

    return 0; // End of the program; unique_ptr destructors will be called here, freeing memory
}
