class MinHeap{

    // Private Data Members
    int* heap; // Heap Array
    int capacity; // Maximum Capacity of the array
    int idx; // Stores the Current last index of the array in which some value is inserted
public:

    // Parameterized Constructor
    MinHeap(int capacity){
        this->capacity = capacity+1;
        heap = new int[capacity];
        idx = 0;
    }

    // Member Functions

    // All function prototypes are given below:-
    void insert(int item); // Insert Item in the MinHeap
    int removeMinEle(); // Remove the minimum element from the Minheap and returns it's value
    int getMin(); // Returns the Minimum Element of the MinHeap
    int size(); // Returns the current size of the MinHeap
    void displayMinHeapByLevelOrderTravesal(); // Display Compltete Minheap but LevelWise
};