#include <iostream>
using namespace std;
void partition(int arr[],int N,int Beg,int End,int &LOC){
    int Left = Beg;
    int Right = End;
    LOC = Beg;
    while(true){
        while(arr[LOC]<=arr[Right] && LOC!=Right){
            Right = Right - 1;
        }
        if(LOC == Right){
            return;
        }
        if(arr[LOC]>arr[Right]){
            int temp = arr[LOC];
            arr[LOC] = arr[Right];
            arr[Right] = temp;
            LOC = Right;
        }
        while(arr[Left]<=arr[LOC] && LOC!=Left){
            Left = Left + 1;
        }
        if(LOC == Left){
            return;
        }
        if(arr[Left]>arr[LOC]){
            int temp = arr[LOC];
            arr[LOC] = arr[Left];
            arr[Left] = temp;
            LOC = Left;
        }
    }
}
