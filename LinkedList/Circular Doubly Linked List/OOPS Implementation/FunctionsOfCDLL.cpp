#include "CircularDoublyLinkedListClass.cpp"


// Insertion at Beginning

void CircularDoublyLinkedList::insertAtHead(int item){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL > capacity){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = FORW[AVAIL];
    // Attaching Node at beginning 
    INFO[New] = item; // Insertion of item
    if(size == 0){
        FORW[START] = New;
        BACK[START] = New;
        BACK[New] = START;
        FORW[New] = START;
    }
    else{
        int help = FORW[START];
        FORW[START] = New;
        BACK[New] = START;
        FORW[New] = help;
        BACK[help] = New;
    }
    size++;
    return;
}


// Insertion at end

void CircularDoublyLinkedList::insertAtEnd(int item){
    // Checking Overflow Condition
    if(AVAIL > capacity){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = FORW[START]; // Initialises Pointer
    // Special Case
    if(PTR == START){ // Circular LL is empty
        insertAtHead(item);
        return;
    }
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    // Attaching Node at end
    PTR = BACK[START];
    // Linking Last Node to new node
    FORW[PTR] = New;
    BACK[New] = PTR;
    // Set New Node pointer points to NULL
    FORW[New] = START;
    BACK[START] = New;
    size++; // Increasing the size
    return;
}


// Printing of Linked list

void CircularDoublyLinkedList::print(){
    // Checking Underflow Condition
    if(FORW[START] == START){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = FORW[START]; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != START){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = FORW[PTR]; // Update Pointer
    }
    cout<<endl;
    return;
}

void CircularDoublyLinkedList::printReverse(){
    int PTR = BACK[START];
    if(PTR == START){
        cout<<"Underflow error\n";
        return;
    }
    while(PTR != START){
        cout<<INFO[PTR]<<" ";
        PTR = BACK[PTR]; // Updates Pointer
    }
    cout<<endl;
    return;
}

// Searching an element by its value

int CircularDoublyLinkedList::search(int item){
    int PTR = FORW[START]; // Initialises Pointer
    // Checking PTR == START && INFO[PTR] == item
    while(PTR != START && INFO[PTR] != item){ 
        PTR = FORW[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then 0 value is returned
    return LOC;
}


// Searching an element by its value from back

int CircularDoublyLinkedList::searchFromBack(int item){
    int PTR = BACK[START]; // Initialises Pointer
    // Checking PTR == START && INFO[PTR] == item
    while(PTR != START && INFO[PTR] != item){ 
        PTR = BACK[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then 0 value is returned
    return LOC;
}


// Insertion after specific Location

void CircularDoublyLinkedList::insertAfterIdx(int LOC,int item){
    if(LOC<0){
        cout<<"Negative Indexing not allowed\n";
        return;
    }
    if(AVAIL > capacity){
        cout<<"Overflow error\n";
        return;
    }
    // Special Case
    if(LOC == START){ // If LOC == NULL i.e Insert At head
        insertAtHead(item); // Insert As First Node
        return;
    }
    // Remove first node from AVAIL List
    int New = AVAIL;
    AVAIL = FORW[AVAIL];
    // Upadating INFO array
    INFO[New] = item;
    // Inserting the node after specific Location
    FORW[New] = FORW[LOC];
    BACK[FORW[LOC]] = New;
    FORW[LOC] = New;
    BACK[New] = LOC;
    // Increasing the current size
    size++;
    return;
}


// Insertion of item in sorted Linked list

void CircularDoublyLinkedList::insertInSorted(int item){
    // Special Case
    if(FORW[START] == START  || item < INFO[START]){
        insertAfterIdx(START,item);
        return;
    }
    int LOC = START;
    int PTR = FORW[START]; // Initialises Pointer
    while(PTR != START){ // Checking PTR == START
        if(item < INFO[PTR]){
            break;
        }
        LOC = PTR;
        PTR = FORW[PTR]; // Updating Pointer
    }
    insertAfterIdx(LOC,item);
    return;
}


// Deletion at beginning

int CircularDoublyLinkedList::deleteAtHead(){
    if(FORW[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    int New = FORW[START];
    // Removing first node
    FORW[START] = FORW[New];
    BACK[FORW[New]] = START;
    // Updating AVAIL List
    FORW[New] = AVAIL;
    AVAIL = New;
    // Decreasing the current size
    size--;
    return INFO[New];
}


// Deletion at end

int CircularDoublyLinkedList::deleteAtEnd(){
    if(FORW[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    // Initialises Pointers
    int SAVE = START;
    int PTR = FORW[START];
    // Special Case
    if(PTR == START){ // LL contain one element
        int val = deleteAtHead();
        return val;
    }
    while(FORW[PTR] != START){ // Checking PTR == START
        SAVE = PTR;
        PTR = FORW[PTR];
    }
    // Removing the last node
    FORW[SAVE] = START;
    BACK[START] = SAVE;
    // Updating the AVAIL List
    FORW[PTR] = AVAIL;
    AVAIL = PTR;
    // Decreasing the current size
    size--;
    return INFO[PTR];
}


// Deletion when value of item is given 


// Deletion following a given node
int CircularDoublyLinkedList::deleteAfterIdx(int& LOC){
    // Node at LOC is required to be deleted
    // LOCP means the preceeding node of the node at LOC which is to be deleted
    if(LOC == 0 && size != 0){
        cout<<"Item does not exist in list "<<endl;
        return INT_MIN;
    }
    if(LOC == 0 ){
        cout<<"Underflow error\n"<<endl;
        return INT_MIN;
    }
    else{ 
        int LOCP = BACK[LOC];
        // Checking LOCP == NULL
        if(LOCP == START){ // Deleting the first node
            // Removing the first Node of Linked List
            int val = deleteAtHead();
            return val;
        }
        else{
            FORW[LOCP] = FORW[LOC];
            BACK[FORW[LOC]] = LOCP;
        }
        // Updating the AVAIL List
        FORW[LOC] = AVAIL;
        AVAIL = LOC;
        // Decreasing the current size
        size--;
        return INFO[LOC];
    }
}


// Deleting an item
void CircularDoublyLinkedList::deleteItem(int item){
    int LOC = search(item);
    deleteAfterIdx(LOC);
    return;
}
