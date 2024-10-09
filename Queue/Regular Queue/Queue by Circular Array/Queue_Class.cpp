#include <iostream>
using namespace std;
class Queue{
    // Data Members
    int* FRONT;
    int* REAR;
    int size;
    int queue[];
    public:
    // Parameterized Constructor
    Queue(int size){
        this->size = size;
        queue[size];
        *FRONT = -1; // -1 is used as NULL
        *REAR = -1; // -1 is used as NULL
    }
    // Member Functions
    void push(int item);
    int pop();
    int front();
    int rear();
    bool isEmpty();
    bool isFull();
    void print();
    int currSize();
};