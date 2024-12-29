#include "functions.cpp" // Include the provided implementation of SeparateChaining

void displayMenu() {
    cout << "\n===== Hash Map (Separate Chaining) =====\n";
    cout << "1. Insert a value\n";
    cout << "2. Delete a value\n";
    cout << "3. Search for a value\n";
    cout << "4. Display the hash map\n";
    cout << "5. Check total slots in the hash map\n";
    cout << "6. Check current size of the hash map\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int capacity;
    cout << "Enter the capacity of the hash map: ";
    cin >> capacity;

    SeparateChaining hashMap(capacity);
    int choice, value;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Insert a value
                cout << "Enter value to insert: ";
                cin >> value;
                hashMap.insertVal(value);
                break;

            case 2: // Delete a value
                cout << "Enter value to delete: ";
                cin >> value;
                hashMap.deleteVal(value);
                break;

            case 3: // Search for a value
                cout << "Enter value to search: ";
                cin >> value;
                if (hashMap.searchVal(value)) {
                    cout << "Value " << value << " found in the hash map.\n";
                } else {
                    cout << "Value " << value << " not found in the hash map.\n";
                }
                break;

            case 4: // Display the hash map
                hashMap.displayMap();
                break;

            case 5: // Check total slots
                cout << "Total slots in the hash map: " << hashMap.totalSlotsInHashMap() << "\n";
                break;

            case 6: // Check current size
                cout << "Current size of the hash map: " << hashMap.size() << "\n";
                break;

            case 7: // Exit
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }

    return 0;
}
