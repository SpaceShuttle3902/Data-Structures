// ArrayOperations.h


class ArrayOperations {
public:
    ArrayOperations(); // Constructor
    ~ArrayOperations(); // Destructor

    // Function to check if a number exists in the array
    int checkIfExists(int num);

    // Function to modify the value at a given index
    void modifyValue(int index, int newValue, int& oldValue);

    // Function to add a new integer to the array
    void addInteger(int newNum);

    // Function to replace a value at a given index or remove the integer
    void replaceOrRemove(int index, bool remove);

    // Function to print the array
    void displayArray();

    // Function to read data from the file
    bool readFromFile(const char* filename);

private:
    int* arr;  // Dynamically allocated array
    int capacity;  // Max size of the array
    int size;  // Current size of the array
};

