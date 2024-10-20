#include <stack>
#include "partitionAlgorithm.cpp"
void quickSort(int arr[],int N){
    stack<int>Lower;
    stack<int>Upper;
    int Beg;
    int End;
    int LOC;
    if(N>1){
        Lower.push(0);
        Upper.push(N-1);
    }
    while(Lower.size() && Upper.size()){
        Beg = Lower.top();
        End = Upper.top();
        Lower.pop();
        Upper.pop();
        partition(arr,N,Beg,End,LOC);
        if(Beg < LOC-1){
            Lower.push(Beg);
            Upper.push(LOC-1);
        }
        if(LOC+1 < End){
            Lower.push(LOC+1);
            Upper.push(End);
        }
    }
}