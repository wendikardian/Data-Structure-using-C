// TREE using C
// IMPLEMENTASI Ke -2 


#include<stdio.h>
#include<stdlib.h>
// #include<string.h>

typedef struct vertex{
    char data[20];
    struct vertex *sibling;
    struct vertex *child;
}Vertex;


Vertex *root = NULL;

Vertex * createVertex(char data[100]){
    Vertex *new = (Vertex*)malloc(sizeof(Vertex));
    strcpy(new->data, data);
    new->sibling = NULL;
    new->child = NULL;
    return new;
}


void addChild(char c[], Vertex *root){
    if(root != NULL){
        Vertex *new = createVertex(c);
        if(root->child == NULL){
            new->sibling = NULL;
            root->child = new;
        }else{
            if(root->child->sibling == NULL){
                new->sibling = root->child;
                root->child->sibling = new;
            }else{
                Vertex *last = root->child;
                while(last->sibling != root->child){
                    last = last->sibling;
                }
                new->sibling = root->child;
                last->sibling = new;
            }
        }
    }
}

Vertex *findVertex(char c[], Vertex *root){
    Vertex *result = NULL;
    if(root != NULL){
        if(strcmp(root->data, c) == 0){
            result = root;
        }else{
            Vertex *ptr = root->child;
            if(ptr != NULL){
                if(ptr->sibling == NULL){
                    if(strcmp(ptr->data, c) == 0){
                        result =  ptr;
                    }else{
                        result = findVertex(c, ptr);
                    }
                }else{
                    int find = 0;
                    while(ptr->sibling != root->child && (find == 0)){
                        if(strcmp(ptr->data, c) == 0){
                            result = ptr;
                            find = 1;
                        }else{
                            result = findVertex(c, ptr);
                            ptr = ptr->sibling;
                        }
                    }
                if(find == 0){
                    if(strcmp(ptr->data, c) == 0){
                        result = ptr;
                    }else{
                        result = findVertex(c, ptr);
                    }
                }
                }
            }
        }
    }
    return result;
}

void dellAll(Vertex *root){
    if(root != NULL){
        if(root->child != NULL){
            if(root->child->sibling == NULL){
                dellAll(root->child);
                free(root);
            }else{
                Vertex *ptr;
                Vertex *help;
                ptr = root->child;
                while(ptr->sibling != root->child){
                    help = ptr;
                    ptr = ptr->sibling;
                    dellAll(help);
                }
            }
            free(root);
        }else{
            free(root);
        }
    }
}


void dellChild(char c, Vertex *root){
    if(root != NULL) {
        Vertex *delete = root->child;
        if(delete != NULL){
            if(delete->sibling == NULL){
                if(strcmp(root->child->data, c) == 0){
                    dellAll(root->child);
                    root->child == NULL;
                }else{
                    printf("Vertex child not found\n");
                }
            }else{
                Vertex *ptr = NULL;
                int find = 0;
                while((delete->sibling != root->child) && (find == 0)){
                    if(strcmp(delete->data, c) == 0){
                        find = 1;
                    }else{
                        ptr = delete;
                        delete = delete->sibling;
                    }
                }

                if(find == 0 && (strcmp(delete->data, c) == 0)){
                    find = 1;
                }

                if(find == 1){
                    Vertex *last = root->child;
                    while(last->sibling != root->child){
                        last = last->sibling;
                    }

                    if(ptr == NULL){
                        if((delete->sibling == last) && (last->sibling == root->child)){
                            root->child = last;
                            last->sibling = NULL;
                        }else{
                            root->child = delete->sibling;
                            last->sibling = root->child;
                        }
                    }else{
                        if((ptr == root->child) && (last->sibling == root->child )){
                            root->child->sibling = NULL;
                        }else{
                            ptr->sibling = delete->sibling;
                            delete->sibling = NULL;
                        }
                    }
                    dellAll(delete);
                }else{
                    printf("Vertex child doesnt exist\n");
                }
            }
        }
    }
}

void preOrder(Vertex *root){
    if(root != NULL){
        printf(" %s - ", root->data);
        Vertex *ptr = root->child;
        if(ptr != NULL){
            if(ptr->sibling == NULL){
                preOrder(ptr);
            }else{
                while(ptr->sibling != root->child){
                    preOrder(ptr);
                    ptr = ptr->sibling;
                }
                preOrder(ptr);
            }
        }
    }
}

void postOrder(Vertex *root){
    if(root != NULL){
        Vertex *ptr = root->child;
        if(ptr != NULL){
            if(ptr->sibling == NULL){
                postOrder(ptr);
            }else{
                while(ptr->sibling != root->child){
                    postOrder(ptr);
                    ptr = ptr->sibling;
                }
                postOrder(ptr);
            }
        }
        printf(" %s - ", root->data);
    }
}


