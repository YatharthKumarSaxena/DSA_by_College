// To create a sorted circular linked list use only insertInSorted function for insertion

#include "FunctionsOfCLL.cpp"
int main(){
    int size;
    cout<<"Please enter the maximum size of your Linked List = ";
    cin>>size;
    // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
    int currSize = 0;
    int INFO[size+1]; // A list that contains Data of Linked List
    int LINK[size+1]; // A list that contains address of next element
    int AVAIL = 1; // AVAIL Pointer
    int START = 0; // Start pointer of Linked list currently points to NULL
    INFO[0] = 0;
    LINK[0] = 0;
    for(int i=1;i<=size;i++){
        // Example LINK[0] = 1 points to 1st index of INFO array
        LINK[i] = i+1; // Linking Link element value to the next index of INFO element
    }
    print(INFO,LINK,START);
    insertInSorted(4,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(-1,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(2,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(-4,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(5,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(9,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(8,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(0,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(19,INFO,LINK,size,AVAIL,START,currSize);
    insertInSorted(456,INFO,LINK,size,AVAIL,START,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,8,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,0,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,4,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,456,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,-4,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,-1,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,2,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,5,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,19,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    deleteItem(INFO,LINK,START,AVAIL,9,currSize);
    print(INFO,LINK,START);
    cout<<endl;
    return 0;
}