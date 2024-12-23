// Note:- INT_MIN is used to represent NULL here
// Note:- Here Complete Binary Tree is constructed 

#include <iostream>
#include <climits>
using namespace std;

class BinaryTree{
    // Data Member
    int* tree;
    int root;   // Points to root node
    int last;   // Points to last Node
    int size;   // Maximum Capacity of Tree
public:

    // Parameterized Constructor
    BinaryTree(int size){
        this->size = size+1;
        tree = new int[size+1];
        root = 1;
        last = 1;
        // Root points to NULL
        tree[1] = INT_MIN;  // INT_MIN points to NULL here
    }

    // Member Function
    int info(int n);
    void insert(int val);
    int leftChild(int n);
    int rightChild(int n);
    void makeEmpty();
    int currSize();
    int father(int n);
    void sibling(int n);
    void preOrder(int ptr);
    void inOrder(int ptr);
    void postOrder(int ptr);
    int removeNthNode(int n);
    void displayCBT();
};