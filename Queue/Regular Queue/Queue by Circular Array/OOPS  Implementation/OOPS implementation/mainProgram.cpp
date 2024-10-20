#include "FunctionsOfRegularQueueByCircularArray.cpp"
/* !! Don't Edit the above code in this file otherwise program will malfunction !! */
int main(){

    // Sample Code written so that you can understand how to implement these functions
    Queue q(2);
    cout<<q.isEmpty();
    cout<<q.isFull();
    q.print();
    q.push(1);
    cout<<q.isEmpty();
    cout<<q.isFull();
    q.push(2);
    cout<<q.isEmpty();
    cout<<q.isFull();
    q.print();
    q.push(0);
    return 0;
}