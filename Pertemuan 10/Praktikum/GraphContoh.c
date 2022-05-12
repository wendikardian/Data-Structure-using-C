// Asisten Praktikum Struktur Data 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct untuk vertex*/
typedef struct simpul{				
	struct ruas *jalur;
	struct simpul *nextVertex;
	char label;
}simpul;

/*struct untuk edge*/
typedef struct ruas{
	struct ruas *nextEdge;
	struct simpul *vertexTujuan;
	char bobot[2];
}ruas;

simpul *awal = NULL;

/*buat node baru*/
simpul *createSimpul (char a){
	simpul *simpulBaru = (simpul*)malloc(sizeof(simpul));
	simpulBaru->label = a;
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
void tambahVertex(char a){
	simpul *prev = cariSimpul(a);
	
	if(prev == NULL){
		simpul *baru = createSimpul(a);
		awal = baru;
	}
	else{
		if((prev->nextVertex == NULL) && (prev->label != a)){
			simpul *baru = createSimpul(a);
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

/*menambahkan edge*/
void tambahEdge(char Vasal, char nilaiEdge[], char Vtujuan){
	simpul *a,*t;
	
	if (cariSimpul(Vasal) == NULL){
		tambahVertex(Vasal);
	}
	if (cariSimpul(Vtujuan) == NULL){
		tambahVertex(Vtujuan);
	}
	
	a = cariSimpul(Vasal);
	t = cariSimpul(Vtujuan);
	
	createEdge(a,t,nilaiEdge);
}

/*cetak graph*/
void cetakGraph(){
	simpul *tempSimpul = awal;
	printf("\n Isi Dari Graph : \n");
	if (tempSimpul != NULL) {
		while (tempSimpul != NULL){
			printf("\n --| Vertex %c terhubung dengan edge : \n", tempSimpul->label);
			ruas *tempEdge = tempSimpul->jalur;
			while (tempEdge != NULL){
				printf(" ------| %s menuju vertex %c \n",tempEdge->bobot, tempEdge->vertexTujuan->label);
				tempEdge = tempEdge->nextEdge;
			}
			printf("\n");
			tempSimpul = tempSimpul->nextVertex;
		}
	}
	else{
		printf("Graph Kosong");
	}
}

int main(){
	
	tambahEdge('A',"5",'B');
	tambahEdge('A',"e2",'D');
	tambahEdge('B',"4",'A');
	tambahEdge('B',"3",'C');
	tambahEdge('B',"12",'E');
	tambahEdge('C',"10",'D');
	tambahEdge('C',"7",'B');
	tambahEdge('C',"6",'E');
	tambahEdge('D',"8",'C');
	tambahEdge('D',"3",'E');
	
	cetakGraph();
	
	return 0;
}