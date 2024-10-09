// Regular Queue Implementation using two arrays without pointers
// Note INT_MIN is used as NULL
/* !! Don't Edit the below code otherwise program will malfunction !! */
#include <iostream>
#include <climits>
using namespace std;

// All function prototypes given below made in this file :-

/* Insertion functions */
void push(int item,int INFO[],int LINK[],int size,int &AVAIL,int &FRONT,int &REAR);// Insertion at Rear End
/* General Functions */
void print(int INFO[],int LINK[],int FRONT);// Printing of Regular Queue
int count(int INFO[],int LINK[],int FRONT);// To count the total number of elements in the regular queue
bool isEmpty(int FRONT); // Checking Emptyness of Regular Queue
bool isFull(int INFO[],int LINK[],int FRONT,int size); // Checking Regular Queue is full
int rear(int INFO[],int REAR); // Return rear element of regular queue
int front(int INFO[],int FRONT); // Return front element of regular queue
/* Deletion Functions */
void pop(int INFO[],int LINK[],int &FRONT,int &REAR,int &AVAIL);// Deletion at front


// Insertion at Rear end of Regular Queue (Push Function)

void push(int item,int INFO[],int LINK[],int size,int &AVAIL,int &FRONT,int &REAR){
    // Checking Overflow Condition
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = FRONT; // Initialises Pointer
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    // Special Case
    if(PTR == INT_MIN){
        FRONT = New;
        REAR = New;
        LINK[FRONT] = INT_MIN;
        return;
    }
    // Attaching Node at end
    LINK[REAR] = New;
    // Linking Last Node to new node
    REAR = New;
    // Set New Node pointer points to NULL
    LINK[REAR] = INT_MIN;
    return;
}


// Printing of Linked list

void print(int INFO[],int LINK[],int FRONT){
    // Checking Underflow Condition
    if(FRONT == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = FRONT; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != INT_MIN){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    return;
}


// To count the total number of elements in the linked list

int count(int INFO[],int LINK[],int FRONT){
    int size = 0; // Initialises Counter 
    int PTR = FRONT; // Initalises pointer
    // Checking PTR == NULL
    while(PTR != INT_MIN){
        size++; // Incrementing Counter
        PTR = LINK[PTR];
    }
    return size;
}


// Checking Emptyness of Regular Queue

bool isEmpty(int FRONT){
    return (FRONT == INT_MIN); // i.e FRONT == NULL
}


// Checking Regular Queue is full

bool isFull(int INFO[],int LINK[],int FRONT,int size){
    int currSize = count(INFO,LINK,FRONT); // Current size of regular queue
    return (currSize == size);
}


// Return rear element of regular queue

int rear(int INFO[],int REAR){
    if(REAR == INT_MIN){ // Checking Underflow condition
        cout<<"Underflow Error\n";
        return -1;
    }
    return INFO[REAR];
}


// Return front element of regular queue

int front(int INFO[],int FRONT){
    if(FRONT == INT_MIN){ // Checking Underflow condition
        cout<<"Underflow Error\n";
        return -1;
    }
    return INFO[FRONT];
} 

// Deletion at front

void pop(int INFO[],int LINK[],int &FRONT,int &REAR,int &AVAIL){
    if(FRONT == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return;
    }
    // Special Case
    if(FRONT == REAR){ // Regular Queue Contains only one element
        FRONT = INT_MIN; // FRONT = NULL
        REAR = INT_MIN; // REAR = NULL
        return;
    }
    int New = FRONT;
    // Removing first node
    FRONT = LINK[FRONT];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    return;
}