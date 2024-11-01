// Ascending Priority Queue Implementation using three arrays without pointers
// Note INT_MIN is used as NULL
/* !! Don't Edit the code in this file otherwise program will malfunction !! */
#include <iostream>
#include <climits>
using namespace std;

// All function prototypes given below made in this file :-

void pop(string INFO[],int LINK[],int &START,int &AVAIL);
void print(string INFO[],int LINK[],int START);
int count(int LINK[],int START);
void insertAfterIdx(int LOC,string item,int prioNumber,string INFO[],int LINK[],int PRN[],int size,int &AVAIL,int &START);
int findLOC(int prioNumber,string INFO[],int LINK[],int PRN[],int START);
void push(string item,int prioNumber,string INFO[],int LINK[],int PRN[],int size,int &AVAIL,int &START);
string front(int START,string INFO[]);
string rear(int START,string INFO[],int LINK[]);
bool isEmpty(int START);
bool isFull(int LINK[],int START,int size);


// Printing of Priority Queue

void print(string INFO[],int LINK[],int START){
    // Checking Underflow Condition
    if(START == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = START; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != INT_MIN){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    cout<<endl;
    return;
}


// To count the total number of elements in the priority queue

int count(int LINK[],int START){
    int size = 0; // Initialises Counter 
    int PTR = START; // Initalises pointer
    // Checking PTR == NULL
    while(PTR != INT_MIN){
        size++; // Incrementing Counter
        PTR = LINK[PTR];
    }
    return size;
}


// Insertion after specific Location

void insertAfterIdx(int LOC,string item,int prioNumber,string INFO[],int LINK[],int PRN[],int size,int &AVAIL,int &START){
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    // Remove first node from AVAIL List
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Special Case
    if(LOC == INT_MIN){ // If LOC == NULL i.e INT_MIN here
        // Attaching Node at beginning 
        INFO[New] = item; // Insertion of item
        LINK[New] = START; // Linking of New to START
        PRN[New] = prioNumber;
        START = New; // Update START
        return;
    }
    // Upadating INFO array and PRN Array
    INFO[New] = item;
    PRN[New] = prioNumber;
    // Inserting the node after specific Location
    LINK[New] = LINK[LOC];
    LINK[LOC] = New;
    return;
}

// Function to find Location for insertion in priority queue

int findLOC(int prioNumber,string INFO[],int LINK[],int PRN[],int START){
    // List empty Condition
    if(START == INT_MIN){
        return INT_MIN;
    }
    // Special Case 
    if(prioNumber < PRN[START]){
        return INT_MIN;
    }
    // Initialises Pointer
    int LOC = START;
    int PTR = LINK[START];
    // Checking PTR != NULL
    while(PTR!=INT_MIN){ // INT_MIN is used as NULL
        if(prioNumber < PRN[PTR]){
            return LOC;
        }
        // Update Pointers
        LOC = PTR;
        PTR = LINK[PTR];
    }
    return LOC;
}


// Insertion of item in Priority Queue

void push(string item,int prioNumber,string INFO[],int LINK[],int PRN[],int size,int &AVAIL,int &START){
    // Find location where item < value of element of linked list
    int idx = findLOC(prioNumber,INFO,LINK,PRN,START);
    // Inserting item before the value whose value is just greater than item
    insertAfterIdx(idx,item,prioNumber,INFO,LINK,PRN,size,AVAIL,START);
    return;
}


// Deletion at beginning

void pop(string INFO[],int LINK[],int &START,int &AVAIL){
    if(START == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return;
    }
    int New = START;
    // Removing first node
    START = LINK[START];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    return;
}


// Return the front element of priority queue

string front(int START,string INFO[]){
    // Checking underflow condition
    if(START == INT_MIN){ // START == NULL
        cout<<"Underflow error\n";
        return "";
    }
    return INFO[START];
}


// Return the last element of priority queue

string rear(int START,string INFO[],int LINK[]){
    // Checking underflow condition
    if(START == INT_MIN){ // START == NULL
        cout<<"Underflow error\n";
        return "";
    }
    int PTR = START; // Initialises Pointer
    while(LINK[PTR] != INT_MIN){ // Getting the Last element of Priority Queue
        PTR = LINK[PTR]; // Updating Pointer
    }
    return INFO[PTR];
}


// Checking emptyness of Priority Queue

bool isEmpty(int START){
    return (START == INT_MIN); // START == NULL
}


// Checking Priority Queue is full or not

bool isFull(int LINK[],int START,int size){
    int currSize = count(LINK,START); // Return the value of current size
    return (size == currSize);
}