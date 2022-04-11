#include<stdio.h>
#include<stdlib.h>


int main(){
    int array1[20];
    int array2[20];
    int total;
    int i;
    scanf("%d", &total);
    for(i = 0; i<total; i++){
        scanf("%d", &array1[i]);
    }
    for(i = 0; i<total; i++){
        scanf("%d", &array2[i]);
    }
    for(i = 0; i<total; i++){
        printf("%d\n", array1[i] + array2[i]);
    }

    return 0;
}
