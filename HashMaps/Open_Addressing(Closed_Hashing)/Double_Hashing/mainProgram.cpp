#include "functions.cpp"

void displayMenu() {
    cout << "\n=========== Hash Table Operations ===========\n";
    cout << "1. Insert a value\n";
    cout << "2. Search for a value\n";
    cout << "3. Delete a value\n";
    cout << "4. Display the hash table\n";
    cout << "5. Show current size\n";
    cout << "6. Show total slots in the hash table\n";
    cout << "7. Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice: ";
}

int main() {
    int initialCapacity;
    cout << "Enter the initial capacity of the hash table: ";
    cin >> initialCapacity;

    OpenAddressing hashTable(initialCapacity);

    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert: ";
                cin >> value;
                hashTable.insertVal(value);
                break;

            case 2:
                cout << "Enter a value to search: ";
                cin >> value;
                if (hashTable.searchVal(value)) {
                    cout << "Value " << value << " found in the hash table.\n";
                } else {
                    cout << "Value " << value << " not found in the hash table.\n";
                }
                break;

            case 3:
                cout << "Enter a value to delete: ";
                cin >> value;
                hashTable.deleteVal(value);
                break;

            case 4:
                cout << "Displaying hash table:\n";
                hashTable.displayMap();
                break;

            case 5:
                cout << "Current size of the hash table: " << hashTable.size() << "\n";
                break;

            case 6:
                cout << "Total slots in the hash table: " << hashTable.totalSlotsInHashMap() << "\n";
                break;

            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}
