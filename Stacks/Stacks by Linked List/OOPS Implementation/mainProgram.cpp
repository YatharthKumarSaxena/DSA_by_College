#include "FunctionsOfStack.cpp"

int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore Stack by 'One way'/'Singly' Linked List\n";
    int size;
    cout<<"Please enter the maximum size of your Stack = ";
    cin>>size;
    Stack st(size);

    /* !! Don't Edit the Above code otherwise program will malfunction !! */


    // Sample Code written so that you can understand how to implement these functions
    cout<<st.isFull();
    st.push(5);
    cout<<st.isFull()<<endl;
    st.print();
    st.push(4);
    st.print();
    st.push(3);
    cout<<st.isEmpty()<<endl;
    st.print();
    st.push(2);
    st.print();
    st.push(1);
    st.print();
    cout<<st.isFull()<<endl;
    cout<<st.pop();
    st.print();
    cout<<st.isFull()<<endl;
    cout<<st.pop();
    st.print();
    cout<<st.isFull()<<endl;
    cout<<st.pop();
    st.print();
    cout<<st.pop();
    st.print();
    cout<<st.pop();
    st.print();
    cout<<st.isEmpty();
    return 0;
}