#include "..\MinHeap\FunctionsOfMinHeap.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to sort an array using Heapify Algorithm by minheap\n";
    cout<<"Please enter the size of the array = ";
    int N;
    cin>>N;
    int arr[N];
    MinHeap minHeap(N);
    cout<<"Please enter the elements of your array given below :- \n";
    for(int i=0;i<N;i++){
        cout<<"Please enter the "<<i+1<<" Element of the array = ";
        cin>>arr[i];
    }
    cout<<"Your array looks like :- {";
    // Heapify Algorithm
    for(int i=0;i<N;i++){
        if(i<N-1)cout<<arr[i]<<",";
        else cout<<arr[i]<<"}";
        minHeap.insert(arr[i]);
    }
    for(int i=0;i<N;i++){
        int val = minHeap.removeMinEle();
        arr[i] = val;
    }
    cout<<"\nAfter Heapify Algorithm by minheap your array looks like :- \n{";
    for(int i=0;i<N;i++){
        if(i<N-1)cout<<arr[i]<<",";
        else cout<<arr[i]<<"}";
    }
}