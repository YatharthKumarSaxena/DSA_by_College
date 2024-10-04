// To create a sorted doubly linked list use only insertInSorted function for insertion

#include "FunctionsOfDLL.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"This program is dedicated to explore Doubly Linked List\n";
    int size;
    cout<<"Please enter the size of your Doubly Linked List = ";
    cin>>size;
    int INFO[size]; // A list that contains Data of Linked List
    int FORW[size]; // A list that contains address of next element
    int BACK[size]; // A list that contains address of previous element
    int FIRST = INT_MIN; // START Pointer initialised to NULL points to first element of DLL
    int LAST = INT_MIN; // LAST Pointer initialised to NULL points to last element of DLL
    int AVAIL = 0; // AVAIL Pointer
    for(int i=0;i<size;i++){
        // Example FORW[0] = 1 points to 1st index of INFO array
        FORW[i] = i+1; // Linking FORW element value to the next index of INFO element
        // Example BACK[1] = 0 points to 0th index of INFO array
        BACK[i] = i-1; // Linking BACK element value to the previous index of INFO element
    }
    insertInSorted(10,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(8,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(9,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(5,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(0,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(80,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(-9,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(-5,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(100,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(-100,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(90,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(-15,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(76,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(-980,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(-19,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    insertInSorted(85,INFO,FORW,BACK,size,AVAIL,FIRST,LAST);
    print(INFO,FORW,FIRST);

}