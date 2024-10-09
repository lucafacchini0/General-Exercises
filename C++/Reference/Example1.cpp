#include <iostream>
#include <string>

// Function to increment an integer
// Parameters:
// - int &value: A reference to an integer that will be incremented.
//   This allows direct manipulation of the original variable passed to the function.
void increment(int &value) {
    value++; // Increment the original value
}

// Function to double the elements of an array
// Parameters:
// - int (&arr)[5]: A reference to an array of 5 integers.
//   This allows direct manipulation of the original array passed to the function.
void doubleArray(int (&arr)[5]) { // Pass an array of 5 integers by reference
    for (int i = 0; i < 5; ++i) {
        arr[i] *= 2; // Double each element of the array
    }
}

// Function to append text to a string
// Parameters:
// - std::string &text: A reference to a string that will be modified.
//   This allows direct manipulation of the original string passed to the function.
void appendText(std::string &text) {
    text += " World!"; // Append " World!" to the original string
}

// Class Person
class Person {
public:
    std::string name;

    // Constructor for Person class
    // Parameters:
    // - const std::string &name: A constant reference to a string to initialize the person's name.
    Person(const std::string &name) : name(name) {}
};

// Function to change the name of a person
// Parameters:
// - Person &p: A reference to a Person object whose name will be changed.
// - const std::string &newName: A constant reference to a string with the new name.
void changeName(Person &p, const std::string &newName) {
    p.name = newName; // Change the name of the original object
}

int main() {
    // Example 1: Pass an integer by reference
    int num = 10; // Allocate memory for an integer on the stack
    std::cout << "Before increment: " << num << std::endl; // Prints 10
    increment(num); // Pass the integer by reference
    std::cout << "After increment: " << num << std::endl; // Prints 11

    // Example 2: Pass an array by reference
    int myArray[5] = {1, 2, 3, 4, 5}; // Allocate memory for an array of 5 integers on the stack
    doubleArray(myArray); // Pass the array by reference
    std::cout << "Doubled array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " "; // Prints 2 4 6 8 10
    }
    std::cout << std::endl;

    // Example 3: Pass a string by reference
    std::string greeting = "Hello"; // Allocate memory for a string on the heap
    std::cout << "Before append: " << greeting << std::endl; // Prints "Hello"
    appendText(greeting); // Pass the string by reference
    std::cout << "After append: " << greeting << std::endl; // Prints "Hello World!"

    // Example 4: Pass an object of a custom class by reference
    Person person("Alice"); // Allocate memory for a Person object on the heap
    std::cout << "Before change: " << person.name << std::endl; // Prints "Alice"
    changeName(person, "Bob"); // Pass the object by reference
    std::cout << "After change: " << person.name << std::endl; // Prints "Bob"

    return 0; // End of program
}

/*
    Memory Explanation for Each Example:

    Example 1 (Incrementing an Integer):
    - The variable 'num' is allocated on the stack and initialized to 10.
    - When 'increment' is called, the reference 'value' is created, directly pointing to the memory location of 'num'.
    - The statement 'value++' increments the value stored at 'num' by 1, affecting the original variable directly.
    - After the function execution, 'num' now holds the incremented value (11).

    Example 2 (Doubling Array Elements):
    - The array 'myArray' is allocated on the stack with five integers initialized to {1, 2, 3, 4, 5}.
    - When 'doubleArray' is called, the reference 'arr' is created, pointing to the original array.
    - Each element of 'arr' is modified directly, doubling its value.
    - After the function execution, 'myArray' contains {2, 4, 6, 8, 10}.

    Example 3 (Appending to a String):
    - The variable 'greeting' is allocated on the heap and initialized to "Hello".
    - When 'appendText' is called, the reference 'text' is created, directly pointing to 'greeting'.
    - The statement 'text += " World!"' modifies the original string, appending the text directly.
    - After the function execution, 'greeting' holds "Hello World!".

    Example 4 (Changing an Object's Name):
    - The 'Person' object 'person' is allocated on the heap and initialized with the name "Alice".
    - When 'changeName' is called, the reference 'p' is created, pointing to the original 'person' object.
    - The statement 'p.name = newName' modifies the original object's name directly.
    - After the function execution, 'person.name' now holds "Bob".
*/
