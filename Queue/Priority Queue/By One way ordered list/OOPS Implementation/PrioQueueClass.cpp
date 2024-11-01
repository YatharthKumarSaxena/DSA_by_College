#include <iostream>
#include <climits>
using namespace std;
class PrioQueue{
    // Data Member
    string* INFO;
    int* LINK;
    int* PRN;
    int capacity; // Maximum Size of PrioQueue
    int size; // Current size of PrioQueue
    int AVAIL; // AVAIL Pointer
    int START; // START Pointer
    // Member Function 
    void insertAfterIdx(int LOC,string item,int prioNumber);
    int findLOC(int prioNumber);
public:

    // Parameterized Constructor

    PrioQueue(int capacity){
        this->capacity = capacity;
        // Array of unused memory cells let say AVAIL list consist of INFO part,PRIO Part and LINK part
        INFO = new string[capacity]; // A list that contains Data of elements of Priority Queue
        PRN = new int[capacity]; // A list that contains Priority of elements of Priority Queue
        LINK = new int[capacity]; // A list that contains address of next element
        START = INT_MIN;
        AVAIL = 0;
        size = 0; // Initial Size of PrioQueue is 0
        for(int i=0;i<capacity;i++){
            // Example LINK[0] = 1 points to 1st index of INFO array
            LINK[i] = i+1; // Linking Link element value to the next index of INFO element
            PRN[i] = -1;
        }
    }

    // Member Functions

    // All function prototypes given below :-

    string pop();
    void print();
    int count();
    void push(string item,int prioNumber);
    string front();
    string rear();
    bool isEmpty();
    bool isFull();

    // Destructor
    ~PrioQueue() {
        delete[] INFO;
        delete[] LINK;
        delete[] PRN;
    }
};