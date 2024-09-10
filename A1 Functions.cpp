// ArrayOperations.cpp
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "A1 Functions.h"

using namespace std;

// Constructor to initialize the array
ArrayOperations::ArrayOperations() {
    capacity = 200;  // Set an initial array capacity (you can adjust as needed)
    size = 0;  // Initialize size to 0
    arr = new int[capacity];  // Dynamically allocate the array
}

// Destructor to clean up memory
ArrayOperations::~ArrayOperations() {
    delete[] arr;
}

// Function to check if a number exists in the array
int ArrayOperations::checkIfExists(int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;  // Return the index if the number is found
        }
    }
    return -1;  // Return -1 if the number is not found
}

// Function to modify a value at a given index and return the old value
void ArrayOperations::modifyValue(int index, int newValue, int& oldValue) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range.");
    }
    oldValue = arr[index];  // Store the old value
    arr[index] = newValue;  // Modify the value
}

// Function to add a new integer to the end of the array
void ArrayOperations::addInteger(int newNum) {
    if (size >= capacity) {
        throw overflow_error("Array is full.");
    }
    arr[size] = newNum;
    size++;
}

// Function to replace the value at a given index or remove the integer
void ArrayOperations::replaceOrRemove(int index, bool remove) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range.");
    }
    if (remove) {
        // Shift elements left
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;  // Decrease the size of the array
    }
    else {
        arr[index] = 0;  // Replace with 0
    }
}

// Function to display the array contents
void ArrayOperations::displayArray() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to read data from the file into the array
bool ArrayOperations::readFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file!" << endl;
        return false;
    }

    int num;
    while (file >> num) {
        if (size < capacity) {
            arr[size++] = num;
        }
        else {
            cout << "Array capacity exceeded." << endl;
            break;
        }
    }
    file.close();
    return true;
}
