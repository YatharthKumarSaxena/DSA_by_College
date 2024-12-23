// Efficient Bubble Sort Algorithm
void effBubbleSort(int arr[],int size){
    for(int PTR=0;PTR<size-1;PTR++){  // Size-1 Pass
        int k = 0;
        bool flag = false;
        while(k<size-PTR-1){
            if(arr[k]>arr[k+1]){
                // Swap arr[k] and arr[k+1]
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
                flag = true;
            }
            k += 1;
        }
        if(!flag) break;
    }
}