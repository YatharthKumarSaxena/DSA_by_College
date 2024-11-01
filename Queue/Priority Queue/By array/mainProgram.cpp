// Intrinsic Priority Queue implementation by array


// You can see implementation of Descending Priority Queue in this file as well 
/* To see implementation of Descending Priority Queue 
   Replace "FunctionsOfAscendingPrioQueueByArray.cpp" by "FunctionsOfDescendingPrioQueueByArray.cpp*/
#include "FunctionsOfAscendingPrioQueueByArray.cpp" 
int main(){
    //Sample Code written for your understanding
    PrioQueue q(5);
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.push(1);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.push(2);
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.push(3);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.push(4);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.push(5);
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    q.push(5);
    q.push(2);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.pop();
    q.print();
    q.printReverse();
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.pop();
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    q.print();
    q.printReverse();
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.pop();
    q.print();
    q.printReverse();
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.pop();
    q.print();
    q.printReverse();
    q.pop();
    q.print();
    q.printReverse();
    q.pop();
    q.pop();
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    return 0;
}