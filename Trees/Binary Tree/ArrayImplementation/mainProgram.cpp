#include "functionsOfBinaryTree.cpp"
using namespace std;

void displayMenu() {
    cout << "\n========= Binary Tree Operations Menu =========\n";
    cout << "0. Display Complete Binary Tree\n";
    cout << "1. Insert a value into the tree\n";
    cout << "2. Display information about a node\n";
    cout << "3. Get left child of a node\n";
    cout << "4. Get right child of a node\n";
    cout << "5. Get parent of a node\n";
    cout << "6. Find sibling of a node\n";
    cout << "7. Display tree in Pre-order\n";
    cout << "8. Display tree in In-order\n";
    cout << "9. Display tree in Post-order\n";
    cout << "10. Remove a node\n";
    cout << "11. Make the tree empty\n";
    cout << "12. Get current size of the tree\n";
    cout << "-1. Exit\n";
    cout << "==============================================\n";
}

int main() {
    int size;
    cout << "Enter the maximum size of the binary tree: ";
    cin >> size;

    BinaryTree tree(size);
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:{
                cout<<"Complete Binary Tree Structure level wise is displayed below:-\n";
                tree.displayCBT();
                break;
            }
            case 1: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            }
            case 2: {
                int node;
                cout << "Enter node index to get information: ";
                cin >> node;
                int info = tree.info(node);
                if (info != INT_MIN) {
                    cout << "Value at node " << node << ": " << info << endl;
                }
                break;
            }
            case 3: {
                int node;
                cout << "Enter node index to get left child: ";
                cin >> node;
                int left = tree.leftChild(node);
                if (left != INT_MIN) {
                    cout << "Left child of node " << node << ": " << tree.info(left) << endl;
                }
                break;
            }
            case 4: {
                int node;
                cout << "Enter node index to get right child: ";
                cin >> node;
                int right = tree.rightChild(node);
                if (right != INT_MIN) {
                    cout << "Right child of node " << node << ": " << tree.info(right) << endl;
                }
                break;
            }
            case 5: {
                int node;
                cout << "Enter node index to get parent: ";
                cin >> node;
                int parent = tree.father(node);
                if (parent != INT_MIN) {
                    cout << "Parent of node " << node << ": " << tree.info(parent) << endl;
                }
                break;
            }
            case 6: {
                int node;
                cout << "Enter node index to find sibling: ";
                cin >> node;
                tree.sibling(node);
                break;
            }
            case 7: {
                cout << "Pre-order traversal: ";
                tree.preOrder(1);
                cout << endl;
                break;
            }
            case 8: {
                cout << "In-order traversal: ";
                tree.inOrder(1);
                cout << endl;
                break;
            }
            case 9: {
                cout << "Post-order traversal: ";
                tree.postOrder(1);
                cout << endl;
                break;
            }
            case 10: {
                int node;
                cout << "Enter node index to remove: ";
                cin >> node;
                int removedValue = tree.removeNthNode(node);
                if (removedValue != INT_MIN) {
                    cout << "Removed value: " << removedValue << endl;
                }
                break;
            }
            case 11: {
                tree.makeEmpty();
                cout << "Tree has been emptied.\n";
                break;
            }
            case 12: {
                cout << "Current size of the tree: " << tree.currSize() << endl;
                break;
            }
            case -1: {
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != -1);

    return 0;
}