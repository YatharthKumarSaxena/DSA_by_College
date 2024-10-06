// Find the nth term of fibonacci sequence 
// 1st term is 0 and 2nd term is 2 of fibonacco sequence
// Don't do amendment in code otherwise program will malfunction
#include <iostream>
using namespace std;
void fibOfNthTerm(int &fib,int n,int fibA=1,int fibB=1){
    if(n==0 || n==1){
        fib = n;
        return;
    }
    fibOfNthTerm(fibA,n-2,fibA,fibB);
    fibOfNthTerm(fibB,n-1,fibA,fibB);
    fib = fibA+fibB;
    return;
}
int main(){
    cout<<"Welcome to the fibonacci number program"<<endl;
    cout<<"Please enter the nth term = ";
    int n,ans;
    cin>>n;
    if(n<=0){
        cout<<"Please enter a natural number\n";
        cout<<"Program is terminated, so rerun the program\n";
        return 1;
    }
    fibOfNthTerm(ans,n-1);
    cout<<"The "<<n<<"th term of the fibonacci sequence = "<<ans;
    return 0;
}