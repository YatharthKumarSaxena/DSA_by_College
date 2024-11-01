// Descending Priority Queue Program
#include "FunctionsOfPrioQueue.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore functionalities of Descending Priority Queue\n";
    int size;
    cout<<"Please enter the maximum size of your Priority Queue = ";
    cin>>size;
    // Array of unused memory cells let say AVAIL list consist of INFO part and LINK part
    string INFO[size]; // A list that contains Data of Priority Queue
    int LINK[size]; // A list that contains address of next element
    int PRN[size];
    int AVAIL = 0; // AVAIL Pointer
    int START = INT_MIN; // Start pointer of Priority Queue currently points to NULL
    for(int i=0;i<size;i++){
        // Example LINK[0] = 1 points to 1st index of INFO array
        LINK[i] = i+1; // Linking Link element value to the next index of INFO element
        PRN[i] = -1;
    }

    /* !! Don't Edit the Above code otherwise program will malfunction !! */

    // Sample Code written for your understanding
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Is full :- "<<isFull(LINK,START,size)<<endl;
    cout<<"Is empty :- "<<isEmpty(START)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    push("AAA",1,INFO,LINK,PRN,size,AVAIL,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    cout<<"Is full :- "<<isFull(LINK,START,size)<<endl;
    cout<<"Is empty :- "<<isEmpty(START)<<endl;
    push("BBB",1,INFO,LINK,PRN,size,AVAIL,START);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    push("CCC",3,INFO,LINK,PRN,size,AVAIL,START);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    push("DDD",4,INFO,LINK,PRN,size,AVAIL,START);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    push("EEE",1,INFO,LINK,PRN,size,AVAIL,START);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    push("FFF",1,INFO,LINK,PRN,size,AVAIL,START);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    push("GGG",3,INFO,LINK,PRN,size,AVAIL,START);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    push("HHH",4,INFO,LINK,PRN,size,AVAIL,START);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Is full :- "<<isFull(LINK,START,size)<<endl;
    cout<<"Is empty :- "<<isEmpty(START)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    cout<<"Is full :- "<<isFull(LINK,START,size)<<endl;
    cout<<"Is empty :- "<<isEmpty(START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    pop(INFO,LINK,START,AVAIL);
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Current Size = "<<count(LINK,START)<<endl;
    print(INFO,LINK,START);
    cout<<"Front element :- "<<front(START,INFO)<<endl;
    cout<<"Rear element :- "<<rear(START,INFO,LINK)<<endl;
    cout<<"Is full :- "<<isFull(LINK,START,size)<<endl;
    cout<<"Is empty :- "<<isEmpty(START)<<endl;
}