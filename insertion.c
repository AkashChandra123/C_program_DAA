#include<stdio.h>
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        for(int j = i-1; j < n; j++){
            if(arr[j] > arr[i]){
                swap(arr,i,j);
            }
            for(int k = 0; k < j; k++){
                if(arr[k] > arr[j]){
                    swap(arr, k, j);
                }
            }
        }
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {12, 31, 25, 8, 32, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorted: ");
    printArray(arr, n);
    printf("Array after sort: ");
    insertion_sort(arr,n);
    printArray(arr, n);
    return 0;
}
