#include "class.cpp"

void LinkedList::insertNode(int val){
    cout << "Value " << val << " inserted successfully" << endl;
    ListNode* temp = new ListNode(val);
    if(Head == NULL){
        Head = temp;
        size++;
        return;
    }
    temp->next = Head;
    Head = temp;
    size++;
    return;
}

void LinkedList::deleteNode(int val){
    ListNode* temp = Head;
    if(temp->val == val){
        Head = Head->next;
        size--;
        return;
    }
    while(temp && temp->next && temp->next->val != val){
        temp = temp->next;
    }
    if(temp){
        if(temp->next && temp->next->val == val){
            temp->next = temp->next->next;
            size--;
            return;
        }
    }
    cout << "No Node with value " << val << " exists in LinkedList" << endl;
    return;
}

bool LinkedList::searchValue(int val){
    ListNode* temp = Head;
    while(temp && temp->val!=val){
        temp=temp->next;
    }
    if(temp)return true;
    return false;
}

void LinkedList::display(){
    ListNode* temp = Head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int LinkedList::currSize(){
    return size;
}