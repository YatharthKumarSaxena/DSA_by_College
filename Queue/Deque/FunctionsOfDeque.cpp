/* !! Don't Edit the code in this file otherwise program will malfunction !! */
#include "Deque_Class.cpp"

// All Function Definition of Regular Deque Class 


// Checking if Deque is empty

bool Deque::isEmpty(){
    return (LEFT == -1);
}


// Checking if Deque is full

bool Deque::isFull(){
    return ((RIGHT + 1) % size == LEFT); // size is the Maximum size of array
}


//Insertion function at end

void Deque::pushBack(int value) {
    if (isFull()) {
        cout << "Overflow error\n";
        return;
    }
    if (LEFT == -1){
        LEFT = 0;
    }
    RIGHT = (RIGHT + 1) % size;
    deque[RIGHT] = value;
}


//Insertion function at front

void Deque::pushFront(int value) {
    if (isFull()) {
        cout << "Overflow error\n";
        return;
    }
    if (LEFT == -1){
        LEFT = 0;
        RIGHT = 0;
    }
    else LEFT = (size + (LEFT - 1) % size)%size;
    deque[LEFT] = value;
}


// Deletion at front end of deque

int Deque::popFront(){
    if (isEmpty()) {
        cout << "Underflow error\n";
        return -1;
    }
    int ele = deque[LEFT];
    if (LEFT == RIGHT) {
        LEFT = -1;
        RIGHT = -1;
    } else {
        LEFT = (LEFT + 1) % size;
    }
    return ele;
}


// Deletion at rear end of deque

int Deque::popBack(){
    if (isEmpty()) {
        cout << "Underflow error\n";
        return -1;
    }
    int ele = deque[RIGHT];
    if (LEFT == RIGHT) {
        LEFT = -1;
        RIGHT = -1;
    } else {
        RIGHT = (size+(RIGHT - 1) % size)%size;
    }
    return ele;
}


// Return the front element of Regular Deque

int Deque::front(){
    // Checking Underflow condition
    if(LEFT == -1){ // FRONT == NULL
        cout<<"Underflow Error\n";
        return -1;
    }
    return deque[LEFT];
}


// Return the rear element of Regular Deque

int Deque::rear(){
    // Checking Underflow condition
    if(LEFT == -1){ // FRONT == NULL
        cout<<"Underflow Error\n";
        return -1;
    }
    return deque[RIGHT];
}


// Printing elements of Deque

void Deque::print() {
    if (isEmpty()) {
        cout << "Underflow error\n";
        return;
    }
    int i = LEFT;
    while (true) {
        cout << deque[i] << ' ';
        if (i == RIGHT) break;
        i = (i + 1) % size;
    }
    cout << endl;
}


// Printing elements of Deque in reverse order

void Deque::printReverse() {
    if (isEmpty()) {
        cout << "Underflow error\n";
        return;
    }
    int i = RIGHT;
    while (true) {
        cout << deque[i] << ' ';
        if (i == LEFT) break;
        i = (size+(i - 1) % size)%size;
    }
    cout << endl;
}