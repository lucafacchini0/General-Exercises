#include <iostream>

// Function to copy an array of integers
// Parameters:
// - int (&source)[5]: A reference to an array of 5 integers that serves as the source array.
// - int (&destination)[5]: A reference to an array of 5 integers that will store the copied values.
// - int size: The number of elements to copy from the source array to the destination array.
void copyArray(int (&source)[5], int (&destination)[5], int size) {
    // Loop through each element of the source array up to the specified size
    for (int i = 0; i < size; ++i) {
        destination[i] = source[i]; // Copy the value from the source array to the destination array
    }
}

int main() {
    int original[5] = {1, 2, 3, 4, 5}; // Original array of integers (allocated on the stack)
    int copied[5]; // Array to hold the copied values (also allocated on the stack)

    // Call the copy function
    copyArray(original, copied, 5); // Pass the original array and the copied array along with the size

    // Print the original array
    std::cout << "Original Array: ";
    for (int i : original) {
        std::cout << i << " "; // Print each element in the original array
    }
    std::cout << std::endl;

    // Print the copied array
    std::cout << "Copied Array: ";
    for (int i : copied) {
        std::cout << i << " "; // Print each element in the copied array 
    }
    std::cout << std::endl;

    return 0; // End of program
}

/*
    Memory Explanation for copyArray Function:
    - The arrays 'original' and 'copied' are both allocated on the stack when the main function is called.
    - The 'original' array occupies memory for 5 integers.
    - The 'copied' array also occupies memory for 5 integers, initially uninitialized.
    - When 'copyArray' is called, both arrays are passed by reference:
        - 'source' refers directly to 'original'.
        - 'destination' refers directly to 'copied'.
    - Inside the function:
        - No new memory is allocated for 'source' or 'destination'; they simply point to the existing arrays in memory.
        - The for loop iterates through each element of 'source', copying its value directly into 'destination'.
    - After the function execution, the copied values in 'copied' reflect the values from 'original'.
    - Both arrays remain allocated on the stack until the main function exits, after which their memory is automatically released.
*/
