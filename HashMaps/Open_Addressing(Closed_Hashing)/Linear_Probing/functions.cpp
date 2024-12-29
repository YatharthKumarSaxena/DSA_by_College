#include "class.cpp"

bool OpenAddressing::searchVal(int val) {
    int loc = val % capacity; // Start with the hash index
    int reservedLoc = loc;
    int i = 0;

    while (arr[loc] != INT_MIN) { // Stop at the first empty slot
        if (arr[loc] == val) {
            return true; // Value found
        }
        i++;
        loc = (reservedLoc + i) % capacity; // Continuous probing
        if (i == capacity) {
            break; // Prevent infinite loop if all slots are checked
        }
    }
    return false; // Value not found
}

void OpenAddressing::deleteVal(int val) {
    int loc = val % capacity; // Start with the hash index
    int reservedLoc = loc;
    int i = 0;

    while (arr[loc] != INT_MIN) { // Stop at the first empty slot
        if (arr[loc] == val) {
            arr[loc] = INT_MAX; // Mark as deleted
            cout << "Value " << val << " deleted successfully\n";
            return;
        }
        i++;
        loc = (reservedLoc + i) % capacity; // Continuous probing
        if (i == capacity) {
            break; // Prevent infinite loop if all slots are checked
        }
    }
    cout << "Value " << val << " does not exist in hashmap\n";
}

void OpenAddressing::insertVal(int val){
    int loc = locOfOperation(val);
    if(loc == -1){
        cout<<"Overflow Error\n";
        cout<<"Value cannot be inserted\n";
        return;
    }
    arr[loc] = val;
    return;
}

int OpenAddressing::size(){
    int count = 0;
    for(int i=0;i<capacity;i++){
        if(arr[i] != INT_MIN && arr[i] != INT_MAX){
            count++;
        }
    }
    return count;
}

int OpenAddressing::totalSlotsInHashMap(){
    return this->capacity;
}

void OpenAddressing::displayMap(){
    for(int i=0;i<capacity;i++){
        if(arr[i] == INT_MIN || arr[i] == INT_MAX) cout<<"Empty Slot\n";
        else cout<<arr[i]<<endl;
    }

}