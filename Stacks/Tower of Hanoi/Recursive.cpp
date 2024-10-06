// Recursive soution of Tower of Hanoi
// Don't do amendment in code otherwise program will malfunction
#include <iostream>
using namespace std;
void towerOfHanoiRec(int n,string Beg,string Aux,string End){
    if(n == 1){
        cout<<Beg<<"->"<<End<<endl;
        return;
    }
    towerOfHanoiRec(n-1,Beg,End,Aux);
    cout<<Beg<<"->"<<End<<endl;
    towerOfHanoiRec(n-1,Aux,Beg,End);
}