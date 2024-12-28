#include "functions.cpp"

int main() {
    int capacity;
    cout << "\nEnter the capacity of the HashMap: ";
    cin >> capacity;

    SeparateChaining hashMap(capacity);

    int choice, value;
    while (true) {
        cout << "\n-- Menu --\n";
        cout << "1. Insert Value\n";
        cout << "2. Delete Value\n";
        cout << "3. Search Value\n";
        cout << "4. Display HashMap\n";
        cout << "5. Get Total Slots in HashMap\n";
        cout << "6. Get Current Size of HashMap\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "Enter the value to insert: ";
                cin >> value;
                hashMap.insertVal(value);
                break;
            }
            case 2:{
                cout << "Enter the value to delete: ";
                cin >> value;
                hashMap.deleteVal(value);
                break;
            }
            case 3:{
                cout << "Enter the value to search: ";
                cin >> value;
                if (hashMap.searchVal(value)) {
                    cout << "Value found!" << endl;
                } else {
                    cout << "Value not found." << endl;
                }
                break;
            }
            case 4:{
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
                cout << "Exiting program..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
