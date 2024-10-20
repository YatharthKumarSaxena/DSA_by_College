#include <iostream>
using namespace std;
class Deque{
    // Data Members
    int LEFT;
    int RIGHT;
    int size;
    int *deque;
public:
    // Parameterized Constructor
    Deque(int size){
        this->size = size;
        deque = new int[size];
        LEFT = -1;
        RIGHT = -1;
    }

    //Member Functions
    int front();
    int rear();
    bool isEmpty();
    bool isFull();
    void pushFront(int value);
    void pushBack(int value);
    int popFront();
    int popBack();
    void print();
    void printReverse();

    // Destructor
    ~Deque() {
        delete[] deque;
    }
};