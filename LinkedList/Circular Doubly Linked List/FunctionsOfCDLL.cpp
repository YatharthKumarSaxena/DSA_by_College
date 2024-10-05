// Circular Doubly Linked List Implementation using three arrays without pointers
#include <iostream>
using namespace std;

// All function prototypes given below made in this file :-

/* Insertion functions */
void insertAtHead(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int START,int &currSize);// Insertion at Beginning
void insertAtEnd(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int START,int &currSize);// Insertion at end
void insertAfterIdx(int LOC,int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int START,int &currSize);// Insertion after specific Location
void insertInSorted(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &START,int &currSize);// Insertion of item in sorted Linked list
/* General Functions */
void print(int INFO[],int FORW[],int START);// Printing of Linked list
void printReverse(int INFO[],int BACK[],int START);// Printing of Linked list
int search(int item,int INFO[],int FORW[],int START);// Searching an element by it's value
int searchFromBack(int item,int INFO[],int BACK[],int START);// Searching an element by it's value
/* Deletion Functions */
void deleteAtHead(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int &currSize);// Deletion at beginning
void deleteAtEnd(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int &currSize);// Deletion at end
void deleteAfterIdx(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int LOC,int &currSize);// Deletion following a given node
void deleteItem(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int item,int &currSize);// Deleting an item


// Insertion at Beginning

void insertAtHead(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int START,int &currSize){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL > size){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = FORW[AVAIL];
    // Attaching Node at beginning 
    INFO[New] = item; // Insertion of item
    if(currSize == 0){
        FORW[START] = New;
        BACK[START] = New;
        BACK[New] = START;
        FORW[New] = START;
    }
    else{
        int help = FORW[START];
        FORW[START] = New;
        BACK[New] = START;
        FORW[New] = help;
        BACK[help] = New;
    }
    currSize++;
    return;
}


// Insertion at end

void insertAtEnd(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int START,int &currSize){
    // Checking Overflow Condition
    if(AVAIL > size){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = FORW[START]; // Initialises Pointer
    // Special Case
    if(PTR == START){ // Circular LL is empty
        insertAtHead(item,INFO,FORW,BACK,size,AVAIL,START,currSize);
        return;
    }
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    // Attaching Node at end
    PTR = BACK[START];
    // Linking Last Node to new node
    FORW[PTR] = New;
    BACK[New] = PTR;
    // Set New Node pointer points to NULL
    FORW[New] = START;
    BACK[START] = New;
    currSize++; // Increasing the size
    return;
}


// Printing of Linked list

void print(int INFO[],int FORW[],int START){
    // Checking Underflow Condition
    if(FORW[START] == START){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = FORW[START]; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != START){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = FORW[PTR]; // Update Pointer
    }
    return;
}

void printReverse(int INFO[],int BACK[],int START){
    int PTR = BACK[START];
    if(PTR == START){
        cout<<"Underflow error\n";
        return;
    }
    while(PTR != START){
        cout<<INFO[PTR]<<" ";
        PTR = BACK[PTR]; // Updates Pointer
    }
    return;
}

// Searching an element by its value

int search(int item,int INFO[],int FORW[],int START){
    int PTR = FORW[START]; // Initialises Pointer
    // Checking PTR == START && INFO[PTR] == item
    while(PTR != START && INFO[PTR] != item){ 
        PTR = FORW[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then 0 value is returned
    return LOC;
}


// Searching an element by its value from back

int searchFromBack(int item,int INFO[],int BACK[],int START){
    int PTR = BACK[START]; // Initialises Pointer
    // Checking PTR == START && INFO[PTR] == item
    while(PTR != START && INFO[PTR] != item){ 
        PTR = BACK[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then 0 value is returned
    return LOC;
}


// Insertion after specific Location

void insertAfterIdx(int LOC,int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int START,int &currSize){
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
        insertAtHead(item,INFO,FORW,BACK,size,AVAIL,START,currSize); // Insert As First Node
        return;
    }
    // Remove first node from AVAIL List
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Upadating INFO array
    INFO[New] = item;
    // Inserting the node after specific Location
    FORW[New] = FORW[LOC];
    BACK[FORW[LOC]] = New;
    FORW[LOC] = New;
    BACK[New] = LOC;
    // Increasing the current size
    currSize++;
    return;
}


// Insertion of item in sorted Linked list

void insertInSorted(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &START,int &currSize){
    // Special Case
    if(FORW[START] == START  || item < INFO[START]){
        insertAfterIdx(START,item,INFO,FORW,BACK,size,AVAIL,START,currSize);;
        return;
    }
    int LOC = START;
    int PTR = FORW[START]; // Initialises Pointer
    while(PTR != START){ // Checking PTR == START
        if(item < INFO[PTR]){
            break;
        }
        LOC = PTR;
        PTR = FORW[PTR]; // Updating Pointer
    }
    insertAfterIdx(LOC,item,INFO,FORW,BACK,size,AVAIL,START,currSize);
    return;
}


// Deletion at beginning

void deleteAtHead(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int &currSize){
    if(FORW[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return;
    }
    int New = FORW[START];
    // Removing first node
    FORW[START] = FORW[New];
    BACK[FORW[New]] = START;
    // Updating AVAIL List
    FORW[New] = AVAIL;
    AVAIL = New;
    // Decreasing the current size
    currSize--;
    return;
}


// Deletion at end

void deleteAtEnd(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int &currSize){
    if(FORW[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return;
    }
    // Initialises Pointers
    int SAVE = START;
    int PTR = FORW[START];
    // Special Case
    if(PTR == START){ // LL contain one element
        deleteAtHead(INFO,FORW,BACK,START,AVAIL,currSize);
        return;
    }
    while(FORW[PTR] != START){ // Checking PTR == START
        SAVE = PTR;
        PTR = FORW[PTR];
    }
    // Removing the last node
    FORW[SAVE] = START;
    BACK[START] = SAVE;
    // Updating the AVAIL List
    FORW[PTR] = AVAIL;
    AVAIL = PTR;
    // Decreasing the current size
    currSize--;
    return;
}


// Deletion when value of item is given 


// Deletion following a given node
void deleteAfterIdx(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int LOC,int &currSize){
    // Node at LOC is required to be deleted
    // LOCP means the preceeding node of the node at LOC which is to be deleted
    if(LOC == 0 && currSize != 0){
        cout<<"Item does not exist in list "<<endl;
        return;
    }
    if(LOC == 0 ){
        cout<<"Underflow error\n"<<endl;
        return;
    }
    else{ 
        int LOCP = BACK[LOC];
        // Checking LOCP == NULL
        if(LOCP == START){ // Deleting the first node
            // Removing the first Node of Linked List
            deleteAtHead(INFO,FORW,BACK,START,AVAIL,currSize);
            return;
        }
        else{
            FORW[LOCP] = FORW[LOC];
            BACK[FORW[LOC]] = LOCP;
        }
        // Updating the AVAIL List
        FORW[LOC] = AVAIL;
        AVAIL = LOC;
        // Decreasing the current size
        currSize--;
        return;
    }
}


// Deleting an item
void deleteItem(int INFO[],int FORW[],int BACK[],int START,int &AVAIL,int item,int &currSize){
    int LOC = search(item,INFO,FORW,START);
    deleteAfterIdx(INFO,FORW,BACK,START,AVAIL,LOC,currSize);
    return;
}
