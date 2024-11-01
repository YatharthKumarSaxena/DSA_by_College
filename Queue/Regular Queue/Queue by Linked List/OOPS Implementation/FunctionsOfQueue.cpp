#include "QueueClass.cpp"

// Insertion at Rear end of Regular Queue (Push Function)

void Queue::push(int item){
    // Checking Overflow Condition
    if(AVAIL >= capacity){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = FRONT; // Initialises Pointer
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    size++;
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

void Queue::print(){
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
    cout<<endl;
    return;
}


// To count the total number of elements in the linked list

int Queue::count(){
    return size;
}


// Checking Emptyness of Regular Queue

bool Queue::isEmpty(){
    return (FRONT == INT_MIN); // i.e FRONT == NULL
}


// Checking Regular Queue is full

bool Queue::isFull(){
    int currSize = count(); // Current size of regular queue
    return (currSize == capacity);
}


// Return rear element of regular queue

int Queue::rear(){
    if(REAR == INT_MIN){ // Checking Underflow condition
        cout<<"Underflow Error\n";
        return -1;
    }
    return INFO[REAR];
}


// Return front element of regular queue

int Queue::front(){
    if(FRONT == INT_MIN){ // Checking Underflow condition
        cout<<"Underflow Error\n";
        return -1;
    }
    return INFO[FRONT];
} 

// Deletion at front

int Queue::pop(){
    if(FRONT == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    size--;
    // Special Case
    if(FRONT == REAR){ // Regular Queue Contains only one element
        int val = FRONT;
        FRONT = INT_MIN; // FRONT = NULL
        REAR = INT_MIN; // REAR = NULL
        return INFO[val];
    }
    int New = FRONT;
    // Removing first node
    FRONT = LINK[FRONT];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    return INFO[New];
}