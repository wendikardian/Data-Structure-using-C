#include<stdio.h>

int main(){
    int *a;
    int b=2;
    a = &b;
    printf("%d\n", b);
    printf("%d\n", &b);
    printf("%d\n", a);
    printf("%d\n", *a);
    printf("%d\n", &a);
}