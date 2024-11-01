#include <iostream>
#include <climits>
using namespace std;

class DoublyLinkedList{

    // Data Members

    int* INFO;
    int* FORW;
    int* BACK;
    int FIRST; // Head Pointer of DLL
    int LAST; // Tail Pointer of DLL
    int capacity; // Maximum size of your DLL
    int AVAIL; // AVAIL Pointer
    int size; // Stores the current size of the DLL

public:

    // Parameterized Constructor

    DoublyLinkedList(int capacity){
        this->capacity = capacity;
        INFO = new int[capacity]; // A list that contains Data of Linked List
        FORW = new int[capacity]; // A list that contains address of next element
        BACK = new int[capacity]; // A list that contains address of previous element
        FIRST = INT_MIN; // START Pointer initialised to NULL points to first element of DLL
        LAST = INT_MIN; // LAST Pointer initialised to NULL points to last element of DLL
        size = 0; // Initial Size of DLL is 0
        AVAIL = 0; // AVAIL Pointer
        for(int i=0;i<capacity;i++){
            // Example FORW[0] = 1 points to 1st index of INFO array
            FORW[i] = i+1; // Linking FORW element value to the next index of INFO element
            // Example BACK[1] = 0 points to 0th index of INFO array
            BACK[i] = i-1; // Linking BACK element value to the previous index of INFO element
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
    void printReverse();// Printing of Linked list in reverse order
    int count();// To count the total number of elements in the linked list
    int search(int item);// Searching an element by it's value
    int searchFromBack(int item);// Searching an element by it's value from back
    /* Deletion Functions */
    int deleteAtHead();// Deletion at beginning
    int deleteAtEnd();// Deletion at end
    int deleteAfterIdx(int& LOC,int& LOCP);// Deletion following a given node
    void deleteItem(int item);// Deleting an item
};
