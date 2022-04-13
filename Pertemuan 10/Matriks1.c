#include<stdio.h>
#include<stdlib.h>
#define vertex 17

int main(){
    // matriks ruas
    char matriksRuas[vertex][2][10] = {{"Rama", "Ella"},
                                    {"Rama", "Bob"},
                                    {"Rama", "Katie"},
                                    {"Ella", "Bob"},
                                    {"Bob", "Tom"},
                                    { "Bob", "Sam"},
                                    {"Katie" , "Lee"},
                                    {"Katie","Swati"},
                                    {"Lee", "Bob"},
                                    {"Lee", "Sam"},
                                    {"Ella", "Zahir"},
                                    {"Lee", "Swati"},
                                    {"Swati", "Zahir"},
                                    {"Zahir", "Sam"},
                                    {"Zahir", "Arun"},
                                    {"Sam", "Tom"},
                                    {"Sam", "Arun"}
};

int i,j ;
    for (i = 0; i<vertex; i++){
        for(j = 0; j<2; j++){
            printf("%s\t", matriksRuas[i][j]);
        }
        printf("\n");
    }
    
}