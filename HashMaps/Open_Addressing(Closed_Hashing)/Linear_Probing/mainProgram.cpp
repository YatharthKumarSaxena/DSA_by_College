#include "functions.cpp"

// Function to display the menu
void displayMenu() {
    cout << "\n======== HashMap Operations Menu ========\n";
    cout << "1. Insert a Value\n";
    cout << "2. Delete a Value\n";
    cout << "3. Search for a Value\n";
    cout << "4. Display the HashMap\n";
    cout << "5. Current Size of the HashMap\n";
    cout << "6. Total Slots in the HashMap\n";
    cout << "7. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    int capacity;
    cout << "Enter the initial capacity for the HashMap: ";
    cin >> capacity;

    // Initialize the OpenAddressing HashMap
    OpenAddressing hashMap(capacity);

    int choice, value;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                hashMap.insertVal(value);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                hashMap.deleteVal(value);
                break;

            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                if (hashMap.searchVal(value)) {
                    cout << "Value " << value << " is present in the HashMap.\n";
                } else {
                    cout << "Value " << value << " is not present in the HashMap.\n";
                }
                break;

            case 4:
                cout << "Displaying the HashMap: \n";
                hashMap.displayMap();
                break;

            case 5:
                cout << "Current size of the HashMap: " << hashMap.size() << "\n";
                break;

            case 6:
                cout << "Total slots in the HashMap: " << hashMap.totalSlotsInHashMap() << "\n";
                break;

            case 7:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
