#include "FunctionsOfMaxHeap.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore the functionalities of minheap\n";
    // Don't edit the above code otherwise program will malfunction
    // Sample Code written for your understanding on how to implement these function
    MaxHeap hp(7);
    hp.insert(1);
    hp.insert(2);
    hp.insert(3);
    hp.insert(4);
    hp.insert(5);
    hp.insert(6);
    hp.insert(7);
    hp.insert(7);
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMaximum element :- "<<hp.getMax()<<endl;
    cout<<"Maximum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMaximum element :- "<<hp.getMax()<<endl;
    cout<<"Maximum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMaximum element :- "<<hp.getMax()<<endl;
    cout<<"Maximum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMaximum element :- "<<hp.getMax()<<endl;
    cout<<"Maximum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMaximum element :- "<<hp.getMax()<<endl;
    cout<<"Maximum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMaximum element :- "<<hp.getMax()<<endl;
    cout<<"Maximum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMinimum element :- "<<hp.getMax()<<endl;
    cout<<"Minimum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
    cout<<"\nMaximum element :- "<<hp.getMax()<<endl;
    cout<<"Maximum element that is deleted:- "<<hp.removeMaxEle();
    cout<<"\nLevel order traversal is given below :- \n";
    hp.displayMaxHeapByLevelOrderTravesal();
}