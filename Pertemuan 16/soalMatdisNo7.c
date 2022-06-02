#include<stdio.h>
#include<stdlib.h>
//WendiKardian - 2100016 - PILKOMA
int rekursi(int n){
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }else{
        return (rekursi(n-1) + 2*rekursi(n-2) );
    }
}

int main(){
    int a;
    scanf("%d", &a);
    int i;
    for(i=1; i<=a; i++){
         printf("%d ", rekursi(i));
    }
    return 0;
}