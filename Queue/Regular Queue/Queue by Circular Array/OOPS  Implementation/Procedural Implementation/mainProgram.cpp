#include "FunctionsOfRegularQueue.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore the functionalities of the regular queue\n";
    cout<<"Procedural Programming is used here\n";
    cout<<"Please enter the maximum size of the array = ";
    int size;
    cin>>size;
    int FRONT = -1; // FRONT Pointer initially Points to NULL
    int REAR = -1; // REAR Pointer initially Points to NULL
    int queue[size]; // Queue array is declared

    
    /* !! Don't Edit the Above code otherwise program will malfunction !! */

    
    // Sample Code written for your understanding
    print(FRONT,REAR,size,queue);
    rear(REAR,queue);
    cout<<endl;
    front(FRONT,queue);
    cout<<"Is Full :- "<<isFull(FRONT,REAR,size)<<endl;
    cout<<"Is Empty :- "<<isEmpty(FRONT)<<endl;
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    push(1,FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    push(2,FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    push(3,FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    push(4,FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    push(5,FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    cout<<"Is Full :- "<<isFull(FRONT,REAR,size)<<endl;
    cout<<"Is Empty :- "<<isEmpty(FRONT)<<endl;
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
    print(FRONT,REAR,size,queue);
    pop(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    print(FRONT,REAR,size,queue);
    cout<<"Is Full :- "<<isFull(FRONT,REAR,size)<<endl;
    cout<<"Is Empty :- "<<isEmpty(FRONT)<<endl;
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
    pop(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    push(10,FRONT,REAR,size,queue);
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
    print(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
    pop(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    push(14,FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    print(FRONT,REAR,size,queue);
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    pop(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    print(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
    pop(FRONT,REAR,size,queue);
    print(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
    pop(FRONT,REAR,size,queue);
    print(FRONT,REAR,size,queue);
    cout<<"Current Size :- "<<currSize(FRONT,REAR,size)<<endl;
    cout<<"Front element :- "<<front(FRONT,queue)<<endl;
    cout<<"Rear element :- "<<rear(REAR,queue)<<endl;
}