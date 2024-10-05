#include "FunctionsOfStack.cpp"
int main(){
    /* !! Don't Edit the Above code otherwise program will malfunction !! */


    // Sample Code written so that you can understand how to implement these functions
    Stack st(5);
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
}