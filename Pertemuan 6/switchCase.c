#include<stdio.h>
#include<stdlib.h>


int main(){
    int option;
    scanf("%d",&option);
    do{
        switch(option){
        case -1:
            printf("Data == -1\n");
            break;
        case 1:
            printf("Data == 1\n");
            break;
        case 2:
            printf("Data == 2\n");
            break;
        case 3:
            printf("Data == 3\n");
            break;
        default:
            printf("Data tidak sesuai");
            break;
    }
    scanf("%d",&option);
    }while(option != 0);
    

    return 0;
}