#include <iostream>
#include <climits>
using namespace std;

class Stack{

    // Data Member
    int Top; // Stores Address of Top element of Stack
    int* INFO;
    int* LINK;
    int AVAIL; // AVAIL Pointer
    int size; // Stores Current size of the Stack
    int capacity; // Maximum size of your Stack

public:

    // Parameterized Constructor
    Stack(int capacity){
        this->capacity = capacity;
        AVAIL = 0; 
        size = 0;
        Top = INT_MIN; // Top pointer of Stack currently points to NULL
        // Array of unused memory cells let say AVAIL Stack consist of INFO part and LINK part
        INFO = new int[capacity]; // A list that contains Data of Stack
        LINK = new int[capacity]; // A list that contains address of bottom element of Stack
        for(int i=0;i<capacity;i++){
            // Example LINK[0] = 1 points to 1st index of INFO array
            LINK[i] = i+1; // Linking Link element value to the next index of INFO element
        }
    }

    // Member Functions

    // All function prototypes given below made in this file :-
    void push(int item); // Push function for insertion
    int pop(); // Pop Function for deletion and return the deleted item
    int top(); // Top Function to Display of top element of stack
    bool isEmpty(); // Check emptyness of list
    bool isFull(); // Check list is full
    void print(); // Display all elements of stack from top to bottom

    // Destructor
    ~Stack(){
        delete[] INFO;
        delete[] LINK;
    }
};