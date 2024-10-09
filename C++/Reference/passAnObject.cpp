#include <iostream>

class Rectangle {
public:
    // Constructor to initialize the rectangle's dimensions
    // Parameters:
    // - float width: The width of the rectangle.
    // - float height: The height of the rectangle.
    // The constructor uses an initializer list to set the private attributes.
    Rectangle(float width, float height) : width(width), height(height) {}

    // Getter for width (const indicates it does not modify the object)
    float getWidth() const { return width; }

    // Getter for height (const indicates it does not modify the object)
    float getHeight() const { return height; }

private:
    float width;  // Width of the rectangle
    float height; // Height of the rectangle
};

// Function to calculate area (passing by value)
// Parameters:
// - Rectangle rectangle: A copy of the rectangle is created for this function.
//   This involves allocating memory on the stack for the copy.
float area(Rectangle rectangle) {
    // A copy of 'rectangle' is created on the stack.
    // Memory is allocated for the copy, which has its own width and height.
    return rectangle.getHeight() * rectangle.getWidth(); // Calculate area using getters
}

// Function to calculate area (passing by reference)
// Parameters:
// - Rectangle &rectangle: A reference to the original rectangle is passed,
//   allowing direct access without creating a copy.
float area2(Rectangle &rectangle) {
    // No copy is created; the original rectangle is accessed directly.
    // Memory for the reference is allocated on the stack.
    return rectangle.getHeight() * rectangle.getWidth(); // Calculate area using getters
}

int main() {
    // Create two Rectangle objects with specified dimensions
    // The rectangles are allocated on the stack.
    Rectangle rectangle1(10, 50); // rectangle1 created on the stack
    Rectangle rectangle2(50, 20); // rectangle2 created on the stack

    // Calculate and print the area for each rectangle
    // For area(rectangle1), a copy is made and memory for it is allocated on the stack.
    std::cout << "Area of rectangle 1: " << area(rectangle1) << std::endl; // Calls the area function

    // For area2(rectangle2), no copy is made; the function accesses the original rectangle.
    std::cout << "Area of rectangle 2: " << area2(rectangle2) << std::endl; // Calls the area2 function

    return 0; // End of program
}

/*
    Memory Explanation:

    1. Rectangle Objects:
       - 'rectangle1' and 'rectangle2' are created on the stack when their constructors are called.
       - Memory for their width and height attributes is allocated when they are constructed.

    2. Function Call - area():
       - When calling `area(rectangle1)`, a copy of `rectangle1` is created on the stack.
       - Memory is allocated for the copy, including space for its width and height.
       - The original `rectangle1` remains unaffected by changes in the function.

    3. Function Call - area2():
       - When calling `area2(rectangle2)`, no copy is made; instead, a reference to `rectangle2` is passed.
       - Memory for the reference itself is allocated on the stack, but the original object is accessed directly.
       - This approach is more efficient as it avoids the overhead of creating a copy.

    4. Memory Release:
       - Upon exiting `main`, the stack memory allocated for `rectangle1`, `rectangle2`, and any copies created is automatically released.
*/
