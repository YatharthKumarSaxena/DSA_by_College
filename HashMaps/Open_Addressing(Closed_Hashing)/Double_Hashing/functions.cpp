#include "class.cpp"

// Insert Function
void OpenAddressing::insertVal(int key)
{
    if (this->size() == capacity)
    {
        cout << "Hash table full. \n";
        cout<<"Overflow Error\n";
        return;
    }
    int hash = locOfOperation(key);
    arr[hash] = key;
}

bool OpenAddressing::searchVal(int key) {
    int hash = key % capacity;
    int originalHash = hash;
    int i = 0;

    while (arr[hash] != INT_MIN) {
        if (arr[hash] == key) {
            return true; // Key found
        }

        // Continue probing, including over deleted slots
        hash = (originalHash + i * DoubleHashFunction(key)) % capacity;
        i++;

        if (i >= capacity) {
            break; // Prevent infinite loop
        }
    }

    return false; // Key not found
}

void OpenAddressing::deleteVal(int key) {
    int hash = key % capacity;
    int originalHash = hash;
    int i = 0;

    while (arr[hash] != INT_MIN) {
        if (arr[hash] == key) {
            arr[hash] = INT_MAX; // Mark as deleted
            cout << "Key " << key << " deleted.\n";
            return;
        }

        // Continue probing, including over deleted slots
        hash = (originalHash + i * DoubleHashFunction(key)) % capacity;
        i++;

        if (i >= capacity) {
            break; // Prevent infinite loop
        }
    }

    cout << "Key " << key << " not found.\n";
}


// Display Function
void OpenAddressing::displayMap()
{
    for (int i = 0; i < capacity; i++)
    {
        if (arr[i] == INT_MIN)
        {
            cout << "Empty Slot";
        }
        else if (arr[i] == INT_MAX)
        {
            cout << "Empty Slot";
        }
        else
        {
            cout << arr[i];
        }
        cout<<endl;
    }
    cout << endl;
}

int OpenAddressing::size(){
    int count = 0;
    for(int i=0;i<capacity;i++){
        if(arr[i] == INT_MIN || arr[i] == INT_MAX)continue;
        else count++;
    }
    return count;
}

int OpenAddressing::totalSlotsInHashMap(){
    return this->capacity;
}