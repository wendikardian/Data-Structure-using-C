// Asisten Praktikum Struktur Data 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct untuk vertex*/
typedef struct simpul{				
	struct ruas *jalur;
	struct simpul *nextVertex;
	char label;
	char id[2];
}simpul;

/*struct untuk edge*/
typedef struct ruas{
	struct ruas *nextEdge;
	struct simpul *vertexTujuan;
	char bobot[2];
}ruas;

simpul *awal = NULL;

/*buat node baru*/
simpul *createSimpul (char a, char b[]){
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
		simpul *baru = createSimpul(a, b);
		awal = baru;
	}
	else{
		if((prev->nextVertex == NULL) && (prev->label != a)){
			simpul *baru = createSimpul(a, b);
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

/*cetak graph*/
void cetakGraph(){
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
	
	tambahVertex('A', "v1");
	tambahVertex('B', "v2");
	tambahVertex('C', "v3");
	tambahVertex('D', "v4");
	tambahVertex('E', "v5");
	tambahVertex('E', "v5");
	tambahEdge('A',"5",'B');
	tambahEdge('A',"e2",'D');
	tambahEdge('B',"4",'A');
	tambahEdge('B',"3",'C');
	tambahEdge('B',"12",'E');
	tambahEdge('C',"7",'B');
	tambahEdge('C',"10",'D');
	tambahEdge('C',"6",'E');
	tambahEdge('D',"8",'C');
	tambahEdge('D',"3",'E');
	cetakGraph();
	// checkVertex();
	
	return 0;
}