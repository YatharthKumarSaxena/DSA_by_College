// Linked List Implementation using two arrays without pointers
// Note INT_MIN is used as NULL
#include <climits>
#include <iostream>
using namespace std;
class LL{
public:

    //Data Members
    int START;  // Start pointer of Linked list
    int AVAIL;  // AVAIL Pointer
    int size; // Maximum capacity of Linked List
    // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
    int INFO[0];    // A list that contains Data of Linked List
    int LINK[0];    // A list that contains address of next element

    // Parameterized Constructor
    LL(int size){
        this->size = size;
        START = INT_MIN;    // Initially points to NULL i.e INT_MIN here
        AVAIL = 0;
        INFO[size];
        LINK[size];
        // Example LINK[0] = 1 points to 1st index of INFO array
        for(int i=0;i<size;i++){
            LINK[i] = i+1;  // Example LINK[0] = 1 points to 1st index of INFO array
        }
    }

    // Member functions
    void insertAtHead(int item);// Insertion at Beginning
    void insertAtEnd(int item); // Insertion at end
    void print(); // Printing of Linked list
    int count(); // To count the total number of elements in the linked list
    int search(int item); // Searching an element in Linked List
};