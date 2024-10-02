// Linked List Implementation using three arrays without pointers
// Note INT_MIN is used as NULL
#include <iostream>
#include <climits>
using namespace std;

// All function prototypes given below made in this file :-

/* Insertion functions */
void insertAtHead(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START);// Insertion at Beginning
void insertAtEnd(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START);// Insertion at end
void insertAfterIdx(int LOC,int item,int INFO[],int LINK[],int size,int &AVAIL,int &START);// Insertion after specific Location
void insertInSorted(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START);// Insertion of item in sorted Linked list
/* General Functions */
void print(int INFO[],int LINK[],int START);// Printing of Linked list
int count(int INFO[],int LINK[],int START);// To count the total number of elements in the linked list
int search(int item,int INFO[],int LINK[],int START);// Searching an element by it's value
int findLOC(int item,int INFO[],int LINK[],int START);// Function to find Location for insertion in sorted linked list
void findLOCandLOCP(int INFO[],int LINK[],int &START,int item,int &LOC,int &LOCP);// Finding the Location of deleted item i.e LOC and it's preceeding location LOCP
/* Deletion Functions */
void deleteAtHead(int INFO[],int LINK[],int &START,int &AVAIL);// Deletion at beginning
void deleteAtEnd(int INFO[],int LINK[],int &START,int &AVAIL);// Deletion at end
void deleteAfterIdx(int INFO[],int LINK[],int &START,int &AVAIL,int LOC,int LOCP);// Deletion following a given node
void deleteItem(int INFO[],int LINK[],int &START,int &AVAIL,int item);// Deleting an item


// Insertion at Beginning

void insertAtHead(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START){
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


// Insertion at end

void insertAtEnd(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START){
    // Checking Overflow Condition
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = START; // Initialises Pointer
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    // Special Case
    if(PTR == INT_MIN){
        START = New;
        LINK[START] = INT_MIN;
        return;
    }
    // Attaching Node at end
    while(LINK[PTR] != INT_MIN){
        PTR = LINK[PTR]; // Updating pointer
    }
    // Linking Last Node to new node
    LINK[PTR] = New;
    // Set New Node pointer points to NULL
    LINK[New] = INT_MIN;
    return;
}


// Printing of Linked list

void print(int INFO[],int LINK[],int START){
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
    return;
}


// To count the total number of elements in the linked list

int count(int INFO[],int LINK[],int START){
    int size = 0; // Initialises Counter 
    int PTR = START; // Initalises pointer
    // Checking PTR == NULL
    while(PTR != INT_MIN){
        size++; // Incrementing Counter
        PTR = LINK[PTR];
    }
    return size;
}


// Searching an element by it's value

int search(int item,int INFO[],int LINK[],int START){
    int PTR = START; // Initialises Pointer
    // Checking PTR == NULL && INFO[PTR] = item
    while(PTR != INT_MIN && INFO[PTR] != item){ 
        PTR = LINK[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then INT_MIN value is returned
    return LOC;
}


// Insertion after specific Location

void insertAfterIdx(int LOC,int item,int INFO[],int LINK[],int size,int &AVAIL,int &START){
    if(LOC<0){
        cout<<"Negative Indexing not allowed\n";
        return;
    }
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    // Special Case
    if(LOC == INT_MAX){ // If LOC == NULL i.e INT_MAX here Insert At head
        insertAtHead(item,INFO,LINK,size,AVAIL,START); // Insert As First Node
        return;
    }
    // Remove first node from AVAIL List
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Upadating INFO array
    INFO[New] = item;
    // Inserting the node after specific Location
    LINK[New] = LINK[LOC];
    LINK[LOC] = New;
    return;
}


// Function findLOC And insertInSorted to create a sorted singly Linked List


// Function to find Location for insertion in sorted linked list

int findLOC(int item,int INFO[],int LINK[],int START){
    // List empty Condition
    if(START == INT_MIN){
        return INT_MAX;
    }
    // Special Case 
    if(item < INFO[START]){
        return INT_MAX;
    }
    // Initialises Pointer
    int LOC = START;
    int PTR = LINK[START];
    // Checking PTR != NULL
    while(PTR!=INT_MIN){ // INT_MIN is used as NULL
        if(item < INFO[PTR]){
            return LOC;
        }
        // Update Pointers
        LOC = PTR;
        PTR = LINK[PTR];
    }
    return LOC;
}

// Insertion of item in sorted Linked list

void insertInSorted(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START){
    // Find location where item < value of element of linked list
    int idx = findLOC(item,INFO,LINK,START);
    // Inserting item before the value whose value is just greater than item
    insertAfterIdx(idx,item,INFO,LINK,size,AVAIL,START);
    return;
}

// Deletion at beginning

void deleteAtHead(int INFO[],int LINK[],int &START,int &AVAIL){
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


// Deletion at end

void deleteAtEnd(int INFO[],int LINK[],int &START,int &AVAIL){
    if(START == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return;
    }
    int SAVE = START;
    int PTR = LINK[SAVE];
    // Special Case
    if(PTR == INT_MIN){ // Checking PTR == NULL
        deleteAtHead(INFO,LINK,START,AVAIL);
        return;
    }
    // Repeat Step 204 until PTR == NULL
    while(LINK[PTR] != INT_MIN){ // Checking PTR == NULL
        SAVE = PTR;
        PTR = LINK[PTR];
    }
    // Removing the last node
    LINK[SAVE] = INT_MIN;
    // Updating the AVAIL List
    LINK[PTR] = AVAIL;
    AVAIL = PTR;
    return;
}


// Deletion following a given node

void deleteAfterIdx(int INFO[],int LINK[],int &START,int &AVAIL,int LOC,int LOCP){
    // Node at LOC is required to be deleted
    // LOCP means the preceeding node of the node at LOC which is to be deleted
    if(LOC == -1 && LOCP == -1){
        cout<<"Item does not exist in list"<<endl;
        return;
    }
    if(LOC == INT_MIN){ // Checking LOC == NULL
        cout<<"Underflow error\n";
        return;
    }
    else{ 
        // Checking LOCP == NULL
        if(LOCP == INT_MIN){ // Deleting the first node
            // Removing the first Node of Linked List
            deleteAtHead(INFO,LINK,START,AVAIL);
            return;
        }
        else{
            LINK[LOCP] = LINK[LOC];
        }
        // Updating the AVAIL List
        LINK[LOC] = AVAIL;
        AVAIL = LOC;
        return;
    }
}

// Deletion when value of item is given 

// Finding the Location of deleted item i.e LOC and it's preceeding location LOCP

void findLOCandLOCP(int INFO[],int LINK[],int &START,int item,int &LOC,int &LOCP){
    if(START == INT_MIN){ // Checking START == NULL
        LOC == INT_MIN;
        return;
    }
    if(INFO[START] == item){
        LOC = START;
        LOCP = INT_MIN;
        return;
    }
    int SAVE = START; // Initialised pointer for LOCP
    int PTR = LINK[START]; // Initialised pointer for LOC
    while(LINK[PTR] != INT_MIN){ // Checking upto Last Node 
        if(INFO[PTR] == item){
            LOCP = SAVE;
            LOC = PTR;
            return;
        }
        // Updates Pointer
        SAVE = PTR;
        PTR = LINK[PTR];
    }
    return;
}

// Deleting an item

void deleteItem(int INFO[],int LINK[],int &START,int &AVAIL,int item){
    int LOC = -1;
    int LOCP = -1;
    findLOCandLOCP(INFO,LINK,START,item,LOC,LOCP);
    deleteAfterIdx(INFO,LINK,START,AVAIL,LOC,LOCP);
    return;
}