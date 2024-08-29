#include<stdio.h>
int parent(int i) {
   if (i == 0)
      return -1;
   else
      return (i - 1) / 2;
}

void heapify(int a[], int n, int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;
    if(left < n && a[left] > a[largest]){
        largest = left;
    }
    if(right < n && a[right] > a[largest]){
        largest = right;
    }
    if(largest!= i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void MaxHeap_insert(int a[], int *n, int item){
    (*n)++;
    int i = *n;
    a[i] = item;
    while(i > 1 && a[parent(i)] < a[i]){
        int temp = a[i];
        a[i] = a[parent(i)];
        a[parent(i)] = a[i];
        i = parent(i);
    }
}

void heapsort(int a[], int n){
    for(int i = n/2 -1; i >= 0; i--){
        heapify(a,n,i);
    }
    for(int i = n-1; i >= 0; i--){
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {48, 10, 23, 43, 28, 26, 1};
    int n = sizeof(a)/sizeof(a[0]);
    int item = 34;
    printf("Before sorted: ");
    printArray(a, n);
    heapsort(a,n);
    printf("After sorted:  ");
    printArray(a, n);

    MaxHeap_insert(a,&n, item);
    heapsort(a,n);
    printf("After inserting new item:\n");
    printArray(a,n);
    return 0;
}