#include "FunctionsOfMinHeap.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore the functionalities of minheap\n";
    // Don't edit the above code otherwise program will malfunction
    // Sample Code written for your understanding on how to implement these function
    MinHeap hp(7);
    hp.insert(1);
    hp.insert(2);
    hp.insert(3);
    hp.insert(4);
    hp.insert(5);
    hp.insert(6);
    hp.insert(7);
    hp.insert(7);
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMin()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMinEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMinHeapByLevelOrderTravesal();
}