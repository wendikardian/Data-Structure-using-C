#include<stdio.h>
#include<stdlib.h>


void insertingSort(int arr[], int n){
    int i,j, key;
    for(i = 1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void print(int arr[], int n){
    int i;
    for(i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[5] = {12,11,13,5,6};
    int n = 5;
    insertingSort(arr, n);
    printf("Sorted array : ");
    print(arr, n);

    return 0;
}