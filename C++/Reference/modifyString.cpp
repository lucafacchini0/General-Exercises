#include <iostream>
#include <string>

using std::string;

// Function to modify a string by appending a predefined message
// Parameters:
// - string &a: A reference to a string that will be modified.
//   This allows direct manipulation of the original string passed to the function.
void modifyString(string &a) {
    a += " I love coding."; // Append " I love coding." to the original string
}

// Function to modify a string by appending a suffix string
// Parameters:
// - string &a: A reference to a string that will be modified.
// - string &suffix: A reference to another string that will be appended to 'a'.
//   Both references allow direct manipulation of the original strings passed to the function.
void modifyString(string &a, string &suffix) {
    a += suffix; // Append 'suffix' to the original string
}

int main() {
    // Initialize a string with a greeting message
    string myString = "Hello, I'm Luca!"; // Allocate memory for 'myString' on the heap

    // Call the modifyString function to append a predefined message
    modifyString(myString); // Pass the string by reference

    // Print the modified string
    std::cout << myString << std::endl; // Prints: "Hello, I'm Luca! I love coding."

    // Initialize a second string with a greeting message and a suffix
    string myString2 = "Hello, I'm Luca!"; // Allocate memory for 'myString2' on the heap
    string mySuffix = " I love coding."; // Allocate memory for 'mySuffix' on the heap
    
    // Call the modifyString function to append a suffix string
    modifyString(myString2, mySuffix); // Pass both strings by reference

    // Print the modified string again (this should still print the first modified string)
    std::cout << myString << std::endl; // Prints: "Hello, I'm Luca! I love coding."

    return 0; // End of program
}

/*
    Memory Explanation:

    - The string variables 'myString', 'myString2', and 'mySuffix' are all allocated on the heap.
    
    Example 1 (Modifying the First String):
    - The variable 'myString' is initialized with "Hello, I'm Luca!".
    - When 'modifyString' is called with 'myString', the reference 'a' is created, directly pointing to the memory location of 'myString'.
    - The operation 'a += " I love coding."' modifies the original string, appending the text directly.
    - After this operation, 'myString' now holds "Hello, I'm Luca! I love coding.".

    Example 2 (Modifying the Second String):
    - The variable 'myString2' is initialized with "Hello, I'm Luca!" and 'mySuffix' is initialized with " I love coding.".
    - When 'modifyString' is called with both strings, two references are created, pointing directly to 'myString2' and 'mySuffix'.
    - The operation 'a += suffix' appends 'mySuffix' to 'myString2'.
    - After this operation, 'myString2' now holds "Hello, I'm Luca! I love coding.".

    - The output at the end of the main function prints the modified first string from Example 1, which holds the modified content.
*/
