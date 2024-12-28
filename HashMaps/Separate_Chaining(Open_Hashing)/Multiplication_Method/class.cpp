#include "../functionsOfLinkedList.cpp"
// Multiplication Method is used here to find loc
class SeparateChaining{
    // Data Members
    LinkedList** arr;
    int capacity;
    // Member Function
    int locOfOperation(int val){    // Returns Index of the Linked List where value must be Stored
        // HashFunction Definition
        float A = 0.347; // Initialised A constant < 1 but > 0
        float m = val*A;
        // Extract the fractional part of m
        float i = m - int(m);
        // Take floor part of i * capacity
        int loc =  i * capacity;
        return loc;
    }
public:
    // Parameterized Constructor
    SeparateChaining(int capacity){
        this->capacity = capacity;
        arr = new LinkedList*[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            arr[i] = new LinkedList();
        }
    }
    // Member Functions
    bool searchVal(int val);
    void deleteVal(int val);
    void insertVal(int val);
    int size(); // Returns the Current Size of HashMap
    int totalSlotsInHashMap();
    void displayMap();
    // Destructor
    ~SeparateChaining() {
        for (int i = 0; i < this->capacity; i++) {
            delete arr[i];
        }
        delete[] arr;
    }
};