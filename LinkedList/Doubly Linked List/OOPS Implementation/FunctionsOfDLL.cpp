#include "DoublyLinkedListClass.cpp"

//Insertion at Beginning 

void DoublyLinkedList::insertAtHead(int item){
    if(AVAIL >= capacity){
        cout<<"Overflow error\n";
        return;
    }
    // Removing the First Node from AVAIL list
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Insertion of new node at beginning
    INFO[New] = item;
    // Checking DLL is empty
    if(FIRST == INT_MIN){ 
        FIRST = New;
        LAST = New;
        BACK[FIRST] = INT_MIN;
        FORW[FIRST] = INT_MIN;
    }
    else{
        FORW[New] = FIRST;
        BACK[FIRST] = New;
        FIRST = New;
        BACK[FIRST] = INT_MIN;
    }
    size++; // Increasing the current size by 1
    return;
}


// Insertion at end

void DoublyLinkedList::insertAtEnd(int item){
    // Checking Overflow Condition
    if(AVAIL >= capacity){
        cout<<"Overflow error\n";
        return;
    }
    // Checking DLL is empty
    if(FIRST == INT_MIN){
        insertAtHead(item);
        return;
    }
    // Removing the First Node from AVAIL list
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Inserting New Node at end
    INFO[New] = item;
    FORW[LAST] = New;
    BACK[New] = LAST;
    LAST = New;
    FORW[LAST] = INT_MIN;
    size++; // Increasing the current size by 1
    return;
}


// Insertion after specific Location

void DoublyLinkedList::insertAfterIdx(int LOC,int item){
    // Checking Overflow condition
    if(AVAIL >= capacity){
        cout<<"Overflow error\n";
    }
    // Insertion At First Location i.e LOC == INT_MIN
    else if(LOC == INT_MIN){
        insertAtHead(item);
    }
    // Insertion at Last location i.e LOC == LAST
    else if(LOC == LAST){
        insertAtEnd(item);
    }
    //Insertion at the wrong location
    else if(LOC>size){
        cout<<"Insertion not possible at "<<LOC<<"\n";
        cout<<"Index out of bound error here\n";
    }
    else if(LOC < 0){
        cout<<"Invalid index entered , negative indexing not allowed \n";
    }
    else{
        // Removing the First Node from AVAIL list
        int New = AVAIL;
        AVAIL = FORW[AVAIL];
        INFO[New] = item;
        // Inserting the item at Required Location
        FORW[New] = FORW[LOC];
        BACK[FORW[LOC]] = New;
        BACK[New] = LOC;
        FORW[LOC] = New;
    }
    size++; // Increasing the current size by 1
    return;
}


// Insertion in sorted manner

void DoublyLinkedList::insertInSorted(int item){
    // Special Case
    if(FIRST == INT_MIN || item < INFO[FIRST]){
        insertAfterIdx(INT_MIN,item);
        return;
    }
    int LOC = FIRST;
    int PTR = FORW[FIRST]; // Initialises Pointer
    while(PTR != INT_MIN){ // Checking PTR == LAST
        if(item < INFO[PTR]){
            break;
        }
        LOC = PTR;
        PTR = FORW[PTR]; // Updating Pointer
    }
    insertAfterIdx(LOC,item);
    return;
}


// Printing of the LL

// Printing in actual order
void DoublyLinkedList::print(){
    // Checking Underflow error
    if(FIRST == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = FIRST; // Initialises Pointer
    while(PTR != INT_MIN){
        cout<<INFO[PTR]<<" ";
        PTR = FORW[PTR]; // Updates Pointer
    }
    cout<<endl;
    return;
}

// Printing in reverse order
void DoublyLinkedList::printReverse(){
    // Checking Underflow condition
    if(LAST == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = LAST;
    while(PTR != INT_MIN){
        cout<<INFO[PTR]<<" ";
        PTR = BACK[PTR]; // Updates Pointer
    }
    cout<<endl;
    return;
}


// To count the current size of the DLL

int DoublyLinkedList::count(){
    return size;
}


// Searching an element by it's value

int DoublyLinkedList::search(int item){
    int PTR = FIRST; // Initialises Pointer
    while(PTR != INT_MIN){ // Checking PTR == NULL
        if(INFO[PTR]==item){
            return PTR;
        }
        PTR = FORW[PTR]; // Updates Pointer
    }
    // If search is unsuccessful INT_MIN Vlaue is returned
    return PTR;
}


// Searching an element by it's value from Back side of DLL

int DoublyLinkedList::searchFromBack(int item){
    int PTR = LAST; // Initialises Pointer
    while(PTR != INT_MIN){ // Checking PTR == NULL
        if(INFO[PTR]==item){
            return PTR;
        }
        PTR = BACK[PTR]; // Updates Pointer
    }
    // If search is unsuccessful INT_MIN Vlaue is returned
    return PTR;
}


// Deletion at beginning

int DoublyLinkedList::deleteAtHead(){
    // Checking Underflow Error
    if(FIRST == INT_MIN){ // Checking FIRST == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    // Special Case
    if(FIRST == LAST){ // DLL has only one node
        // Updating the AVAIL List
        FORW[FIRST] = AVAIL;
        AVAIL = FIRST;
        // Removing the first Node
        FIRST = INT_MIN;
        LAST = INT_MIN;
        return INFO[FIRST];
    }
    int New = FIRST;
    // Removing the FIRST node
    FIRST = FORW[FIRST];
    BACK[FIRST] = INT_MIN;
    // Updating AVAIL List
    FORW[New] = AVAIL;
    AVAIL = New;
    size--; // Decreasing the current size by 1
    return INFO[New];
}


// Deletion at end

int DoublyLinkedList::deleteAtEnd(){
    // Checking Underflow Error
    if(FIRST == INT_MIN){ // Checking FIRST == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    // Special Case
    if(FIRST == LAST){ // DLL has only one node
        int val = deleteAtHead();
        return val;
    }
    int New = LAST;
    // Removing the LAST node
    LAST = BACK[LAST];
    FORW[LAST] = INT_MIN;
    // Updating AVAIL List
    FORW[New] = AVAIL;
    AVAIL = New;
    size--; // Decreasing the current size by 1
    return INFO[New];
}


// Deletion following a given node
int DoublyLinkedList::deleteAfterIdx(int& LOCP,int& LOC){
    // Checking Underflow error
    if(FIRST == INT_MIN){
        cout<<"Underflow error\n";
    }
    // Deletion of the first node
    else if(LOCP == INT_MIN){
        int val = deleteAtHead();
        return val;
    }
    // Deletion of the Node that does not exist
    else if(LOCP == LAST || LOC<0 || LOC>=capacity){
        cout<<"Node does not exist\n";
    }
    // Deletion of the Last Node
    else if(FORW[LOCP] == LAST){
        int val = deleteAtEnd();
        return val;
    }
    // Deletion of the required node
    else{
        int New = FORW[LOC];
        FORW[LOCP] = FORW[New];
        BACK[New] = LOCP;
        // Updating the AVAIL List
        FORW[LOC] = AVAIL;
        AVAIL = LOC;
        size--; // Decreasing the current size by 1
        return INFO[LOC];
    }
    return INT_MIN;
}


// Deleting an item

void DoublyLinkedList::deleteItem(int item){
    // Location at which item is located is LOCA
    int LOC = search(item);
    if(LOC == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    // DeleteAfterIdx function require address of the previous node of the node to be deleted i.e LOC
    int LOCP = BACK[LOC];
    deleteAfterIdx(LOCP,LOC);
    return;
}