#include "Queue_Class.cpp"

// All Function Definition of Regular Queue Class 


//Insertion function at end

void Queue::push(int item){
    // Checking Overflow Condition
    if((*FRONT = 0 && *REAR == size-1) || (*FRONT = *REAR+1)){
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
        return;
    }
    return queue[*FRONT];
}


// Return the rear element

int Queue::rear(){
    if(*FRONT == -1){
        cout<<"Underflow error\n";
        return;
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