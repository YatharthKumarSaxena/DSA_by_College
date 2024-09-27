// Linked List Implementation using three arrays without pointers
// Note INT_MIN is used as NULL
#include <iostream>
#include <climits>
using namespace std;
// Insertion at Beginning
void insertAtHead(int item,int INFO[],int LINK[],int size,int &AVAIL,int &START){
    // Checking Avail == NULL OR Overflow Condition check
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    // Removing first node from avail list
    int New  = AVAIL;
    AVAIL = LINK[AVAIL];
    // Attaching Node at beginning 
    INFO[New] = item; // Insertion of item
    LINK[New] = START; // Linking of New to START
    START = New; // Update START
    return;
}
// Insertion at end
void insertAtEnd(int item,int INFO[],int LINK[],int &START,int &AVAIL,int size){
    // Checking Overflow Condition
    if(AVAIL >= size){
        cout<<"Overflow error\n";
        return;
    }
    int PTR = START; // Initialises Pointer
    // Removing Node from AVAIL list
    int New = AVAIL;
    AVAIL = LINK[AVAIL];
    // Updating item in info array
    INFO[New] = item;
    // Special Case
    if(PTR == INT_MIN){
        START = New;
        LINK[START] = INT_MIN;
        return;
    }
    // Attaching Node at end
    while(LINK[PTR] != INT_MIN){
        PTR = LINK[PTR]; // Updating pointer
    }
    // Linking Last Node to new node
    LINK[PTR] = New;
    // Set New Node pointer points to NULL
    LINK[New] = INT_MIN;
    return;
}
// Printing of Linked list
void print(int INFO[],int LINK[],int START){
    // Checking Underflow Condition
    if(START == INT_MIN){
        cout<<"Underflow error\n";
        return;
    }
    int PTR = START; // Initialises pointer
    // Repeat Step 27 And 28 Until PTR == NULL
    while(PTR != INT_MIN){ // Checking PTR == NULL 
        cout<<INFO[PTR]<<" "; // Write
        PTR = LINK[PTR]; // Update Pointer
    }
    return;
}
// To count the total number of elements in the linked list
int count(int INFO[],int LINK[],int START){
    int size = 0; // Initialises Counter 
    int PTR = START; // Initalises pointer
    // Repeat Step 40 and 41 until PTR == NULL
    while(PTR != INT_MIN){
        size++; // Incrementing Counter
        PTR = LINK[PTR];
    }
    return size;
}
int search(int item,int INFO[],int LINK[],int START){
    int PTR = START; // Initialises Pointer
    // Repeat Step 52 until PTR == NULL && INFO[PTR] = item
    while(PTR != INT_MIN && INFO[PTR] != item){ 
        PTR = LINK[PTR]; // Update pointer
    }
    int LOC = PTR; // return index of INFO array whose value is item
    // If search unsuccessfull then INT_MIN value is returned
    return LOC;
}
int main(){
    int n;
    cout<<"Please enter the maximum size of your Linked List = ";
    cin>>n;
    // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
    int INFO[n]; // A list that contains Data of Linked List
    int LINK[n]; // A list that contains address of next element
    int AVAIL = 0; // AVAIL Pointer
    int START = INT_MIN; // Start pointer of Linked list currently points to NULL
    for(int i=0;i<n;i++){
        // Example LINK[0] = 1 points to 1st index of INFO array
        LINK[i] = i+1; // Linking Link element value to the next index of INFO element
    }
    print(INFO,LINK,START);
    insertAtEnd(1,INFO,LINK,START,AVAIL,n);
    insertAtEnd(2,INFO,LINK,START,AVAIL,n);
    insertAtEnd(3,INFO,LINK,START,AVAIL,n);
    insertAtEnd(4,INFO,LINK,START,AVAIL,n);
    insertAtHead(5,INFO,LINK,n,AVAIL,START);
    print(INFO,LINK,START);
    int idx = search(1,INFO,LINK,START);
    cout<<idx;
    return 0;
}