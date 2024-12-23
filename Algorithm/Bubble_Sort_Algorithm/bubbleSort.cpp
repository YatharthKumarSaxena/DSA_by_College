// Normal Bubble Sort Algorithm
void bubbleSort(int arr[],int size){  
    for(int PTR=0;PTR<size-1;PTR++){  // Size-1 Pass
        int k = 0;
        while(k<size-PTR-1){
            if(arr[k]>arr[k+1]){
                // Swap arr[k] and arr[k+1]
                int temp = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = temp;
            }
            k += 1;
        }
    }
}