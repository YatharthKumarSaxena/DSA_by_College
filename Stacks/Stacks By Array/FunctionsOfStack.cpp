#include "Stack_Class.cpp"
#include <climits>
#include <iostream>
using namespace std;


// Insertion Function at top of the stack

void Stack::push(int item){
    // Checking Overflow Condition
    if(Top == size-1){
        cout<<"Overflow error\n";
        return;
    }
    Top += 1; // Update Top 
    arr[Top] = item; // Insertion of item
    return;
}


// Deletion function at top of the stack and returning the deleted item value

int Stack::pop(){
    // Checking Underflow error
    if(Top == -1){ // Checking Top == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    Top -= 1; // Update Top 
    return arr[Top+1];
}


// Printing of Stack elements from top to bottom

void Stack::print(){
    // Checking Underflow error
    if(Top == -1){ // Checking Top == NULL
        cout<<"Underflow error\n";
        return;
    }
    cout<<"The stack elements from top to bottom looks like :- ";
    for(int i=Top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


// Function to return top element of stack

int Stack::top(){
    // Checking Underflow error
    if(Top == -1){ // Checking Top == NULL
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    return arr[Top];
}


// Checking the emptyness of the Stack

bool Stack::isEmpty(){
    return (Top == -1);
}


// Checking a stack is full

bool Stack::isFull(){
    return (Top == size-1);
}