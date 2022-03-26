#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void InfixToPosfix(char souce[], char target[]){
    int i = 0;
    int j = 0;
    char temp;
    while(souce[i] != '0'){
        if(souce[i] == '('){
            push(st, souce[i]);
            i++;
        }else if(souce[i] == ')'){
            while((top != -1) && (st[top] != '(')){
                
            }
        }
    }
}

int main(){

    return 0;
}