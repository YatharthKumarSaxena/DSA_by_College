#include "FunctionsOfCDLL.cpp"

int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore singly Linked List\n";
    int size;
    cout<<"Please enter the maximum size of your Linked List = ";
    cin>>size;
    CircularDoublyLinkedList LL(size);

    /* !! Don't Edit the Above code otherwise program will malfunction !! */


    // Sample Code written so that you can understand how to implement these functions
    
    LL.print();
    LL.insertAtEnd(4);
    LL.insertAtHead(1);
    LL.insertAtHead(2);
    LL.insertAtEnd(3);
    LL.insertAtHead(8);
    LL.insertAtEnd(9);
    LL.print();
    LL.printReverse();
    LL.deleteAtHead();
    LL.deleteAtEnd();
    LL.deleteItem(3);
    cout<<LL.deleteAtHead()<<endl;
    cout<<LL.deleteAtEnd()<<endl;
    LL.deleteItem(1);
    LL.insertInSorted(6);
    LL.insertInSorted(5);
    LL.insertInSorted(3);
    LL.insertInSorted(4);
    LL.insertInSorted(1);
    LL.insertInSorted(2);
    LL.insertInSorted(10);
    LL.print();
    return 0;
}