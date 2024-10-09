#include <iostream>

// Function to increment the value of an integer
// Parameters:
// - int &item: A reference to an integer that will be incremented.
//   This allows direct manipulation of the original variable passed to the function.
void incrementValue(int &item) {
    item++; // Increment the value of the integer pointed to by the reference
}

int main() {
    int number = 10; // Allocate memory for an integer on the stack and initialize it to 10

    incrementValue(number); // Call the function and pass 'number' by reference

    std::cout << number; // Print the incremented value of 'number'

    return 0; // End of program
}

/*
    Memory Explanation for incrementValue Function:
    - The variable 'number' is allocated on the stack when the main function is called, occupying space for a single integer.
    - When 'incrementValue' is invoked, the reference parameter 'item' is created:
        - 'item' directly refers to the memory location of 'number', meaning any modifications to 'item' affect 'number' directly.
    - Inside the function:
        - The statement 'item++' increments the value stored at the memory address of 'number' by 1.
        - There is no additional memory allocation for 'item'; it is simply an alias for 'number'.
    - After the function execution, 'number' now holds the incremented value (11).
    - The memory for 'number' remains allocated on the stack until the main function exits, after which it is automatically released.
*/
