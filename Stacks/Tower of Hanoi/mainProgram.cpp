// Don't do amendment in code otherwise program will malfunction
#include "Recursive.cpp"
#include <cmath>
int main(){
    cout<<"Welcome to Tower of Hanoi game\n";
    cout<<"Please enter the number of discs = ";
    int n;
    cin>>n;
    cout<<"Minimum number of steps to reach destination peg from source peg = "<<pow(2,n)-1;
    cout<<endl;
    cout<<"Steps from start to end is given below :- \n";
    towerOfHanoiRec(n,"Src","Aux","Dst");
    return 0;
}