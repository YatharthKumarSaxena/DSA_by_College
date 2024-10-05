// Definition of class Stack
class Stack{
    // Data Members
    int* Top;
    int size;
    int arr[];
public:
    //Parameterized Constructor
    Stack(int size){
        *Top = -1;
        this->size = size;
        arr[size];
    }
    //Member Functions
    void push(int item);
    int pop();
    int top();
    bool isEmpty();
    bool isFull();
    void print();
};