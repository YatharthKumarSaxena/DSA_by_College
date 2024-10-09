#include "FunctionsOfRegularQueueByLL.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore Regular Queue functions using One way Linked List\n";
    int size;
    cout<<"Please enter the maximum size of your Regular Queue = ";
    cin>>size;
    // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
    int INFO[size]; // A list that contains Data of Regular Queue
    int LINK[size]; // A list that contains address of next element
    int AVAIL = 0; // AVAIL Pointer
    int FRONT = INT_MIN; // Front Pointer of Regular Queue currently points to NULL
    int REAR = INT_MIN; // Rear Pointer of Regular Queue currently points to NULL
    for(int i=0;i<size;i++){
        // Example LINK[0] = 1 points to 1st index of INFO array
        LINK[i] = i+1; // Linking Link element value to the next index of INFO element
    }

    /* !! Don't Edit the Above code otherwise program will malfunction !! */


    // Sample Code written so that you can understand how to implement these functions
    print(INFO,LINK,FRONT);
    cout<<"Empty ? :- "<<isEmpty(FRONT)<<endl;
    cout<<"Full ? :- "<<isFull(INFO,LINK,FRONT,size)<<endl;
    cout<<"Current Size :- "<<count(INFO,LINK,FRONT);
    cout<<endl;
    push(1,INFO,LINK,size,AVAIL,FRONT,REAR);
    cout<<"Empty ? :- "<<isEmpty(FRONT)<<endl;
    cout<<"Full ? :- "<<isFull(INFO,LINK,FRONT,size)<<endl;
    cout<<"Current Size :- "<<count(INFO,LINK,FRONT);
    cout<<endl;
    push(2,INFO,LINK,size,AVAIL,FRONT,REAR);
    cout<<"Current Size :- "<<count(INFO,LINK,FRONT);
    cout<<endl;
    push(3,INFO,LINK,size,AVAIL,FRONT,REAR);
    cout<<"Current Size :- "<<count(INFO,LINK,FRONT);
    cout<<endl;
    push(4,INFO,LINK,size,AVAIL,FRONT,REAR);
    cout<<"Current Size :- "<<count(INFO,LINK,FRONT);
    cout<<endl;
    print(INFO,LINK,FRONT);
    cout<<endl;
    cout<<"Empty ? :- "<<isEmpty(FRONT)<<endl;
    cout<<"Full ? :- "<<isFull(INFO,LINK,FRONT,size)<<endl;
    cout<<"Front :- "<<front(INFO,FRONT)<<" Rear :- "<<rear(INFO,REAR);
    pop(INFO,LINK,FRONT,REAR,AVAIL);
    cout<<endl;
    cout<<"Front :- "<<front(INFO,FRONT)<<" Rear :- "<<rear(INFO,REAR);
    cout<<endl<<"Current Size :- "<<count(INFO,LINK,FRONT)<<endl;
    print(INFO,LINK,FRONT);
    pop(INFO,LINK,FRONT,REAR,AVAIL);
    cout<<endl;
    cout<<"Front :- "<<front(INFO,FRONT)<<" Rear :- "<<rear(INFO,REAR);
    cout<<endl<<"Current Size :- "<<count(INFO,LINK,FRONT)<<endl;
    print(INFO,LINK,FRONT);
    pop(INFO,LINK,FRONT,REAR,AVAIL);
    cout<<endl;
    cout<<"Empty ? :- "<<isEmpty(FRONT)<<endl;
    cout<<"Full ? :- "<<isFull(INFO,LINK,FRONT,size)<<endl;
    cout<<"Front :- "<<front(INFO,FRONT)<<" Rear :- "<<rear(INFO,REAR);
    cout<<endl<<"Current Size :- "<<count(INFO,LINK,FRONT)<<endl;
    print(INFO,LINK,FRONT);
    return 0;
}