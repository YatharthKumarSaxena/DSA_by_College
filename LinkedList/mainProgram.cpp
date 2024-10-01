// To create a sorted linked list use only insertInSorted function for insertion

#include "FunctionsOfLL.cpp"
int main(){
    int size;
    cout<<"Please enter the maximum size of your Linked List = ";
    cin>>size;
    // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
    int INFO[size]; // A list that contains Data of Linked List
    int LINK[size]; // A list that contains address of next element
    int AVAIL = 0; // AVAIL Pointer
    int START = INT_MIN; // Start pointer of Linked list currently points to NULL
    for(int i=0;i<size;i++){
        // Example LINK[0] = 1 points to 1st index of INFO array
        LINK[i] = i+1; // Linking Link element value to the next index of INFO element
    }
    print(INFO,LINK,START);
    insertInSorted(4,INFO,LINK,size,AVAIL,START);
    insertInSorted(1,INFO,LINK,size,AVAIL,START);
    insertInSorted(2,INFO,LINK,size,AVAIL,START);
    insertInSorted(3,INFO,LINK,size,AVAIL,START);
    insertInSorted(8,INFO,LINK,size,AVAIL,START);
    deleteAtHead(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    return 0;
}