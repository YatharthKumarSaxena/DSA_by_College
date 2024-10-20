#include <iostream>
using namespace std;

class PrioQueue {
    // Data Members
    int* arr; // Array to store elements
    int capacity; // Maximum capacity
    int size; // Current size
public:
    // Parameterized Constructor
    PrioQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }
    // Member Functions
    void push(int value);
    int pop();
    void print();
    void printReverse();
    bool isEmpty();
    bool isFull();
    int front();
    int rear();

    // Destructor
    ~PrioQueue() {
        delete[] arr;
    }
};