#include "class.cpp"

// Insert Function
void OpenAddressing::insertVal(int key)
{
    int steps = 0;
    int hash = locOfOperation(key);

    if (hash == -1)
    {
        cout << "Hash table full. Rehashing required!\n";
        rehash();
        insertVal(key);
        return;
    }

    while (arr[hash] != INT_MIN && arr[hash] != INT_MAX)
    {
        if (arr[hash] == key)
        {
            cout << "Duplicate key: " << key << " already exists.\n";
            return;
        }
        hash = (hash + steps * steps) % capacity;
        steps++;

        if (steps >= capacity / 2)
        {
            cout << "Secondary clustering detected. Rehashing required!\n";
            rehash();
            insertVal(key);
            return;
        }
    }

    arr[hash] = key;
}

// Search Function
bool OpenAddressing::searchVal(int key)
{
    int hash = locOfOperation(key);
    return hash != -1 && arr[hash] == key;
}

// Delete Function
void OpenAddressing::deleteVal(int key)
{
    int hash = locOfOperation(key);

    if (hash == -1 || arr[hash] != key)
    {
        cout << "Key " << key << " not found.\n";
        return;
    }

    arr[hash] = INT_MAX; // Mark as deleted
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