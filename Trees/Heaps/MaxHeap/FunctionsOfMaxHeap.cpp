#include "MaxHeapClass.cpp"
#include <iostream>
#include <climits>
using namespace std;

// Insert Item in the MaxHeap
void MaxHeap::insert(int item){
    // Checking Overflow Condition
    if(idx>=capacity-1){
        cout<<"Overflow Error\n";
        return;
    }
    idx++;
    heap[idx]=item; // Stores the value at last index
    // Reaching the actual place of item by swapping with it's parent node
    int tempIdx = idx;
    while(true){
        if(tempIdx == 1)return;
        if(heap[tempIdx]<=heap[tempIdx/2]){
            return;
        }
        else{
            swap(heap[tempIdx],heap[tempIdx/2]);
            tempIdx /= 2;
        }
    }
    return;
}

// Remove the maximum element from the Maxheap and returns it's value
int MaxHeap::removeMaxEle(){
    // Checking Underflow condition
    if(idx == 0){
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    int temp = heap[1];
    int last = heap[idx];
    heap[1] = last;
    idx--;
    // Rearranging the Maxheap Structure
    // Pointer Initialization
    int ptr = 1;
    int left = 2;
    int right = 3;
    while(right <= idx){
        if((heap[left]<=last) && (heap[right]<=last)){
            break;
        }
        // Updating pointer
        if(heap[left]>=heap[right]){ // If left is greater than right then set left as parent value of right
            heap[ptr]=heap[left];
            ptr = left;
        }
        // Updating Pointer
        else{ // If right is greater than right then set left as parent value of left
            heap[ptr]=heap[right];
            ptr = right;
        }
        // Updating left and right pointer
        left = 2*ptr;
        right = 2*ptr+1;
    }
    if((last<heap[left]) && (left == idx)){
        heap[ptr] = heap[left];
        heap[left] = last;
    }
    else{
        heap[ptr] = last;
    }
    return temp;
}

// Returns the Maximum Element of the MaxHeap
int MaxHeap::getMax(){
    // Checking Underflow Condition
    if(idx == 0){
        cout<<"Underflow error\n";
        return INT_MIN;
    }
    return heap[1];
}

// Returns the current size of the MaxHeap
int MaxHeap::size(){
    return idx;
}

// Display Compltete Maxheap but LevelWise
void MaxHeap::displayMaxHeapByLevelOrderTravesal(){
    int checkPoint = -1;
    int space = 0;
    for(int i=1;i<=idx;i++){
        cout<<heap[i]<<' ';
        checkPoint++;
        if(space == checkPoint){
            if(space==0)space += 2;
            else space += (space * 2);
            cout<<endl;
        }
    }
    return;
}