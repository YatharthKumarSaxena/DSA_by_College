class MaxHeap{

    // Private Data Members
    int* heap;
    int capacity;
    int idx;
public:

    // Parameterized Constructor
    MaxHeap(int capacity){
        this->capacity = capacity+1;
        heap = new int[capacity];
        idx = 0;
    }

    // Member Functions

    // All function prototypes are given below:-
    void insert(int item); // Insert Item in the MaxHeap
    int removeMaxEle(); // Remove the maximum element from the Maxheap and returns it's value
    int getMax(); // Returns the Maximum Element of the MaxHeap
    int size(); // Returns the current size of the MaxHeap
    void displayMaxHeapByLevelOrderTravesal(); // Display Compltete Minheap but LevelWise
};