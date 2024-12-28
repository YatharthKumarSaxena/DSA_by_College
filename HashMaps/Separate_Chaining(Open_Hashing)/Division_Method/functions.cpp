#include "class.cpp"

bool SeparateChaining::searchVal(int val){
    int loc = locOfOperation(val);
    bool result = arr[loc]->searchValue(val);
    return result;
}

void SeparateChaining::insertVal(int val){
    int loc = locOfOperation(val);
    arr[loc]->insertNode(val);
}

void SeparateChaining::deleteVal(int val){
    if(this->size() == 0){
        cout<<"Underflow error\n";
        cout<<"Hashmap is empty\n";
        return;
    }
    int loc = locOfOperation(val);
    arr[loc]->deleteNode(val);
}

void SeparateChaining::displayMap(){
    cout<<"Your HashMap looks as given below:- \n";
    for(int i=0;i<capacity;i++){
        arr[i]->display();
    }
}

int SeparateChaining::totalSlotsInHashMap(){
    return this->capacity;
}

int SeparateChaining::size(){
    int totalSize = 0;
    for(int i=0;i<capacity;i++){
        totalSize += arr[i]->currSize();
    }
    return totalSize;
}