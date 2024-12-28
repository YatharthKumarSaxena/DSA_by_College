#include "../functionsOfLinkedList.cpp"
// Optimum Division Method Separate Chaining here Size of the array is always taken as Prime Number
class SeparateChaining{
    // Data Members
    LinkedList** arr;
    int capacity;
    // Member Function
    int locOfOperation(int LOC){    // Returns Index of the Linked List where value must be Stored
        // HashFunction Definition
        int loc = LOC % capacity;
        return loc;
    }
    // Return the Optimum Slot that will always be a Prime Number just greater than the user capacity
    int optimumSlots(int capacity){
        if(capacity<2){
            return 2;
        }
        int num = capacity;
        while(true){
            int count = 0;
            num += 1;
            int i;
            for(i=2;i*i<=num;i++){
                if(num%i==0)count++;
            }
            if(count < 2)return num;
        }
        return -1;
    }
public:
    // Parameterized Constructor
    SeparateChaining(int capacity){
        this->capacity = this->optimumSlots(capacity);
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