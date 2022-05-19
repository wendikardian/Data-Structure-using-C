
// Fibonnaci menggunakan recrusive

#include<stdio.h>

int fibonnaci(int n){
    if(n == 0){
        return 1;
    }else if(n == 1){
        return 1;
    }else{
        return (fibonnaci(n-1) + fibonnaci(n-2) );
    }
}

int main(){
    int n, i;
    printf("Enter the value of the fibonnaci : ");
    scanf("%d", &n);
    printf("Fibonnaci of %d : ", n);
    for(i = 0; i<n; i++){
        printf("%d ", fibonnaci(i));
    }
}