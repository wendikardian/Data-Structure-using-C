#include<stdio.h>

int main(){
    int a = 1;
    int b= 1;
    int c;
    int i = 3;
    int total;
    printf("Masukan nilai n dari deret fibonnaci yang akan di buat : ");
    scanf("%d", &total);
    printf("Deret Fibonnaci : %d %d ", a, b);
    while(i<= total){
        c = a+b;
        printf("%d ", c);
        a = b;
        b = c;
        i++;
    }
    return 0;
}