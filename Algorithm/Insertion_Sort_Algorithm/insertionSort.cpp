#include <climits>
// Insertion Sort
void insertionSort(int arr[],int size){
    // Initialize a Delimeter , Note :- INT_MIN is used as -infinity here
    arr[0] = INT_MIN;   // Array Size is size+1 (Size is entered by user)
    for(int k=2;k<=size;k++){
        int temp = arr[k], PTR = k-1;
        while(temp<arr[PTR]){
            arr[PTR+1] = arr[PTR];
            PTR -= 1;
        }
        arr[PTR+1] = temp;
    }
}