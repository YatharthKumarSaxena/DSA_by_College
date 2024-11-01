#include "StackClass.cpp"

// Push Function

void Stack::push(int item){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL >= capacity){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = LINK[AVAIL];
    // Attaching Node at beginning 
    INFO[New] = item; // Insertion of item
    LINK[New] = Top; // Linking of New to START
    Top = New; // Update START
    size++;
    return;
}


// Pop Function

int Stack::pop(){
    if(Top == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    int New = Top;
    // Removing first node
    Top = LINK[Top];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    size--;
    return INFO[New];
}


// Printing of Stack elements from top to bottom

void Stack::print(){
    // Checking Underflow Condition
    if(Top == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return;
    }
    cout<<"Your Stack from top to bottom looks like :- ";
    int PTR = Top; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != INT_MIN){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    cout<<endl;
    return;
}


// Top Function for returning top element of stack

int Stack::top(){
    // Checking Underflow condition
    if(Top == INT_MIN){ // Checking START == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    return INFO[Top]; // Returning the Top element
}


// Checking stack is empty

bool Stack::isEmpty(){
    return (Top == INT_MIN); // START == NULL
}


// Checking Stack is full

bool Stack::isFull(){
    return (AVAIL >= capacity);
}
