#include<stdio.h>
#include<stdlib.h>


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int n){
    int i,j, min_index;
    for(i = 0; i<n-1; i++){
        min_index = i;
        for(j = j+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
        
    }
}

void print(int arr[], int n){
    int i;
    printf("Sorted array : ");
    for(i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){
    int arr[5] = {12,11,13,5,6};
    int n = 5;
    selectionSort(arr, n);
    print(arr, n);

    return 0;
}