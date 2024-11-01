#include "..\PrioQueueClass.cpp"

// Printing of Priority Queue

void PrioQueue::print(){
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

int PrioQueue::count(){
    return size;
}


// Insertion after specific Location

void PrioQueue::insertAfterIdx(int LOC,string item,int prioNumber){
    if(AVAIL >= capacity){
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
        size++;
        return;
    }
    // Upadating INFO array and PRN Array
    INFO[New] = item;
    PRN[New] = prioNumber;
    // Inserting the node after specific Location
    LINK[New] = LINK[LOC];
    LINK[LOC] = New;
    size++; // Increasing the current size by 1
    return;
}

// Function to find Location for insertion in priority queue

int PrioQueue::findLOC(int prioNumber){
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

void PrioQueue::push(string item,int prioNumber){
    // Find location where item < value of element of linked list
    int idx = findLOC(prioNumber);
    // Inserting item before the value whose value is just greater than item
    insertAfterIdx(idx,item,prioNumber);
    return;
}


// Deletion at beginning

string PrioQueue::pop(){
    if(START == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return "";
    }
    int New = START;
    // Removing first node
    START = LINK[START];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    size--; // Decreasing the current size by 1
    return INFO[New];
}


// Return the front element of priority queue

string PrioQueue::front(){
    // Checking underflow condition
    if(START == INT_MIN){ // START == NULL
        cout<<"Underflow error\n";
        return "";
    }
    return INFO[START];
}


// Return the last element of priority queue

string PrioQueue::rear(){
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

bool PrioQueue::isEmpty(){
    return (START == INT_MIN); // START == NULL
}


// Checking Priority Queue is full or not

bool PrioQueue::isFull(){
    int currSize = count(); // Return the value of current size
    return (capacity == currSize);
}
