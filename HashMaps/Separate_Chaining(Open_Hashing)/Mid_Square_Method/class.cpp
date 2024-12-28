#include "../functionsOfLinkedList.cpp"
#include <algorithm>
#include <string>

// Mid Square Method is used here to find loc
class SeparateChaining{
    // Data Members
    LinkedList** arr;
    int capacity;
    // Member Function
    int locOfOperation(int LOC){
        int loc = midSquareMethod(LOC) % capacity;
        return loc;
    }
    int midSquareMethod(int k) {
    // Step 1: Square the key
    long long square = (long long)k * k;
    
    // Step 2: Convert the square to a string to handle digits
    string squareStr = to_string(square);
    
    // Step 3: Calculate the length of the squared number
    int len = squareStr.length();
    
    // Step 4: Extract the middle digits
    if (len % 2 == 0) {
        // Even length: Return the middle two digits
        int mid = len / 2;
        string middle = squareStr.substr(mid - 1, 2);
        return stoi(middle); // Convert the middle part back to integer
    } else {
        // Odd length: Return the middle digit
        int mid = len / 2;
        return squareStr[mid] - '0'; // Convert char to int
    }
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