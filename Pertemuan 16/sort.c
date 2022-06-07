#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a  = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min;
    for(i = 0; i<n-1; i++){
        min = i;
        for(j = i+1; j<n;j++){
            if(arr[j] < arr[min]){
                swap(&arr[min], &arr[j]);
            }
        }
    }
}

int main(){
    int arr[10];
    int n;
    scanf("%d", &n);
    int i;
    for(i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    for(i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    int range[10];
    int j, count;
    scanf("%d", &j);
    for(i = 0; i<j;i++){
        
    }
}