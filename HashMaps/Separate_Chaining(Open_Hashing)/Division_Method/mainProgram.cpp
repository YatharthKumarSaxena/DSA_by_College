#include "functions.cpp" // Include the implementation file of SeparateChaining

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
