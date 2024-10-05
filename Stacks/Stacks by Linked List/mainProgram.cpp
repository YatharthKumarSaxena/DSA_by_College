#include "FunctionsOfStack.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore Stack by 'One way'/'Singly' Linked List\n";
    int size;
    cout<<"Please enter the maximum size of your Stack = ";
    cin>>size;
    // Array of unused memory cells let say AVAIL Stack consist of INFO part and LINK part
    int INFO[size]; // A list that contains Data of Stack
    int LINK[size]; // A list that contains address of bottom element of Stack
    int AVAIL = 0; // AVAIL Pointer
    int START = INT_MIN; // Start pointer of Stack currently points to NULL
    for(int i=0;i<size;i++){
        // Example LINK[0] = 1 points to 1st index of INFO array
        LINK[i] = i+1; // Linking Link element value to the next index of INFO element
    }

    /* !! Don't Edit the Above code otherwise program will malfunction !! */


    // Sample Code written so that you can understand how to implement these functions
    cout<<top(INFO,START)<<" ";
    push(1,INFO,LINK,size,AVAIL,START);
    cout<<top(INFO,START)<<" ";
    push(2,INFO,LINK,size,AVAIL,START);
    cout<<top(INFO,START)<<" ";
    push(3,INFO,LINK,size,AVAIL,START);
    cout<<top(INFO,START)<<" ";
    push(4,INFO,LINK,size,AVAIL,START);
    cout<<top(INFO,START)<<endl;
    print(INFO,LINK,START);
    cout<<top(INFO,START)<<" ";
    cout<<"Stack is empty :- ";
    cout<<isEmpty(START)<<endl;
    cout<<"Stack is full :- ";
    cout<<isFull(AVAIL,size)<<endl;
    cout<<pop(INFO,LINK,START,AVAIL)<<endl;
    print(INFO,LINK,START);
    cout<<pop(INFO,LINK,START,AVAIL)<<endl;
    print(INFO,LINK,START);
    cout<<pop(INFO,LINK,START,AVAIL)<<endl;
    print(INFO,LINK,START);
    cout<<pop(INFO,LINK,START,AVAIL)<<endl;
    print(INFO,LINK,START);
    cout<<"Stack is empty :- ";
    cout<<isEmpty(START)<<endl;
    cout<<"Stack is full :- ";
    cout<<isFull(AVAIL,size)<<endl;
}