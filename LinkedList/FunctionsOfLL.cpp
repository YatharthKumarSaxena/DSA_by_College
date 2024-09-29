#include "LL_Class_ArrayImplentation.cpp"

// Printing of Linked list
void LL::print(){
    // Checking Underflow Condition
    if(START == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = START; // Initialises pointer
    // Repeat Step 27 And 28 Until PTR == NULL
    while(PTR != INT_MIN){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    return;
}

// To count the total number of elements in the linked list
int LL::count(){
    int size = 0; // Initialises Counter 
    int PTR = START; // Initalises pointer
    // Repeat Step 40 and 41 until PTR == NULL
    while(PTR != INT_MIN){
        size++; // Incrementing Counter
        PTR = LINK[PTR];
    }
    return size;
}

// Searching an element in Linked List
int LL::search(int item){
    int PTR = START; // Initialises Pointer
    // Repeat Step 52 until PTR == NULL && INFO[PTR] = item
    while(PTR != INT_MIN && INFO[PTR] != item){ 
        PTR = LINK[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then INT_MIN value is returned
    return LOC;
}

// Insertion at Beginning
void LL::insertAtHead(int item){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = LINK[AVAIL];
    // Attaching Node at beginning 
    LINK[New] = START; // Linking of New to START
    START = New; // Update START
    INFO[New] = item; // Insertion of item
    return;
}
// Insertion at end
void LL::insertAtEnd(int item){
    // Checking Overflow Condition
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = START; // Initialises Pointer
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
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
    // Updating item in info array
    INFO[New] = item;
    return;
}