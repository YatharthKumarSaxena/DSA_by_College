#include "FunctionsOfLL.cpp"
using namespace std;
int main(){
    cout<<"Please enter the size of the linked list = ";
    int size;
    cin>>size;
    LL ll(size);
    ll.print();
    ll.insertAtEnd(56);
    ll.insertAtEnd(56);
    ll.insertAtEnd(56);
    ll.insertAtEnd(56);
    ll.print();
}