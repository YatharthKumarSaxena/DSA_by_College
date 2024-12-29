#include <iostream>
#include <climits>
using namespace std;

class OpenAddressing {
    // Data Members
    int* arr;
    int capacity;
    
    // Helper Functions

    int locOfOperation(int key) {
        // Hash Function using Division Method
        int hash = key % capacity;
        int originalHash = hash;
        int i = 1;

        while (arr[hash] != INT_MIN && arr[hash] != INT_MAX) {
            if (arr[hash] == key) {
                return hash; // Key found
            }
            hash = (originalHash + i * i) % capacity; // Quadratic Probing
            i++;
            
            if (i == capacity) {
                return -1; // Indicates full table or infinite loop
            }
        }
        return hash; // Return available slot
    }

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    int nextPrime(int num) {
        while (!isPrime(num)) {
            num++;
        }
        return num;
    }

    void rehash() {
        int oldCapacity = capacity;
        int* oldArr = arr;

        capacity = nextPrime(2 * capacity); // Double the capacity and find next prime
        arr = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            arr[i] = INT_MIN; // Mark all slots as empty
        }

        for (int i = 0; i < oldCapacity; i++) {
            if (oldArr[i] != INT_MIN && oldArr[i] != INT_MAX) {
                insertVal(oldArr[i]); // Re-insert values into the new hash table
            }
        }

        delete[] oldArr;
    }

public:
    // Constructor
    OpenAddressing(int capacity) {
        this->capacity = nextPrime(capacity);
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