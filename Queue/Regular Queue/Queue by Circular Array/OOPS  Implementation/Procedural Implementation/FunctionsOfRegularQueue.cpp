// Regular Queue Implementation using circular array without pointers
// Note -1 is used as NULL
/* !! Don't Edit the code in this file otherwise program will malfunction !! */
#include <iostream>
using namespace std;

// All function prototypes given below made in this file :-

void push(int item,int &FRONT,int &REAR,int size,int queue[]); // Push function for insertion at end of Regular Queue
int pop(int &FRONT,int &REAR,int size,int queue[]); // Pop Function for deletion at front end of Regular Queue and return the deleted item
int front(int FRONT,int queue[]); // Front function to display rear element of Regular Queue
int rear(int REAR,int queue[]); // Rear function to display rear element of Regular Queue
bool isEmpty(int FRONT); // Check emptyness of Regular Queue
bool isFull(int FRONT,int REAR,int size); // Check Regular Queue is full
int currSize(int FRONT,int REAR,int size); // Checking the current size of the queue
void print(int FRONT,int REAR,int size,int queue[]); // Display all elements of Regular Queue from front to rear


// Insertion at end

void push(int item,int &FRONT,int &REAR,int size,int queue[]){
    // Checking Overflow Condition
    if(size == 0){
        cout<<"Overflow error\n";
        return;
    }
    // Checking Overflow Condition
    else if((FRONT == 0 && REAR == size-1) || (FRONT == REAR+1)){
        cout<<"Overflow error\n";
        return;
    }
    else if(FRONT == -1){ // FRONT == NULL
        FRONT = 0;
        REAR = 0;
    }
    else if(REAR == size-1){ // Last index of array is filled 
        REAR = 0; // Initialises REAR to 0 as array is circular
    }
    else{
        REAR = REAR + 1;
    }
    // Inserting item in the queue
    queue[REAR] = item;
    return;
}


// Return the front element

int front(int FRONT,int queue[]){
    if(FRONT == -1){ // Checking FRONT == NULL
        cout<<"Underflow error\n";
        return -1;
    }
    return queue[FRONT];
}


// Return the rear element

int rear(int REAR,int queue[]){
    if(REAR == -1){ // Checking REAR == NULL
        cout<<"Underflow error\n";
        return -1;
    }
    return queue[REAR];
}


// Deletion at front end of queue

int pop(int &FRONT,int &REAR,int size,int queue[]){
    if(FRONT == -1){
        cout<<"Underflow error\n";
        return -1;
    }
    int front = queue[FRONT];
    if(FRONT == REAR){
        FRONT = -1;
        REAR = -1;
    }
    else if(FRONT < size-1){
        FRONT = FRONT + 1;
    }
    else{
        FRONT = 0;
    }
    return front;
}


// Checking the current size of the queue

int currSize(int FRONT,int REAR,int size){
    // Checking Queue is empty
    if(FRONT == -1){ // Checking FRONT == NULL
        return 0;
    }
    else if(FRONT == REAR){ // If Queue contains single element only
        return 1;
    } 
    else if(FRONT < REAR){ // If array is not currently is circular state
        return (REAR - FRONT + 1);
    }
    else{ // REAR > FRONT 
        return (size - FRONT + REAR +1); // If array is not currently is circular state 
    }
    return -1;
}


// Checking if Queue is empty

bool isEmpty(int FRONT){
    return (FRONT == -1); // Checking FRONT == NULL
}


// Checking if Queue is full

bool isFull(int FRONT,int REAR,int size){
    int Size = currSize(FRONT,REAR,size); // Size is the current size
    return (size == Size); // size is the Maximum size of array
}

// Printing elements of queue

void print(int FRONT,int REAR,int size,int queue[]){
    // Checking Underflow condition
    if(FRONT == -1){ // Checking FRONT == NULL
        cout<<"Underflow error\n";
        return;
    }
    int PTR = FRONT; // Initialises counter
    while(PTR != REAR+1){
        if(PTR == size-1){ // If PTR reaches end of the array
            if(REAR == PTR){
                cout<<queue[PTR]<<"\n";
                return;
            }
            cout<<queue[PTR]<<" ";
            PTR = 0; // Set PTR = 0 as array is circular
        }
        else{
            cout<<queue[PTR]<<' ';
            PTR += 1;
        }
    }
    cout<<endl;
    return;
}