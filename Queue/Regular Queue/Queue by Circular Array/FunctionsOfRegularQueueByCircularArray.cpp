#include "Queue_Class.cpp"

// All Function Definition of Regular Queue Class 


//Insertion function at end

void Queue::push(int item){
    // Checking Overflow Condition
    if((size == 0) ||(*FRONT == 0 && *REAR == size-1) || (*FRONT == *REAR+1)){
        cout<<"Overflow error\n";
        return;
    }
    else if(*FRONT == -1){ // FRONT == NULL
        *FRONT = 0;
        *REAR = 0;
    }
    else if(*REAR == size-1){
        *REAR = 0;
    }
    else{
        *REAR = *REAR + 1;
    }
    // Inserting item in the queue
    queue[*REAR] = item;
    return;
}


// Return the front element

int Queue::front(){
    if(*FRONT == -1){
        cout<<"Underflow error\n";
        return -1;
    }
    return queue[*FRONT];
}


// Return the rear element

int Queue::rear(){
    if(*FRONT == -1){
        cout<<"Underflow error\n";
        return -1;
    }
    return queue[*REAR];
}


// Deletion at front end of queue

int Queue::pop(){
    if(*FRONT == -1){
        cout<<"Underflow error\n";
        return -1;
    }
    int front = queue[*FRONT];
    if(*FRONT == *REAR){
        *FRONT = -1;
        *REAR = -1;
    }
    else if(*FRONT < size-1){
        FRONT = FRONT + 1;
    }
    else{
        *FRONT = 0;
    }
    return front;
}


// Checking the current size of the queue

int Queue::currSize(){
    // Checking Queue is empty
    if(*FRONT == -1){ // Checking FRONT == NULL
        return 0;
    }
    else if(*FRONT == *REAR){ // If Queue contains single element only
        return 1;
    }
    else if(*FRONT < *REAR){
        return (*REAR - *FRONT + 1);
    }
    else{
        return (size - *FRONT + *REAR +1);
    }
    return -1;
}


// Checking if Queue is empty

bool Queue::isEmpty(){
    return (*FRONT == -1);
}


// Checking if Queue is full

bool Queue::isFull(){
    int Size = currSize(); // Size is the current size
    return (size == Size); // size is the Maximum size of array
}

// Printing elements of queue

void Queue::print(){
    // Checking Underflow condition
    if(*FRONT == -1){ // Checking FRONT == NULL
        cout<<"Underflow error\n";
        return;
    }
    int PTR = *FRONT; // Initialises counter
    while(PTR != *REAR+1){
        if(PTR == *REAR){
            if(*REAR == size-1){
                cout<<queue[PTR]<<" ";
                return;
            }
        }
        else if(PTR == size-1){ // If PTR reaches end of the array
            cout<<queue[PTR]<<" ";
            PTR = 0; // Set PTR = 0 as array is circular
        }
        else{
            cout<<queue[PTR]<<' ';
            PTR += 1;
        }
    }
    return;
}