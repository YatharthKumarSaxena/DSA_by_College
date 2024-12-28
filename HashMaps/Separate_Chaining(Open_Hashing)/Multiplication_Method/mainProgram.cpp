#include "functions.cpp"

int main() {
    int capacity;
    cout << "Enter the capacity of the HashMap: ";
    cin >> capacity;

    SeparateChaining hashTable(capacity);

    int choice, value;
    do {
        cout << "\n================= HashMap Menu =================\n";
        cout << "1. Insert a value\n";
        cout << "2. Search for a value\n";
        cout << "3. Delete a value\n";
        cout << "4. Display the HashMap\n";
        cout << "5. Get the total number of slots in HashMap\n";
        cout << "6. Get the current size of HashMap\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                hashTable.insertVal(value);
                cout << "Value " << value << " inserted successfully.\n";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (hashTable.searchVal(value))
                    cout << "Value " << value << " found in the HashMap.\n";
                else
                    cout << "Value " << value << " not found in the HashMap.\n";
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                hashTable.deleteVal(value);
                cout << "Value " << value << " deleted if it existed.\n";
                break;

            case 4:
                hashTable.displayMap();
                break;

            case 5:
                cout << "Total number of slots in HashMap: " << hashTable.totalSlotsInHashMap() << endl;
                break;

            case 6:
                cout << "Current size of HashMap: " << hashTable.size() << endl;
                break;

            case 0:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
