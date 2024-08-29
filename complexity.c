#include<stdio.h>

void insertion(int arr[], int n){
    for(int i = 0; i < n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && temp <= arr[j]){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = temp;
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
}

int main(){
    int arr[] = {12, 31, 25, 8, 32, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorted: ");
    printArr(arr, n);
    printf("\n");
    insertion(arr, n);
    printf("After sorted: \n");
    printArr(arr, n);
    return 0;
}