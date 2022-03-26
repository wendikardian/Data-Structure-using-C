#include<stdio.h>

int hasilPangkat(int a){
    return a*a;
}

void jenisBilangan(int a){
    if(a%2==0){
        printf("bilangan genap \n");
    }else{
        printf("bilangan ganjil \n");
    }
}

int main(){
    int a,pangkat;
    scanf("%d",&a);
    jenisBilangan(a);
    pangkat  = hasilPangkat(a);
    printf("Hasil Pangkatnya adalah %d", pangkat);
    return 0;
}
