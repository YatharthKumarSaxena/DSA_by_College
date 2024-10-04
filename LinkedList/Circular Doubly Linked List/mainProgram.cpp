// To create a sorted circular doubly linked list use only insertInSorted function for insertion

#include "FunctionsOfCDLL.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore circular singly Linked List\n";
    int size;
    cout<<"Please enter the maximum size of your Linked List = ";
    cin>>size;
    // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
    int currSize = 0;
    int INFO[size+1]; // A list that contains Data of Linked List
    int FORW[size+1]; // A list that contains address of next element
    int BACK[size+1]; // A list that contains address of previous element
    int AVAIL = 1; // AVAIL Pointer
    int START = 0; // Start pointer of Linked list currently points to NULL
    INFO[0] = 0;
    FORW[0] = 0;
    BACK[0] = 0;
    for(int i=1;i<=size;i++){
        // Example FORW[1] = 2 points to 2nd index of INFO array
        FORW[i] = i+1; // Linking FORW element value to the next index of INFO element
        // Example FORW[1] = 0 points to 0th index of INFO array
        BACK[i] = i-1; // Linking BACK element value to the previous index of INFO element
    }
    insertInSorted(2,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(0,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(8,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(-1,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(12,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(20,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(-676,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(675,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(-98787,INFO,FORW,BACK,size,AVAIL,START,currSize);
    insertInSorted(1786786,INFO,FORW,BACK,size,AVAIL,START,currSize);
    print(INFO,FORW,START);
}