int main(int argc, char **argv){
    root = createVertex("Jawa Barat");
    addChild("Bekasi", root);
    addChild("Bandung", root);
    addChild("Bogor", root);
    addChild("Cimahi", root);
    Vertex *rootBekasi = findVertex("Bekasi", root);
    Vertex *rootBandung = findVertex("Bandung", root);
    Vertex *rootBogor = findVertex("Bogor", root);
    Vertex *rootCimahi = findVertex("Cimahi", root);
    addChild("Bekasi Barat", rootBekasi);
    addChild("Bekasi Selatan", rootBekasi);
    addChild("Bekasi Timur", rootBekasi);
    addChild("Andir", rootBandung);
    addChild("Antapani", rootBandung);
    addChild("Buah Batu", rootBandung);
    addChild("Bogor Barat", rootBogor);
    addChild("Bogor Selatan", rootBogor);
    addChild("Bogor Tengah", rootBogor);
    addChild("Cimahi Utara", rootCimahi);
    addChild("Cimahi Tengah", rootCimahi);
    addChild("Cimahi Selatan", rootCimahi);
    Vertex *rootBekasiBarat = findVertex("Bekasi Barat", rootBekasi);
    Vertex *rootBekasiSelatan = findVertex("Bekasi Selatan", rootBekasi);
    Vertex *rootBekasiTimur = findVertex("Bekasi Timur", rootBekasi);
    addChild("Bintara", rootBekasiBarat);
    addChild("Bintara Jaya", rootBekasiBarat);
    addChild("Kranji", rootBekasiBarat);
    addChild("Jakamulya", rootBekasiSelatan);
    addChild("Jakasetia", rootBekasiSelatan);
    addChild("Marga Jaya", rootBekasiSelatan);
    addChild("Aren Jaya", rootBekasiTimur);
    addChild("Bekasi Jaya", rootBekasiTimur);
    addChild("Duren Jaya", rootBekasiTimur);
    Vertex *rootAndir = findVertex("Andir", rootBandung);
    Vertex *rootAntapani = findVertex("Antapani", rootBandung);
    Vertex *rootBuahBatu = findVertex("Buah Batu", rootBandung);
    addChild("Campaka", rootAndir);
    addChild("Ciroyom", rootAndir);
    addChild("Kebonjeruk", rootAndir);
    addChild("Antapani Kulon", rootAntapani);
    addChild("Antapani Kidul", rootAntapani);
    addChild("Antapani Tengah", rootAntapani);
    addChild("Cijawura", rootBuahBatu);
    addChild("Jatisari", rootBuahBatu);
    addChild("Margasari", rootBuahBatu);
    Vertex *rootBogorBarat = findVertex("Bogor Barat", rootBogor);
    Vertex *rootBogorSelatan = findVertex("Bogor Selatan", rootBogor);
    Vertex *rootBogorTengah = findVertex("Bogor Tengah", rootBogor);
    addChild("Bubulak", rootBogorBarat);
    addChild("Curug", rootBogorBarat);
    addChild("GunungBatu", rootBogorBarat);
    addChild("Batutulis", rootBogorSelatan);
    addChild("Bojongkerta", rootBogorSelatan);
    addChild("Bonbongan", rootBogorSelatan);
    addChild("Babakan", rootBogorTengah);
    addChild("Cibogor", rootBogorTengah);
    addChild("Kebonkelapa", rootBogorTengah);
    Vertex *rootCimahiUtara = findVertex("Cimahi Utara", rootCimahi);
    Vertex *rootCimahiTengah = findVertex("Cimahi Tengah", rootCimahi);
    Vertex *rootCimahiSelatan = findVertex("Cimahi Selatan", rootCimahi);
    addChild("Cibabat", rootCimahiUtara);
    addChild("Cipageran", rootCimahiUtara);
    addChild("Pasirkaliki", rootCimahiUtara);
    addChild("Baros", rootCimahiTengah);
    addChild("Karangmekar", rootCimahiTengah);
    addChild("Padasuka", rootCimahiTengah);
    addChild("Cibeber", rootCimahiSelatan);
    addChild("Melong", rootCimahiSelatan);
    addChild("Leuwigajah", rootCimahiSelatan);



    
    int i;
    while(i != 5){
        printf("\n\n============================\n        TREEE \n============================\n\n");
        printf("\nSelamat datang di data kelurahan Jawa Barat : ");
        printf("\nAdapun beberapa menu yang ada disini adalah");
        printf("\n1. Print Pre Order");
        printf("\n2. Print Post Order");
        printf("\n3. Liat data berdasarkan level");
        printf("\n4. Tambah data");
        printf("\n5. Exit\nPilihan anda :");
        scanf("%d", &i);
        switch (i){
            case 1:
                printf("PRE ORDER : \n");
                preOrder(root);
                break;
            case 2:
                printf("\nPOST ORDER : \n");
                postOrder(root);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
    
    
    return 0;
}