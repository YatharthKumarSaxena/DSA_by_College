#include <iostream>
#include "bubbleSort.cpp"
#include "effBubbleSort.cpp"

using namespace std;
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Your array looks as :- {";
    for(int i=0;i<n;i++){
        if(i==n-1)cout<<arr[i]<<"}";
        else cout<<arr[i]<<",";
    }
    int choice;
    cout << "\nChoose the sorting algorithm:\n";
    cout << "1. Normal Bubble Sort\n";
    cout << "2. Efficient Bubble Sort\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr,n);
            cout << "Array sorted using Normal Bubble Sort:\n";
            break;
        case 2:
            effBubbleSort(arr,n);
            cout << "Array sorted using Efficient Bubble Sort:\n";
            break;
        default:
            cout << "Invalid choice! Exiting program.\n";
            return 1;
    }

    cout<<"After Bubble Sort your array looks as :- {";
    for(int i=0;i<n;i++){
        if(i==n-1)cout<<arr[i]<<"}";
        else cout<<arr[i]<<",";
    }

}