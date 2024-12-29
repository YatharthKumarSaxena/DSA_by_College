#include "../functionsOfLinkedList.cpp"
#include <algorithm>
#include <vector>
#include <string>

// Mid Square Method is used here to find loc
class SeparateChaining{
    // Data Members
    LinkedList** arr;
    int capacity;
    // Member Function
    int locOfOperation(int LOC){
        int loc = foldingMethod(LOC,2) % capacity;
        return loc;
    }
    int foldingMethod(int key, int partLength) {
        // Step 1: Convert key to string to handle digits
        string keyStr = to_string(key);
        int keyLength = keyStr.length();

        // Step 2: Partition the key into parts of size 'partLength'
        vector<int> parts;
        for (int i = 0; i < keyLength; i += partLength) {
            string partStr = keyStr.substr(i, partLength);
            // Convert each part to an integer
            parts.push_back(stoi(partStr));
        }

        // Step 3: Reverse even-numbered parts (optional)
        for (int i = 1; i < parts.size(); i += 2) {
            string reversedPart = to_string(parts[i]);
            reverse(reversedPart.begin(), reversedPart.end());
            parts[i] = stoi(reversedPart);
        }

        // Step 4: Sum the parts to compute the final hash
        int hashValue = 0;
        for (int part : parts) {
            hashValue += part;
        }

        // Step 5: Return the final hash value
        return hashValue;
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