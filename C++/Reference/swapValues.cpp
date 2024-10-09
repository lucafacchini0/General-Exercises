#include <iostream>

// Function to swap two integer values
// Parameters:
// - int &a: A reference to the first integer value.
// - int &b: A reference to the second integer value.
// The function uses references to allow direct modification of the original values.
void swapValues(int &a, int &b) {
    int temp = a; // Store the value of 'a' in a temporary variable
    a = b;        // Assign the value of 'b' to 'a'
    b = temp;    // Assign the value of 'temp' (original 'a') to 'b'
}

int main() {
    int number1 = 10; // Initialize number1 with 10
    int number2 = 50; // Initialize number2 with 50

    // Call swapValues to swap the values of number1 and number2
    swapValues(number1, number2);

    // Print the swapped values
    std::cout << number1 << " " << number2; // Should print "50 10"

    return 0; // End of program
}

/*
    Memory Explanation:

    1. Variable Initialization:
       - 'number1' and 'number2' are created on the stack when they are initialized in 'main'.
       - Memory is allocated for these integers to hold the values 10 and 50, respectively.

    2. Function Call - swapValues():
       - When calling `swapValues(number1, number2)`, the addresses of 'number1' and 'number2' are passed.
       - Memory for the references 'a' and 'b' is allocated on the stack, which points directly to 'number1' and 'number2'.
       - No copies of the integers are created; instead, the original integers are accessed directly.

    3. Variable Manipulation:
       - Inside the function, the value of 'a' is stored in 'temp'.
       - 'a' is updated to the value of 'b', and 'b' is updated to the value of 'temp', effectively swapping the original values.

    4. Memory Release:
       - Upon exiting 'main', the stack memory allocated for 'number1', 'number2', and the references 'a' and 'b' is automatically released.
*/
