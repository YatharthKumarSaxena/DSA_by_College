// To find the factorial of a given number
// Don't do amendment in code otherwise program will malfunction
#include <iostream>
using namespace std;
void fact(int &Fact,int n){
    if(n==0){
        Fact = 1;
        return;
    }
    fact(Fact,n-1);
    Fact = n*Fact;
}
int main(){
    cout<<"Please enter your number = ";
    int ans,n;
    cin>>n;
    if(n<0){
        cout<<"Please enter a Whole number\n";
        cout<<"Program is terminated, so rerun the program\n";
        return 1;
    }
    fact(ans,n);
    cout<<"The factorial of number "<<n<<" = "<<ans;
    return 0;
}
