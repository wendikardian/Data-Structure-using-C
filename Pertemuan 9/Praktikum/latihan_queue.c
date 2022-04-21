#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 5

typedef struct antrian {
	int head;
	int tail;
	int data[maxsize];
}queue;

int isFull(queue *Q) {
	if (Q->head == 0 && Q->tail == maxsize-1) {
		return 1;
	}
	else if (Q->head - Q->tail == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int isEmpty(queue *Q) {
	if (Q->head == -1 && Q->tail == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

void enQueue(queue *Q, int x) {
	if(isFull(Q) == 0) {
		if (Q->head == -1) {
			Q->head = Q->head + 1;
		}
		Q->tail = (Q->tail + 1) % maxsize;
		Q->data[Q->tail] = x;
	}
	else {
		printf("\nAntrian Penuh\n\n");
	}
}

void deQueue(queue *Q) {
	int dataHapus;
	if (isEmpty(Q) == 0) {
		dataHapus = Q->data[Q->head];
		printf("\nData yang telah yang dihapus adalah %d\n\n",dataHapus);
		Q->data[Q->head] = 0;
		if (Q->head == Q->tail) {
			Q->head = -1;
			Q->tail = -1;
		}
		else {
			Q->head = (Q->head + 1) % maxsize;
		}
	}
	else {
		printf("\nAntrian Kosong\n\n");
	}
}

void cetak(queue *Q) {
	int i;
	if (isEmpty(Q) == 0) {
		for(i=0;i<maxsize;i++) {
			printf("%d   ",Q->data[i]);
		}
	}
	else {
		printf("\nAntrian Kosong\n\n");
	}
}

int main() {
	queue antrian;
	
	antrian.head = -1;
	antrian.tail = -1;
	
	enQueue(&antrian,12);
	enQueue(&antrian,5);
	enQueue(&antrian,4);
	enQueue(&antrian,15);
	enQueue(&antrian,400);
	
	cetak(&antrian);
	printf("\n\n");
	
	deQueue(&antrian);
	cetak(&antrian);
	printf("\n");
	deQueue(&antrian);
	cetak(&antrian);
	printf("\n");
	deQueue(&antrian);
	cetak(&antrian);
	printf("\n\n");
	printf("--------------------------------\n");
	enQueue(&antrian,100);
	cetak(&antrian);
	
	return 0;
}