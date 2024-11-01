#include "CircularLinkedListClass.cpp"


// Insertion at Beginning

void CircularLinkedList::insertAtHead(int item){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL > capacity){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = LINK[AVAIL];
    // Attaching Node at beginning 
    INFO[New] = item; // Insertion of item
    if(size == 0){
        LINK[START] = New;
        LINK[New] = START;
    }
    else{
        int help = LINK[START];
        LINK[START] = New;
        LINK[New] = help;
    }
    size++;
    return;
}


// Insertion at end

void CircularLinkedList::insertAtEnd(int item){
    // Checking Overflow Condition
    if(AVAIL > capacity){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = LINK[START]; // Initialises Pointer
    // Special Case
    if(PTR == START){ // Circular LL is empty
        insertAtHead(item);
        return;
    }
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    // Attaching Node at end
    while(LINK[PTR] != START){
        PTR = LINK[PTR]; // Updating pointer
    }
    // Linking Last Node to new node
    LINK[PTR] = New;
    // Set New Node pointer points to NULL
    LINK[New] = START;
    size++;
    return;
}


// Printing of Linked list

void CircularLinkedList::print(){
    // Checking Underflow Condition
    if(LINK[START] == START){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = LINK[START]; // Initialises pointer
    // Checking PTR == NULL
    while(PTR != START){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    return;
}

// Searching an element by it's value

int CircularLinkedList::search(int item){
    int PTR = LINK[START]; // Initialises Pointer
    // Checking PTR == NULL && INFO[PTR] = item
    while(PTR != START && INFO[PTR] != item){ 
        PTR = LINK[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then 0 value is returned
    return LOC;
}


// Insertion after specific Location

void CircularLinkedList::insertAfterIdx(int LOC,int item){
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
    AVAIL = LINK[AVAIL];
    // Upadating INFO array
    INFO[New] = item;
    // Inserting the node after specific Location
    LINK[New] = LINK[LOC];
    LINK[LOC] = New;
    size++;
    return;
}

// Function findLOC And insertInSorted to create a sorted singly Linked List


// Function to find Location for insertion in sorted linked list

int CircularLinkedList::findLOC(int item){
    // List empty Condition
    if(LINK[START] == START){
        return START;
    }
    // Initialises Pointer
    int LOC = START;
    int PTR = LINK[START];
    // Checking PTR != START
    while(PTR!=START){ 
        if(item < INFO[PTR]){
            return LOC;
        }
        // Update Pointers
        LOC = PTR;
        PTR = LINK[PTR];
    }
    return LOC;
}

// Insertion of item in sorted Linked list

void CircularLinkedList::insertInSorted(int item){
    // Find location where item < value of element of linked list
    int idx = findLOC(item);
    // Inserting item before the value whose value is just greater than item
    insertAfterIdx(idx,item);
    return;
}


// Deletion at beginning

int CircularLinkedList::deleteAtHead(){
    if(LINK[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    int New = LINK[START];
    // Removing first node
    LINK[START] = LINK[New];
    // Updating AVAIL List
    LINK[New] = AVAIL;
    AVAIL = New;
    // Decreasing the current size
    size--;
    return INFO[New];
}


// Deletion at end

int CircularLinkedList::deleteAtEnd(){
    if(LINK[START] == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    // Initialises Pointers
    int SAVE = START;
    int PTR = LINK[START];
    // Special Case
    if(PTR == START){ // LL contain one element
        int val = deleteAtHead();
        return val;
    }
    while(LINK[PTR] != START){ // Checking PTR == START
        SAVE = PTR;
        PTR = LINK[PTR];
    }
    // Removing the last node
    LINK[SAVE] = START;
    // Updating the AVAIL List
    LINK[PTR] = AVAIL;
    AVAIL = PTR;
    // Decreasing the current size
    size--;
    return INFO[PTR];
}

// Deletion following a given node

int CircularLinkedList::deleteAfterIdx(int LOC,int LOCP){
    // Node at LOC is required to be deleted
    // LOCP means the preceeding node of the node at LOC which is to be deleted
    if(LOC == -1 && LOCP == -1){
        cout<<"Item does not exist in list"<<endl;
        return INT_MIN;
    }
    if(LOC == START){ // Checking Circular LL is empty
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    else{ 
        // Checking LOCP == NULL
        if(LOCP == START){ // Deleting the first node
            // Removing the first Node of Linked List
            int val = deleteAtHead();
            return val;
        }
        else{
            LINK[LOCP] = LINK[LOC];
        }
        // Updating the AVAIL List
        LINK[LOC] = AVAIL;
        AVAIL = LOC;
        // Decreasing the current size
        size--;
        return INFO[LOC];
    }
}
// Deletion when value of item is given 

// Finding the Location of deleted item i.e LOC and it's preceeding location LOCP

void CircularLinkedList::findLOCandLOCP(int item,int &LOC,int &LOCP){
    if(LINK[START] == START){ // Checking Circular Linked List is empty
        LOC == START;
        return;
    }
    int PTR = LINK[START]; // Initialised Pointer for LOC
    if(INFO[PTR] == item){
        LOC = PTR;
        LOCP = START;
        return;
    }
    int SAVE = START; // Initialised pointer for LOCP
    while(PTR != START){ // Checking upto Last Node 
        if(INFO[PTR] == item){
            LOCP = SAVE;
            LOC = PTR;
            return;
        }
        // Updates Pointer
        SAVE = PTR;
        PTR = LINK[PTR];
    }
    return;
}

// Deleting an item

void CircularLinkedList::deleteItem(int item){
    int LOC = -1;
    int LOCP = -1;
    findLOCandLOCP(item,LOC,LOCP);
    deleteAfterIdx(LOC,LOCP);
    return;
}


// To count the number of elements in the Circular Linked List

int CircularLinkedList::count(){
    return size;
}