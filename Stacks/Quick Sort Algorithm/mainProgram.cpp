#include "quickSort.cpp"
int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"Please enter the size of the array = ";
    int N;
    cin>>N;
    int arr[N];
    cout<<"Please enter the elements of your array given below :- \n";
    for(int i=0;i<N;i++){
        cout<<"Please enter the "<<i+1<<" Element of the array = ";
        cin>>arr[i];
    }
    cout<<"Your array looks like :- {";
    for(int i=0;i<N;i++){
        if(i<N-1)cout<<arr[i]<<",";
        else cout<<arr[i]<<"}";
    }
    quickSort(arr,N);
    cout<<"\nYour array after quick sort looks like :- {";
    for(int i=0;i<N;i++){
        if(i<N-1)cout<<arr[i]<<",";
        else cout<<arr[i]<<"}";
    }
    return 0;
}