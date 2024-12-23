// Selection Sort
void selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int minIdx = i;
        for(int j=i+1;j<size;j++){
            if(arr[minIdx]>arr[j]){
                // Change minIdx
                minIdx = j;
            }
        }
        // We get the Required Index for which value at index i must be swapped
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}