/* !! Don't Edit the code in this file otherwise program will malfunction !! */
#include "Queue_Class.cpp"

// All Function Definition of Regular Queue Class 


// Checking if Queue is empty

bool Queue::isEmpty(){
    return (FRONT == -1);
}


// Checking if Queue is full

bool Queue::isFull(){
    return ((REAR + 1) % size == FRONT); // size is the Maximum size of array
}


//Insertion function at end

void Queue::push(int value) {
    if (isFull()) {
        cout << "Overflow error\n";
        return;
    }
    if (FRONT == -1) FRONT = 0;
    REAR = (REAR + 1) % size;
    queue[REAR] = value;
}


// Deletion at front end of queue

int Queue::pop(){
    if (isEmpty()) {
        cout << "Underflow error\n";
        return -1;
    }
    int ele = queue[FRONT];
    if (FRONT == REAR) {
        FRONT = -1;
        REAR = -1;
    } else {
        FRONT = (FRONT + 1) % size;
    }
    return ele;
}



// Printing elements of queue

void Queue::print() {
    if (isEmpty()) {
        cout << "Underflow error\n";
        return;
    }
    int i = FRONT;
    while (true) {
        cout << queue[i] << ' ';
        if (i == REAR) break;
        i = (i + 1) % size;
    }
    cout << endl;
}


// Return the front element of Regular Queue

int Queue::front(){
    // Checking Underflow condition
    if(FRONT == -1){ // FRONT == NULL
        cout<<"Underflow Error\n";
        return -1;
    }
    return queue[FRONT];
}


// Return the rear element of Regular Queue

int Queue::rear(){
    // Checking Underflow condition
    if(FRONT == -1){ // FRONT == NULL
        cout<<"Underflow Error\n";
        return -1;
    }
    return queue[REAR];
}