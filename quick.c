#include<stdio.h>

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = (start - 1);

    for(int j = start; j <= end-1; j++){
        if(arr[j] < pivot){
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = t;

    return (i+1);

}

void quick(int arr[], int start, int end){
    if(start<end){
        int p = partition(arr, start, end);

        quick(arr, start, p-1);
        quick(arr, p+1, end);
    }
}

void printArray(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
}
int main(){
    int arr[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorted: \t");
    printArray(arr, n);
    printf("\n");
    quick(arr, 0, n-1);
    printf("After sorted: \t");
    printArray(arr, n);
    return 0;
}
