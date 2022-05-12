// STRUKTUR DATA GRAPH DINAMIS
// MIRIP SEPERTI YANG PERTAMA AKAN TETAPI DIBUATKAN DALAM BENTUK MENU
// WENDI KARDIAN (2100016) - Pendidikan Ilmu Komputer - A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul{				
	struct ruas *jalur;
	struct simpul *nextVertex;
	char label;
	char id[2];
}simpul;

typedef struct ruas{
	struct ruas *nextEdge;
	struct simpul *vertexTujuan;
	char bobot[2];
}ruas;

simpul *awal = NULL;

//Membuat vertex baru
simpul *createVertex (char a, char b[]){
	simpul *simpulBaru = (simpul*)malloc(sizeof(simpul));
	simpulBaru->label = a;
	strcpy(simpulBaru->id,b);
	simpulBaru->jalur = NULL;
	simpulBaru->nextVertex = NULL;
	
	return simpulBaru;
}

/*fungsi untuk menemukan simpul didalam graph*/
simpul *cariSimpul(char a) {
	simpul *bantu = awal;
	
	if(bantu != NULL){
		while(bantu->nextVertex != NULL){
			if(bantu->label == a){
				break;
			}
	
			bantu = bantu->nextVertex;
		}
	}
	
	return bantu;
}

/*menambahkan node bila belum ada dalam graph*/
void tambahVertex(char a, char b[]){
	simpul *prev = cariSimpul(a);
	
	if(prev == NULL){
		simpul *baru = createVertex(a, b);
		awal = baru;
	}
	else{
		if((prev->nextVertex == NULL) && (prev->label != a)){
			simpul *baru = createVertex(a, b);
			prev->nextVertex = baru;
		}
	}
}

/*buat edge baru*/
void createEdge (simpul *a, simpul *t, char bobot[]){
	ruas *newEdge = (ruas*)malloc(sizeof(ruas));
	strcpy(newEdge->bobot,bobot);
	newEdge->nextEdge = NULL;
	newEdge->vertexTujuan = t;
	
	if (a->jalur == NULL){
		a->jalur = newEdge;
	}
	else{
		ruas *jalurAkhir = a->jalur;
		while (jalurAkhir->nextEdge != NULL){
			jalurAkhir = jalurAkhir->nextEdge;
		}
		jalurAkhir->nextEdge = newEdge;   
	}
}

void tambahEdge(char Vasal, char nilaiEdge[], char Vtujuan){
	simpul *a,*t;
	a = cariSimpul(Vasal);
	t = cariSimpul(Vtujuan);
	createEdge(a,t,nilaiEdge);
}

void display(){
	simpul *tempSimpul = awal;
	printf("|-----------------------------------------------------------| \n");
	printf("|                 NILAI GRAPH                               | \n");
	printf("|-----------------------------------------------------------| \n");
	if (tempSimpul != NULL) {
		while (tempSimpul != NULL){
			if(tempSimpul->jalur != NULL){
				printf("\n Vertex %c yang memiliki id %s terhubung dengan edge : \n", tempSimpul->label, tempSimpul->id);
				ruas *tempEdge = tempSimpul->jalur;
				while (tempEdge != NULL){
					printf(" ------ %s menuju vertex %c \n",tempEdge->bobot, tempEdge->vertexTujuan->label);
					tempEdge = tempEdge->nextEdge;
				}
				printf("\n");
				tempSimpul = tempSimpul->nextVertex;
			}else{
				printf("\nVertex %c yang memiliki id %s tidak berhubungan dengan edge \n", tempSimpul->label, tempSimpul->id);
				tempSimpul = tempSimpul->nextVertex;
			}
		printf("-----------------------------------------------------------\n");
		}
		
	}
	else{
		printf("Graph Kosong");
	}
}

void checkVertex(){
	simpul *tempSimpul = awal;
	while(tempSimpul != NULL){
		printf("%c\n", tempSimpul->label);
		tempSimpul = tempSimpul->nextVertex;
	}
}

int main(){
	
    int option;
    char vertex1;
    char vertex2;
    char id1[2];
    char id2[2];
    char bobot[2];
    do{
        printf("|-----------------------------------------------------------| \n");
        printf("|                 GRAPH APK                               | \n");
        printf("|-----------------------------------------------------------| \n");
        printf("Menus : \n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. Exit the program\n");
        printf("Your Option : ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("Label 1 : ");
                scanf(" %c",&vertex1);
                printf("ID 1 : ");
                scanf("%s",id1);
                printf("Label 2 : ");
                scanf(" %c",&vertex2);
                printf("ID 2 : ");
                scanf("%s",id2);
                printf("Bobot : ");
                scanf("%s",bobot);
                tambahVertex(vertex1, id1);
                tambahVertex(vertex2, id2);
                tambahEdge(vertex1, bobot, vertex2);
                break;
            case 2: 
                display();
                break;
        }
    }while(option != 3);
	return 0;
}