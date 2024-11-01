// Stack Implementation using two arrays without pointers
// Note INT_MIN is used as NULL
#include <iostream>
#include <climits>
using namespace std;

// All function prototypes given below made in this file :-

void push(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START); // Push function for insertion
int pop(int INFO[],int LINK[],int &START,int &AVAIL); // Pop Function for deletion and return the deleted item
int top(int INFO[],int START); // Top Function to Display of top element of stack
bool isEmpty(int START); // Check emptyness of list
bool isFull(int AVAIL,int size); // Check list is full
void print(int INFO[],int LINK[],int START); // Display all elements of stack from top to bottom


// Push Function

void push(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = LINK[AVAIL];
    // Attaching Node at beginning 
    INFO[New] = item; // Insertion of item
    LINK[New] = START; // Linking of New to START
    START = New; // Update START
    return;
}


// Pop Function

int pop(int INFO[],int LINK[],int &START,int &AVAIL){
    if(START == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    int New = START;
    // Removing first node
    START = LINK[START];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    return INFO[New];
}


// Printing of Stack elements from top to bottom

void print(int INFO[],int LINK[],int START){
    // Checking Underflow Condition
    if(START == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return;
    }
    cout<<"Your Stack from top to bottom looks like :- ";
    int PTR = START; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != INT_MIN){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    cout<<endl;
    return;
}


// Top Function for returning top element of stack

int top(int INFO[],int START){
    // Checking Underflow condition
    if(START == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    return INFO[START]; // Returning the Top element
}


// Checking stack is empty

bool isEmpty(int START){
    return (START == INT_MIN); // START == NULL
}


// Checking Stack is full

bool isFull(int AVAIL,int size){
    return (AVAIL >= size);
}
