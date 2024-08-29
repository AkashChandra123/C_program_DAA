#include<stdio.h>
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Selection_Sort(int arr[], int n){
    int startpos, minpos;
    for(startpos = 0; startpos < n; startpos++){
        minpos = startpos;
        for(int i = minpos+1; i < n; i++){
            if(arr[i]<arr[minpos]){
                minpos = i;
            }
        }
        swap(arr,minpos,startpos);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: \n");
    printArray(arr, n);
    Selection_Sort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}