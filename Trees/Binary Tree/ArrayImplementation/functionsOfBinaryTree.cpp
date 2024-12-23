#include "BinaryTreeClass.cpp"
void BinaryTree::insert(int val){
    // Overflow Condition
    if(last>=size){
        cout<<"Overflow error\n";
        return;
    }
    tree[last++] = val;
}
int BinaryTree::info(int n){
    // Underflow Error
    if(last == 1 || n<1){
        cout<<"Underflow Error\n";
        return INT_MIN;
    }
    // Overflow Condition
    else if(n>=size){
        cout<<"Overflow error\n";
        return INT_MIN;
    }
    // if value at node exists
    else if(n<last) return tree[n];
    return INT_MIN;  // Points that value is not inserted at this place
}
void BinaryTree::makeEmpty(){
    root = 1; // Set root to 1
    tree[root] = INT_MIN; // Set root to null
    last = 1; // Set last node as 1
}
int BinaryTree::currSize(){
    return last-root;
}
int BinaryTree::leftChild(int n){
    // Underflow Error
    if(last == 1 || n<1){
        cout<<"Underflow Error\n";
        return INT_MIN;
    }
    else if(2*n<last){
        return 2*n;
    }
    // Node Does not Exist
    cout<<"Node Does not exit\n";
    return INT_MIN;
}
int BinaryTree::rightChild(int n){
    // Underflow Error
    if(last == 1 || n<1){
        cout<<"Underflow Error\n";
        return INT_MIN;
    }
    else if(2*n+1<last){
        return 2*n+1;
    }
    // Node Does not Exist
    cout<<"Node Does not exit\n";
    return INT_MIN;
}
int BinaryTree::father(int n){
    if(last == 1 || n<1){
        cout<<"Underflow Error\n";
        return INT_MIN;
    }
    else if(n == 1){
        cout<<"You are at the Root node of Binary Tree\n";
        cout<<"So no father node exists for root node\n";
        return INT_MIN;
    }
    else if(n/2 < last){
        return n/2;
    }
    // nth Node as well as father node of nth node of binary tree does not exist 
    cout<<"Father Node does not exist for the "<<n<<"th node\n";
    return INT_MIN;
}
void BinaryTree::sibling(int n){
    // Underflow Error
    if(last == 1 || n<1){
        cout<<"Underflow Error\n";
    }
    int check = n/2;
    if(check<last){
        if(2*check == n){
            cout<<"Node entered by you is left node of sub binary tree\n";
            if(n < last) cout<<"Right Sibling Exist at Location:- "<<2*check+1<<endl;
            else cout<<"Right Sibling Exist but it is a NULL node as "<<n<<"th node i.e its left sibling is NULL node\n";
        }
        else{
            cout<<"Node entered by you is right node of sub binary tree\n";
            if(n < last) cout<<"Left Sibling Exist at Location:- "<<2*check<<endl;
            else if (n-1 < last ) cout<<"Left Sibling Exist but it's "<<n<<"th node i.e its right sibling is NULL node\n";
            else cout<<" Left Sibling is Null Node\n";
        }
    }
    else{
        cout<<"Father Node of "<<n<<"th node does not exist\n";
        cout<<"Hence No Sibling Possible\n";
    }
}
void BinaryTree::preOrder(int ptr){
    if(ptr>=last)return;
    cout<<tree[ptr]<<' ';   // Print root value
    preOrder(2*ptr);    // Go to left
    preOrder(2*ptr+1);  // Go to right
}
void BinaryTree::inOrder(int ptr){
    if(ptr>=last)return;
    inOrder(2*ptr);    // Go to left
    cout<<tree[ptr]<<' ';   // Print root value
    inOrder(2*ptr+1);     // Go to right
}
void BinaryTree::postOrder(int ptr){
    if(ptr>=last)return;
    postOrder(2*ptr);    // Go to left
    postOrder(2*ptr+1);      // Go to right
    cout<<tree[ptr]<<' ';   // Go to right
}
int BinaryTree::removeNthNode(int n){
    // Underflow Error
    if(last == 1 || n<1){
        cout<<"Underflow Error\n";
        return INT_MIN;
    }
    // When Node does not exist in Binary Tree
    else if(n>=last){
        cout<<"Node does not exist\n";
        return INT_MIN;
    }
    // When Last Node is deleted
    else if(n==last-1){
        int LOC = last-1;
        last-=1;
        return tree[LOC];
    }
    // Replace deleted node by last node
    int val = tree[n];
    tree[n] = tree[last-1];
    last -= 1;
    return val;
}
// Display Compltete Binary Tree but LevelWise
void BinaryTree::displayCBT(){
    int checkPoint = -1;
    int space = 0;
    for(int i=1;i<last;i++){
        cout<<tree[i]<<' ';
        checkPoint++;
        if(space == checkPoint){
            if(space==0)space += 2;
            else space += (space * 2);
            cout<<endl;
        }
    }
    return;
}