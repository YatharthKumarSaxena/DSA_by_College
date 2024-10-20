/* !! Don't Edit the code in this file otherwise program will malfunction !! */
#include <iostream>
using namespace std;
class Queue {
    // Data Members
    int *queue;
    int size;
    int FRONT, REAR;

public:
    // Parameterized Constructor
    Queue(int s) {
        size = s;
        queue = new int[size];
        FRONT = -1;
        REAR = -1;
    }
    
    //Member Functions
    int front();
    int rear();
    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    void print();

    // Destructor
    ~Queue() {
        delete[] queue;
    }
};