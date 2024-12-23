#include <iostream>
#include "insertionSort.cpp"
using namespace std;

// Main Function
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;  // Taking size from the user

    // Create an array of size + 1 to accommodate the delimiter
    int arr[size + 1];

    // Taking input for the elements of the array
    cout << "Enter the elements of the array:" << endl;
    for (int i = 1; i <= size; i++) {  // Start from index 1
        cin >> arr[i];  // Store elements starting from arr[1]
    }

    // Display the array after the user has entered all elements
    cout << "Your array looks like this: {";
    for (int i = 1; i <= size; i++) {
        if(i<size)cout << arr[i] <<",";  // Print elements from arr[1] to arr[size]
        else cout<<arr[i]<<"}";
    }
    cout << endl;

    // Calling the Insertion Sort function
    insertionSort(arr, size);

    // Display the sorted array
    cout << "Array after Insertion Sort:" << endl;
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";  // Print the sorted array from arr[1] to arr[size]
    }
    cout << endl;

    return 0;
}