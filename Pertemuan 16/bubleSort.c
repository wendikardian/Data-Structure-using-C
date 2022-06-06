#include<stdio.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
    int i,j;
    for(i = 0; i<n; i++ ){
        for(j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void print(int arr[], int n){
    int i,j;
    for(i = 0; i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int arr[20] = {64,34,25,12,22,11,90};
    int n = 7;
    bubbleSort(arr,n);
    printf("Sorted arrays : ");
    print(arr, n);
    
}