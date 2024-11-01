#include <iostream>
#include <climits>
using namespace std;

// Circular Linked List Class

class CircularLinkedList{

// Data Members

    int capacity; // Maximum Capacity of Avail List
    int *INFO; // Info Array
    int *LINK; // Link Array
    int AVAIL; // Avail Pointer
    int START; // Start Pointer
    int size; // Stores the current size of the Linked List

public:

    // Parameterized Constructor

    CircularLinkedList(int capacity){
        this->capacity = capacity;
        START = 0; // Start pointer of Linked list currently points to NULL
        AVAIL = 1;
        // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
        INFO = new int[capacity+1]; // A list that contains Data of Linked List
        LINK = new int[capacity+1]; // A list that contains address of next element
        size = 0; // Initially Linked List Size is Zero
        INFO[0] = INT_MIN;
        LINK[0] = 0;
        for(int i=1;i<=capacity;i++){
            // Example LINK[0] = 1 points to 1st index of INFO array
            LINK[i] = i+1; // Linking Link element value to the next index of INFO element
        }
    }

    // Member Functions

    // All function prototypes given below :-

    /* Insertion functions */
    void insertAtHead(int item);// Insertion at Beginning
    void insertAtEnd(int item);// Insertion at end
    void insertAfterIdx(int LOC,int item);// Insertion after specific Location
    void insertInSorted(int item);// Insertion of item in sorted Linked list
    /* General Functions */
    void print();// Printing of Linked list
    int count();// To count the total number of elements in the linked list
    int search(int item);// Searching an element by it's value
    int findLOC(int item);// Function to find Location for insertion in sorted linked list
    void findLOCandLOCP(int item,int &LOC,int &LOCP);// Finding the Location of deleted item i.e LOC and it's preceeding location LOCP
    /* Deletion Functions */
    int deleteAtHead();// Deletion at beginning
    int deleteAtEnd();// Deletion at end
    int deleteAfterIdx(int LOC,int LOCP);// Deletion following a given node
    void deleteItem(int item);// Deleting an item
};