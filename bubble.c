#include<stdio.h>
void bubble(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] < a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {13, 32, 26, 35, 10};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Before sorting array: ");
    printArray(a, n);
    bubble(a,n);
    printf("After sorted array: ");
    printArray(a, n);

}