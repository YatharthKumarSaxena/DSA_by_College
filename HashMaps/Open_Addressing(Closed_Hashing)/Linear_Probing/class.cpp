#include <iostream>
#include <climits>
using namespace std;

// Note :- You can use Folding Method, Mid_Square Method and Multiplication Method as HashFunction
// Using Division Method to find out the HashFunction
class OpenAddressing{
    // Data Members
    int* arr;
    int capacity;
    // Member Function
    int locOfOperation(int LOC){    // Returns Index of the Array where value must be Stored
        // HashFunction Definition
        int loc = LOC % capacity;
        int reservedLoc = loc;
        int i = 0;
        while(arr[loc]!=INT_MIN && arr[loc] != INT_MAX){
            i++;
            loc = (reservedLoc + i) % capacity; // Continuous probing
            if(i==this->capacity){
                cout<<"No location is available for "<<reservedLoc<<" in HashTable\n";
                return -1;
            }
        }
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
            if(count < 1)return num;
        }
        return -1;
    }
public:
    // Parametrized Constructor
    OpenAddressing(int capacity){
        this->capacity = this->optimumSlots(capacity);
        arr = new int[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            // Represent that Stop Iteration at this value and insert the value at this position
            arr[i] = INT_MIN;   
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
    ~OpenAddressing() {
        delete[] arr;
    }
};