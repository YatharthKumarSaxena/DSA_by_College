#include <iostream>
using namespace std;

class ListNode{
public:
    // Data Members
    int val;
    ListNode* next;
    // Parameterized Constructor
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
    // Data Members
    ListNode* Head;
    int size;
public:
    // Parameterized Constructor
    LinkedList(){
        this->Head = NULL;
        this->size = 0;
    }
    // Member Functions
    void insertNode(int val);
    void deleteNode(int val);
    bool searchValue(int val);
    void display();
    int currSize();
};#include "class.cpp"

void LinkedList::insertNode(int val){
    cout << "Value " << val << " inserted successfully" << endl;
    ListNode* temp = new ListNode(val);
    if(Head == NULL){
        Head = temp;
        size++;
        return;
    }
    temp->next = Head;
    Head = temp;
    size++;
    return;
}

void LinkedList::deleteNode(int val){
    ListNode* temp = Head;
    if(temp->val == val){
        Head = Head->next;
        size--;
        return;
    }
    while(temp && temp->next && temp->next->val != val){
        temp = temp->next;
    }
    if(temp){
        if(temp->next && temp->next->val == val){
            temp->next = temp->next->next;
            size--;
            return;
        }
    }
    cout << "No Node with value " << val << " exists in LinkedList" << endl;
    return;
}

bool LinkedList::searchValue(int val){
    ListNode* temp = Head;
    while(temp && temp->val!=val){
        temp=temp->next;
    }
    if(temp)return true;
    return false;
}

void LinkedList::display(){
    ListNode* temp = Head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int LinkedList::currSize(){
    return size;
} 

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
        for (int i = 0; i < capacity; i++) {
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
        for (int i = 0; i < capacity; i++) {
            delete arr[i];
        }
        delete[] arr;
    }
};#include "class.cpp"

bool SeparateChaining::searchVal(int val){
    int loc = locOfOperation(val);
    bool result = arr[loc]->searchValue(val);
    return result;
}

void SeparateChaining::insertVal(int val){
    int loc = locOfOperation(val);
    arr[loc]->insertNode(val);
}

void SeparateChaining::deleteVal(int val){
    int loc = locOfOperation(val);
    arr[loc]->deleteNode(val);
}

void SeparateChaining::displayMap(){
    cout<<"Your HashMap looks as given below:- \n";
    for(int i=0;i<capacity;i++){
        arr[i]->display();
    }
}

int SeparateChaining::totalSlotsInHashMap(){
    return this->capacity;
}

int SeparateChaining::size(){
    int totalSize = 0;
    for(int i=0;i<capacity;i++){
        totalSize += arr[i]->currSize();
    }
    return totalSize;
}#include "functions.cpp" // Include the implementation file of SeparateChaining

using namespace std;

void displayMenu() {
    cout << "\n====== Separate Chaining HashMap ======\n";
    cout << "1. Insert a Value\n";
    cout << "2. Search for a Value\n";
    cout << "3. Delete a Value\n";
    cout << "4. Display the HashMap\n";
    cout << "5. Get Total Slots in HashMap\n";
    cout << "6. Get Current Size of HashMap\n";
    cout << "7. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    int capacity;
    cout << "\nEnter the initial capacity for the HashMap (preferably a positive number): ";
    cin >> capacity;

    // Instantiate SeparateChaining object
    SeparateChaining hashMap(capacity);

    int choice, value;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Enter value to insert: ";
                cin >> value;
                hashMap.insertVal(value);
                break;
            }
            case 2:{
                cout << "Enter value to search: ";
                cin >> value;
                if (hashMap.searchVal(value)) {
                    cout << "Value found in the HashMap.\n";
                } else {
                    cout << "Value not found.\n";
                }
                break;
            }
            case 3:{
                cout << "Enter value to delete: ";
                cin >> value;
                hashMap.deleteVal(value);
                cout << "Value deleted successfully (if it existed).\n";
                break;
            }
            case 4:{
                cout << "Displaying the HashMap:\n";
                hashMap.displayMap();
                break;
            }
            case 5:{
                cout << "Total slots in HashMap: " << hashMap.totalSlotsInHashMap() << "\n";
                break;
            }
            case 6:{
                cout << "Current size of HashMap: " << hashMap.size() << "\n";
                break;
            }
            case 7:{
                cout << "Exiting program. Goodbye!\n";
                return 0;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
    return 0;
}
