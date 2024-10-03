// Note :- INT_MIN is used as NULL

#include <iostream>
#include <climits>
using namespace std;

// All function prototypes given below made in this file :-

/* Insertion functions */
void insertAtHead(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST, int &LAST);// Insertion at Beginning
void insertAtEnd(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST, int &LAST);// Insertion at end
void insertAfterIdx(int LOC,int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST,int &LAST);// Insertion after specific Location
void insertInSorted(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST,int &LAST);// Insertion of item in sorted Linked list
/* General Functions */
void print(int INFO[],int FORW[],int FIRST);// Printing of Linked list
void printReverse(int INFO[],int BACK[],int LAST);// Printing of Linked list in reverse order
int count(int INFO[],int FORW[],int FIRST);// To count the total number of elements in the linked list
int search(int item,int INFO[],int FORW[],int FIRST);// Searching an element by it's value
int searchFromBack(int item,int INFO[],int BACK[],int LAST);// Searching an element by it's value from back
/* Deletion Functions */
void deleteAtHead(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL);// Deletion at beginning
void deleteAtEnd(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL);// Deletion at end
void deleteAfterIdx(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL,int LOC,int LOCP);// Deletion following a given node
void deleteItem(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL,int size,int item);// Deleting an item


//Insertion at Beginning 

void insertAtHead(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST, int &LAST){
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    // Removing the First Node from AVAIL list
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Insertion of new node at beginning
    INFO[New] = item;
    // Checking DLL is empty
    if(FIRST == INT_MIN){ 
        FIRST = New;
        LAST = New;
        BACK[FIRST] = INT_MIN;
        FORW[FIRST] = INT_MIN;
    }
    else{
        FORW[New] = FIRST;
        BACK[FIRST] = New;
        FIRST = New;
        BACK[FIRST] = INT_MIN;
    }
    return;
}


// Insertion at end

