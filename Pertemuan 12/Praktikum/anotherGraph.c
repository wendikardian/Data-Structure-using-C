//Asisten praktikum 2022 Struktur Data

#include <stdio.h>
#include <stdlib.h>

/* deklarasi Struktur node dan edge dalam graph*/
struct simpul{				
	struct edge *jalur;
	struct simpul *next;
	char idSimpul;
};

struct edge{
	struct edge *next_jalur;
	struct simpul *tujuan;
	int Cost;
};

/*fungsi untuk membangun graph*/
struct Graph{
	struct simpul  *first;
};

void createGraph(struct Graph *G){
	G->first = NULL;
}

/*tambah node baru*/
void *createSimpul (struct Graph *G, char a){
	struct simpul *simpulBaru = (struct simpul*)malloc(sizeof(struct simpul));
	simpulBaru->idSimpul = a;
	simpulBaru->jalur = NULL;
	simpulBaru->next = NULL;
	
	if (G->first == NULL){
		G->first = simpulBaru;
	}
	else{
		struct simpul *akhir = G->first;
		while (akhir->next != NULL){
			akhir = akhir->next;
		}
		akhir->next = simpulBaru;
	}
}

/*tambah edge baru*/
void addEdge (struct simpul *awal, struct simpul *akhir, int nilaiJalur){
	//buat new jalur
	struct edge *newEdge = (struct edge*)malloc(sizeof(struct edge));
	//lakukan inisialisasi dan masukan nilai edge
	newEdge->Cost = nilaiJalur;
	newEdge->next_jalur = NULL;
	newEdge->tujuan = akhir;
	//periksa awal->jalur
	//jika belum, tambahkan newEdge ke simpul awal
	if (awal->jalur == NULL){
		awal->jalur = newEdge;
	}
	else{
	//jika sudah, periksa jalur akhir pada simpul awal tsb
		struct edge *jalurAkhir = awal->jalur;
		while (jalurAkhir->next_jalur != NULL){
			jalurAkhir = jalurAkhir->next_jalur;
		}
		//tambahkan jalur akhir diujung jalur
		jalurAkhir->next_jalur = newEdge;   
	}
}

/*funsgi untuk mencetak graph*/
void cetakGraph(struct Graph *G){
	struct simpul *tempSimpul = G->first;

	//if graph tidak kosong lakukan penelusuran
	if (tempSimpul != NULL) {
		while (tempSimpul != NULL){
			//print simpul tsb
			printf("\nSimpul %c \n", tempSimpul->idSimpul);
			//lakukan pengecekan dan penelusuran jalur
			struct edge *tempEdge = tempSimpul->jalur;
			
			while (tempEdge != NULL){
				//print setiap jalur dan simpul akhir jalur tsb
				printf("terhubung dengan simpul %c, dengan Cost %d\n", tempEdge->tujuan->idSimpul, tempEdge->Cost);
				tempEdge = tempEdge->next_jalur;
			}
			tempSimpul = tempSimpul->next;
		}
	}
	else{
		//selainnya graph kosong
		printf("Graph Kosong");
	}
}

/*fungsi untuk menemukan simpul didalam graph*/
struct simpul *cariSimpul(char c, struct Graph G) {
	struct simpul *hasil = NULL;
	struct simpul *bantu = G.first;
	
	int ketemu = 0;
	while((bantu != NULL) && ketemu == 0){
		if(bantu->idSimpul == c){
			hasil = bantu;
			ketemu = 1;
		}
		else{
			bantu = bantu->next;
		}
	}
	
	return hasil;
}

void delAll(struct simpul *awal){
	struct edge *bantu;
	bantu = awal->jalur;
	struct edge *hapus;
	while(bantu != NULL){
		hapus = bantu;
		bantu = bantu->next_jalur;
		awal->jalur = bantu;
		hapus->next_jalur = NULL;
		free(hapus);
	}
}

/*Fungsi untuk menghaus edge*/
void delJalur(char ctujuan,struct simpul *awal){
	struct edge *hapus = awal->jalur;
	if(hapus != NULL){
		struct edge *prev = NULL;
		int ketemu = 0;
		while((hapus != NULL) && (ketemu == 0)){
			if(hapus->tujuan->idSimpul == ctujuan){
				ketemu = 1;
			}
			else{
				prev = hapus;
				hapus = hapus->next_jalur;
			}
		}
		if(ketemu == 1){
			if(prev == NULL){
				awal->jalur = hapus->next_jalur;
				hapus->next_jalur = NULL;
			}
			else{
				if(hapus->next_jalur == NULL){
					prev->next_jalur = hapus->next_jalur;
					hapus->next_jalur = NULL;
				}
			}
		}
		free(hapus);
	}
	else{
		printf("tidak ada jalur simpul tujuan \n");
	}
}

/*menghapus simpul*/
void delSimpul(char c, struct Graph *G){
	struct simpul *hapus = (*G).first;
	if(hapus != NULL){
		struct simpul *prev = NULL;
		int ketemu = 0;
		while ((hapus != NULL) && (ketemu == 0)){
			if(hapus->idSimpul == c){
				ketemu = 1;
			}
			else{
				prev = hapus;
				hapus = hapus->next;
			}
		}
		if(ketemu == 1){
			struct simpul *bantu;
			bantu = (*G).first;
			
			while(bantu != NULL){
				if(bantu != hapus){
					delJalur(hapus->idSimpul, bantu);
				}
				bantu = bantu->next;
			}
			delAll(hapus);
			if(prev == NULL){
				(*G).first = hapus->next;
				hapus->next = NULL;
			}
			else{
				if(hapus->next == NULL){
					prev->next = NULL;
				}
				else{
					prev->next = hapus->next;
					hapus->next = NULL;
				}
			}
			free(hapus);
		}
		else{
			printf("Tidak ada simpul dengan info karakter masukan\n");
		}
	}
	else{
		printf("Tidak ada simpul dengan info karakter masukan\n");
	}
}

int main(){
	struct Graph graphSatu;
	struct simpul *A, *B, *C, *D, *E, *F;
	
	//buat graph
	createGraph(&graphSatu);
	
	//buat simpul
	createSimpul(&graphSatu,'A');
	createSimpul(&graphSatu,'B');
	createSimpul(&graphSatu,'C');
	createSimpul(&graphSatu,'D');
	createSimpul(&graphSatu,'E');
	createSimpul(&graphSatu,'F');
	
	//cari simpul
	A = cariSimpul('A',graphSatu);
	B = cariSimpul('B',graphSatu);
	C = cariSimpul('C',graphSatu);
	D = cariSimpul('D',graphSatu);
	E = cariSimpul('E',graphSatu);
	F = cariSimpul('F',graphSatu);
	
	//buat edge 
	addEdge(A,B,3);
	addEdge(B,E,7);
	addEdge(B,D,3);
	addEdge(D,A,8);
	addEdge(C,A,3);
	addEdge(D,C,3);
	addEdge(E,D,4);
	addEdge(E,F,4);
	addEdge(F,D,2);
	
	//cetak hasil
	cetakGraph(&graphSatu);
	
	//delJalur
//	printf("\n-------------DELETE JALUR ----------------\n\n");
//	delJalur('B',A);
//	cetakGraph(&graphSatu);
	
	//delSimpul
	printf("\n-------------DELETE SIMPUL ----------------\n\n");
	delSimpul('C',&graphSatu);
	cetakGraph(&graphSatu);
	
	return 0;
}