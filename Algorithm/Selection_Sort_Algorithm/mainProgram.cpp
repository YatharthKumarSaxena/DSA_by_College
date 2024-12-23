#include <iostream>
#include "selectionSort.cpp"
using namespace std;
// Function to display an array
void displayArray(const int arr[], int size) {
    cout << "Array: {";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}

int main() {
    int size;

    // Taking user input for array size
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    // Ensure the user enters a valid size
    if (size <= 0) {
        cout << "Array size must be positive. Please try again." << endl;
        return 1;
    }

    // Declare the array
    int arr[size];

    // Taking user input for array elements
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Display the array before sorting
    cout << "Before Selection Sort: ";
    displayArray(arr, size);

    // Sort the array using Selection Sort
    selectionSort(arr, size);

    // Display the array after sorting
    cout << "After Selection Sort: ";
    displayArray(arr, size);

    return 0;
}