void insertAtEnd(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST, int &LAST){
    // Checking Overflow Condition
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    // Checking DLL is empty
    if(FIRST == INT_MIN){
        insertAtHead(item,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
        return;
    }
    // Removing the First Node from AVAIL list
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Inserting New Node at end
    INFO[New] = item;
    FORW[LAST] = New;
    BACK[New] = LAST;
    LAST = New;
    FORW[LAST] = INT_MIN;
    return;
}


// Insertion after specific Location

void insertAfterIdx(int LOC,int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST,int &LAST){
    // Checking Overflow condition
    if(AVAIL >= size){
        cout<<"Overflow error\n";
    }
    // Insertion At First Location i.e LOC == INT_MIN
    else if(LOC == INT_MIN){
        insertAtHead(item,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    }
    // Insertion at Last location i.e LOC == LAST
    else if(LOC == LAST){
        insertAtEnd(item,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    }
    //Insertion at the wrong location
    else if(LOC>size){
        cout<<"Insertion not possible at "<<LOC<<"\n";
        cout<<"Index out of bound error here\n";
    }
    else if(LOC < 0){
        cout<<"Invalid index entered , negative indexing not allowed \n";
    }
    else{
        // Removing the First Node from AVAIL list
        int New = AVAIL;
        AVAIL = FORW[AVAIL];
        INFO[New] = item;
        // Inserting the item at Required Location
        FORW[New] = FORW[LOC];
        BACK[FORW[LOC]] = New;
        BACK[New] = LOC;
        FORW[LOC] = New;
    }
    return;
}


// Insertion in sorted manner

void insertInSorted(int item,int INFO[],int FORW[],int BACK[],int size,int &AVAIL,int &FIRST,int &LAST){
    // Special Case
    if(FIRST == INT_MIN || item < INFO[FIRST]){
        insertAfterIdx(INT_MIN,item,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
        return;
    }
    int LOC = FIRST;
    int PTR = FORW[FIRST]; // Initialises Pointer
    while(PTR != INT_MIN){ // Checking PTR == LAST
        if(item < INFO[PTR]){
            break;
        }
        LOC = PTR;
        PTR = FORW[PTR]; // Updating Pointer
    }
    insertAfterIdx(LOC,item,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    return;
}


// Printing of the LL

// Printing in actual order
void print(int INFO[],int FORW[],int FIRST){
    // Checking Underflow error
    if(FIRST == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = FIRST; // Initialises Pointer
    while(PTR != INT_MIN){
        cout<<INFO[PTR]<<" ";
        PTR = FORW[PTR]; // Updates Pointer
    }
    return;
}

// Printing in reverse order
void printReverse(int INFO[],int BACK[],int LAST){
    // Checking Underflow condition
    if(LAST == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = LAST;
    while(PTR != INT_MIN){
        cout<<INFO[PTR]<<" ";
        PTR = BACK[PTR]; // Updates Pointer
    }
    return;
}


// To count the current size of the DLL

int count(int INFO[],int FORW[],int FIRST){
    int c = 0; // Initialises Counter
    int PTR = FIRST; // Initialises Pointer
    while(PTR != INT_MIN){ // Checking PTR == NULL
        c++; // Increasing counter by 1
        PTR = FORW[PTR];
    }
    return c;
}


// Searching an element by it's value

int search(int item,int INFO[],int FORW[],int FIRST){
    int PTR = FIRST; // Initialises Pointer
    while(PTR != INT_MIN){ // Checking PTR == NULL
        if(INFO[PTR]==item){
            return PTR;
        }
        PTR = FORW[PTR]; // Updates Pointer
    }
    // If search is unsuccessful INT_MIN Vlaue is returned
    return PTR;
}


// Searching an element by it's value from Back side of DLL

int searchFromBack(int item,int INFO[],int BACK[],int LAST){
    int PTR = LAST; // Initialises Pointer
    while(PTR != INT_MIN){ // Checking PTR == NULL
        if(INFO[PTR]==item){
            return PTR;
        }
        PTR = BACK[PTR]; // Updates Pointer
    }
    // If search is unsuccessful INT_MIN Vlaue is returned
    return PTR;
}


// Deletion at beginning

void deleteAtHead(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL){
    // Checking Underflow Error
    if(FIRST == INT_MIN){ // Checking FIRST == NULL
        cout<<"Underflow error\n";
        return;
    }
    // Special Case
    if(FIRST == LAST){ // DLL has only one node
        // Updating the AVAIL List
        FORW[FIRST] = AVAIL;
        AVAIL = FIRST;
        // Removing the first Node
        FIRST = INT_MIN;
        LAST = INT_MIN;
        return;
    }
    int New = FIRST;
    // Removing the FIRST node
    FIRST = FORW[FIRST];
    BACK[FIRST] = INT_MIN;
    // Updating AVAIL List
    FORW[New] = AVAIL;
    AVAIL = New;
    return;
}


// Deletion at end

void deleteAtEnd(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL){
    // Checking Underflow Error
    if(FIRST == INT_MIN){ // Checking FIRST == NULL
        cout<<"Underflow error\n";
        return;
    }
    // Special Case
    if(FIRST == LAST){ // DLL has only one node
        deleteAtHead(INFO,FORW,BACK,FIRST,LAST,AVAIL);
        return;
    }
    int New = LAST;
    // Removing the LAST node
    LAST = BACK[LAST];
    FORW[LAST] = INT_MIN;
    // Updating AVAIL List
    FORW[New] = AVAIL;
    AVAIL = New;
    return;
}


// Deletion following a given node
void deleteAfterIdx(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL,int size,int LOC){
    // Checking Underflow error
    if(FIRST == INT_MIN){
        cout<<"Underflow error\n";
    }
    // Deletion of the first node
    else if(LOC == INT_MIN){
        deleteAtHead(INFO,FORW,BACK,FIRST,LAST,AVAIL);
    }
    // Deletion of the Node that does not exist
    else if(LOC == LAST || LOC<0 || LOC>=size){
        cout<<"Node does not exist\n";
    }
    // Deletion of the Last Node
    else if(FORW[LOC] == LAST){
        deleteAtEnd(INFO,FORW,BACK,FIRST,LAST,AVAIL);
    }
    // Deletion of the required node
    else{
        int New = FORW[LOC];
        FORW[LOC] = FORW[New];
        BACK[New] = LOC;
        // Updating the AVAIL List
        FORW[New] = AVAIL;
        AVAIL = New;
    }
    return;
}


// Deleting an item

void deleteItem(int INFO[],int FORW[],int BACK[],int &FIRST,int &LAST,int &AVAIL,int size,int item){
    // Location at which item is located is LOCA
    int LOCA = search(item,INFO,FORW,FIRST);
    if(LOCA == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    // DeleteAfterIdx function require address of the previous node of the node to be deleted i.e LOC
    int LOC = BACK[LOCA];
    deleteAfterIdx(INFO,FORW,BACK,FIRST,LAST,AVAIL,size,LOC);
    return;
}