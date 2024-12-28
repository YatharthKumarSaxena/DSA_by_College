#include <iostream>
using namespace std;

class ListNode{
public:
    // Data Members
    int val;
    ListNode* next;
    // Parameterized Constructor
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
    // Data Members
    ListNode* Head;
    int size;
public:
    // Parameterized Constructor
    LinkedList(){
        this->Head = NULL;
        this->size = 0;
    }
    // Member Functions
    void insertNode(int val);
    void deleteNode(int val);
    bool searchValue(int val);
    void display();
    int currSize();
};

