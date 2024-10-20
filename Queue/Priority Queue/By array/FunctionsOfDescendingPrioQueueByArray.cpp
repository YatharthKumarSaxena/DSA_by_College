// Descending Priority Queue
#include "PrioQueue_Class.cpp"
// Insertion Function at back
void PrioQueue::push(int value) {
    if (size == capacity) {
        cout << "Queue is full!" << endl;
        return;
    }
    arr[size] = value; // Insert at the end
    size++;
    // Reorder to maintain ascending order
    for (int i = size - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1]) {
            swap(arr[i], arr[i - 1]);
        } else {
            break;
        }
    }
}
// Deletion Function at front
int PrioQueue::pop() {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int highestPriority = arr[0]; // Smallest element
    for (int i = 1; i < size; i++) {
        arr[i - 1] = arr[i];
    }
    size--;
    return highestPriority;
}
// Printing elements of Priority Queue
void PrioQueue::print() {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Priority Queue: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Printing elements of Priority Queue in reverse order
void PrioQueue::printReverse() {
    if (size == 0) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Priority Queue: ";
    for (int i = size-1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Checking emptyness of priority queue
bool PrioQueue::isEmpty(){
    return (size == 0);
}
// Checking priority queue is full
bool PrioQueue::isFull(){
    return (size == capacity);
}
// Returning front element of priority queue
int PrioQueue::front(){
    if(size == 0){
        cout<<"Underflow error\n";
        return -1;
    }
    return arr[0];
}
// Returning front element of priority queue
int PrioQueue::rear(){
    if(size == 0){
        cout<<"Underflow error\n";
        return -1;
    }
    return arr[size-1];
}