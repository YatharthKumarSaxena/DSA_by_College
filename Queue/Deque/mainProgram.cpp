#include "FunctionsOfDeque.cpp"
/* !! Don't Edit the above code in this file otherwise program will malfunction !! */
int main(){
    //Sample Code written for your understanding
    Deque q(5);
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.pushFront(1);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.pushFront(2);
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.pushFront(3);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.pushFront(4);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.pushBack(5);
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    q.pushBack(5);
    q.pushFront(2);
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.print();
    q.printReverse();
    q.popFront();
    q.print();
    q.printReverse();
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.popFront();
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
    q.print();
    q.printReverse();
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.popFront();
    q.print();
    q.printReverse();
    cout<<"Front Element :- "<<q.front()<<" Rear Element "<<q.rear()<<endl;
    q.popFront();
    q.print();
    q.printReverse();
    q.popFront();
    q.print();
    q.printReverse();
    q.popFront();
    q.popBack();
    cout<<"Is full ? :- "<<q.isFull()<<" Is empty ? :- "<<q.isEmpty()<<endl;
}