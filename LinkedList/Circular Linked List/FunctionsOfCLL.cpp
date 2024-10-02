// Circular Linked List Implementation using three arrays without pointers
#include <iostream>
using namespace std;

// All function prototypes given below made in this file :-

/* Insertion functions */
void insertAtHead(int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize);// Insertion at Beginning
void insertAtEnd(int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize);// Insertion at end
void insertAfterIdx(int LOC,int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize);// Insertion after specific Location
void insertInSorted(int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize);// Insertion of item in sorted Linked list
/* General Functions */
void print(int INFO[],int LINK[],int START);// Printing of Linked list
int count(int INFO[],int LINK[],int START);// To count the total number of elements in the linked list
int search(int item,int INFO[],int LINK[],int START);// Searching an element by it's value
int findLOC(int item,int INFO[],int LINK[],int START);// Function to find Location for insertion in sorted linked list
void findLOCandLOCP(int INFO[],int LINK[],int &START,int item,int &LOC,int &LOCP);// Finding the Location of deleted item i.e LOC and it's preceeding location LOCP
/* Deletion Functions */
void deleteAtHead(int INFO[],int LINK[],int START,int &AVAIL,int &currSize);// Deletion at beginning
void deleteAtEnd(int INFO[],int LINK[],int START,int &AVAIL,int &currSize);// Deletion at end
void deleteAfterIdx(int INFO[],int LINK[],int START,int &AVAIL,int LOC,int LOCP,int &currSize);// Deletion following a given node
void deleteItem(int INFO[],int LINK[],int START,int &AVAIL,int item,int &currSize);// Deleting an item


// Insertion at Beginning

void insertAtHead(int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL > size+1){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = LINK[AVAIL];
    // Attaching Node at beginning 
    INFO[New] = item; // Insertion of item
    if(currSize == 0){
        LINK[START] = New;
        LINK[New] = START;
    }
    else{
        int help = LINK[START];
        LINK[START] = New;
        LINK[New] = help;
    }
    currSize++;
    return;
}


// Insertion at end

void insertAtEnd(int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize){
    // Checking Overflow Condition
    if(AVAIL > size+1){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = LINK[START]; // Initialises Pointer
    // Special Case
    if(PTR == START){ // Circular LL is empty
        insertAtHead(item,INFO,LINK,size,AVAIL,START,currSize);
        return;
    }
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    // Attaching Node at end
    while(LINK[PTR] != START){
        PTR = LINK[PTR]; // Updating pointer
    }
    // Linking Last Node to new node
    LINK[PTR] = New;
    // Set New Node pointer points to NULL
    LINK[New] = START;
    currSize++;
    return;
}


// Printing of Linked list

void print(int INFO[],int LINK[],int START){
    // Checking Underflow Condition
    if(LINK[START] == START){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = LINK[START]; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != START){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    return;
}

// Searching an element by it's value

int search(int item,int INFO[],int LINK[],int START){
    int PTR = LINK[START]; // Initialises Pointer
    // Checking PTR == NULL && INFO[PTR] = item
    while(PTR != START && INFO[PTR] != item){ 
        PTR = LINK[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then 0 value is returned
    return LOC;
}


// Insertion after specific Location

void insertAfterIdx(int LOC,int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize){
    if(LOC<0){
        cout<<"Negative Indexing not allowed\n";
        return;
    }
    if(AVAIL > size){
        cout<<"Overflow error\n";
        return;
    }
    // Special Case
    if(LOC == START){ // If LOC == NULL i.e Insert At head
        insertAtHead(item,INFO,LINK,size,AVAIL,START,currSize); // Insert As First Node
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
    currSize++;
    return;
}

// Function findLOC And insertInSorted to create a sorted singly Linked List


// Function to find Location for insertion in sorted linked list

int findLOC(int item,int INFO[],int LINK[],int START){
    // List empty Condition
    if(LINK[START] == START){
        return START;
    }
    // Initialises Pointer
    int LOC = START;
    int PTR = LINK[START];
    // Checking PTR != START
    while(PTR!=START){ 
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

void insertInSorted(int item,int INFO[],int LINK[],int size,int &AVAIL,int START,int &currSize){
    // Find location where item < value of element of linked list
    int idx = findLOC(item,INFO,LINK,START);
    // Inserting item before the value whose value is just greater than item
    insertAfterIdx(idx,item,INFO,LINK,size,AVAIL,START,currSize);
    return;
}


// Deletion at beginning

void deleteAtHead(int INFO[],int LINK[],int START,int &AVAIL,int &currSize){
    if(LINK[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return;
    }
    int New = LINK[START];
    // Removing first node
    LINK[START] = LINK[New];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    // Decreasing the current size
    currSize--;
    return;
}


// Deletion at end

void deleteAtEnd(int INFO[],int LINK[],int START,int &AVAIL,int &currSize){
    if(LINK[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return;
    }
    // Initialises Pointers
    int SAVE = START;
    int PTR = LINK[START];
    // Special Case
    if(PTR == START){ // LL contain one element
        deleteAtHead(INFO,LINK,START,AVAIL,currSize);
        return;
    }
    while(LINK[PTR] != START){ // Checking PTR == START
        SAVE = PTR;
        PTR = LINK[PTR];
    }
    // Removing the last node
    LINK[SAVE] = START;
    // Updating the AVAIL List
    LINK[PTR] = AVAIL;
    AVAIL = PTR;
    // Decreasing the current size
    currSize--;
    return;
}

// Deletion following a given node

void deleteAfterIdx(int INFO[],int LINK[],int START,int &AVAIL,int LOC,int LOCP,int &currSize){
    // Node at LOC is required to be deleted
    // LOCP means the preceeding node of the node at LOC which is to be deleted
    if(LOC == -1 && LOCP == -1){
        cout<<"Item does not exist in list"<<endl;
        return;
    }
    if(LOC == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return;
    }
    else{ 
        // Checking LOCP == NULL
        if(LOCP == START){ // Deleting the first node
            // Removing the first Node of Linked List
            deleteAtHead(INFO,LINK,START,AVAIL,currSize);
            return;
        }
        else{
            LINK[LOCP] = LINK[LOC];
        }
        // Updating the AVAIL List
        LINK[LOC] = AVAIL;
        AVAIL = LOC;
        // Decreasing the current size
        currSize--;
        return;
    }
}
// Deletion when value of item is given 

// Finding the Location of deleted item i.e LOC and it's preceeding location LOCP

void findLOCandLOCP(int INFO[],int LINK[],int START,int item,int &LOC,int &LOCP,int &currSize){
    if(LINK[START] == START){ // Checking Circular Linked List is empty
        LOC == START;
        return;
    }
    int PTR = LINK[START]; // Initialised Pointer for LOC
    if(INFO[PTR] == item){
        LOC = PTR;
        LOCP = START;
        return;
    }
    int SAVE = START; // Initialised pointer for LOCP
    while(PTR != START){ // Checking upto Last Node 
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

void deleteItem(int INFO[],int LINK[],int START,int &AVAIL,int item,int &currSize){
    int LOC = -1;
    int LOCP = -1;
    findLOCandLOCP(INFO,LINK,START,item,LOC,LOCP,currSize);
    deleteAfterIdx(INFO,LINK,START,AVAIL,LOC,LOCP,currSize);
    return;
}