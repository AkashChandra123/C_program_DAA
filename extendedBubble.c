#include<stdio.h>
void bubble(int a[], int n){
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        if(flag == 1)
            return;
    }
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {10, 13, 26, 32, 35};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Before sorting array: ");
    printArray(a, n);
    printf("After sorted array:  ");
    bubble(a,n);
    printArray(a, n);
    return 0;
}