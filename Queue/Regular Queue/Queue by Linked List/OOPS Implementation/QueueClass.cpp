#include <iostream>
#include <climits>
using namespace std;

class Queue{

    // Data Member

    int* INFO;
    int* LINK;
    int AVAIL; // AVAIL Pointer
    int FRONT; 
    int REAR;
    int capacity; // Maximum Size of Regular Queue
    int size; // Current size of Regular Queue

public:

    // Parameterized Constructor

    Queue(int capacity){
        this->capacity = capacity;
        // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
        INFO = new int[capacity]; // A list that contains Data of Regular Queue
        LINK = new int[capacity];  // A list that contains address of next element
        AVAIL = 0; // AVAIL Pointer intitaially points to 0th Index of the Avail List
        FRONT = INT_MIN; // Front Pointer of Regular Queue currently points to NULL
        REAR = INT_MIN; // Rear Pointer of Regular Queue currently points to NULL
        size = 0; // Initially size of Regular Queue is 0
        for(int i=0;i<capacity;i++){
            // Example LINK[0] = 1 points to 1st index of INFO array
            LINK[i] = i+1; // Linking Link element value to the next index of INFO element
        }
    }

    // Member Functions

    // All function prototypes given below:-

    /* Insertion functions */
    void push(int item);// Insertion at Rear End
    /* General Functions */
    void print();// Printing of Regular Queue
    int count();// To count the total number of elements in the regular queue
    bool isEmpty(); // Checking Emptyness of Regular Queue
    bool isFull(); // Checking Regular Queue is full
    int rear(); // Return rear element of regular queue
    int front(); // Return front element of regular queue
    /* Deletion Functions */
    int pop();// Deletion at front

    // Destructor

    ~Queue(){
        delete[] INFO;
        delete[] LINK;
    }
};