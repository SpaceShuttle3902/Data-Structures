// main.cpp - Main program to test array operations
#include <iostream>  // For input and output
#include <stdexcept> // For exception handling (like out of range errors)
#include "A1 Functions.h" // Include the header file that contains our array functions

using namespace std; // So we don't have to type 'std::' before cout and cin

int main() {
    ArrayOperations arrOps; // Create an object of the ArrayOperations class to use its functions

    // Try to read data from the input file named "A1input.txt"
    if (!arrOps.readFromFile("A1input.txt")) {
        cout << "Error: Failed to read from file." << endl;
        return 1;  // Exit if file reading fails
    }

    int choice;       // Variable to store user's menu choice
    int num, index;   // Variables to store a number and index from user input
    int newValue;     // Variable to store a new value for modification
    int oldValue;     // Variable to store the old value during modification

    // Start a loop that will display a menu of options until the user chooses to exit
    do {
        // Display the menu with options for array operations
        cout << "\nArray Operations Menu:\n";
        cout << "1. Check if a number exists\n";
        cout << "2. Modify a number in the array\n";
        cout << "3. Add a new number to the array\n";
        cout << "4. Replace or remove a number from the array\n";
        cout << "5. Display the array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get the user's choice

        // Handle the user's choice using a switch statement
        switch (choice) {
        case 1:
            // Option 1: Check if a number exists in the array
            cout << "Enter a number to check: ";
            cin >> num; // Get the number from the user
            index = arrOps.checkIfExists(num); // Call the function to check for the number
            if (index != -1) { // If the number is found, display its index
                cout << "Number found at index " << index << endl;
            }
            else { // If the number is not found, display a message
                cout << "Number not found." << endl;
            }
            break;

        case 2:
            // Option 2: Modify a number at a given index
            try {
                // Get the index and new value from the user
                cout << "Enter the index to modify: ";
                cin >> index;
                cout << "Enter the new value: ";
                cin >> newValue;
                // Modify the value at the given index, also get the old value
                arrOps.modifyValue(index, newValue, oldValue);
                // Display the old and new values
                cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
            }
            catch (const exception& e) { // Catch any errors (e.g., invalid index)
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 3:
            // Option 3: Add a new number to the array
            try {
                cout << "Enter the number to add: ";
                cin >> num; // Get the number from the user
                arrOps.addInteger(num); // Add the number to the array
                cout << "Number added successfully." << endl;
            }
            catch (const exception& e) { // Catch any errors (e.g., array is full)
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 4:
            // Option 4: Replace or remove a number from the array
            try {
                cout << "Enter the index to modify: ";
                cin >> index; // Get the index from the user
                cout << "Do you want to remove the number? (1 for Yes, 0 for No): ";
                bool remove; // Variable to store the user's choice to remove or replace
                cin >> remove;
                // Replace or remove the number based on user's input
                arrOps.replaceOrRemove(index, remove);
                cout << "Operation successful." << endl;
            }
            catch (const exception& e) { // Catch any errors (e.g., invalid index)
                cout << "Error: " << e.what() << endl;
            }
            break;

        case 5:
            // Option 5: Display the current contents of the array
            arrOps.displayArray(); // Call the function to display the array
            break;

        case 6:
            // Option 6: Exit the program
            cout << "Exiting program." << endl;
            break;

        default:
            // If the user enters an invalid option, show an error message
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6); // Keep looping until the user chooses to exit (choice 6)

    return 0; // End of the program
}
