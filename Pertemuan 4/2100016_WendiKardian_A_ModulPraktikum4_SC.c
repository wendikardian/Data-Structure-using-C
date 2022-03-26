#include <stdio.h>
#include <malloc.h>
#include <string.h>


struct node{
    char nama[15];
    char gender[10];
    int usia;
    struct node *next;
};

struct node *start = NULL;


struct node *createList(char nama[], char gender[], int usia, struct node *start){
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->nama, nama);
    strcpy(new_node->gender, gender);
    new_node->usia = usia;
    new_node->next = NULL;
    start = new_node;
    return start;
}

struct node *insert_end(char nama[], char gender[], int usia, struct node *start){
    struct node *new_node, *ptr;
    new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->nama, nama);
    strcpy(new_node->gender, gender);
    new_node->usia = usia;
    new_node->next = NULL;
    start->next = new_node;
    return start;
}


struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("\n%s\n%s\n%d\n", ptr->nama, ptr->gender, ptr->usia);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(char nama[], char gender[], int usia,struct node *start){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    strcpy(new_node->nama,nama);
    strcpy(new_node->gender,gender);
    new_node->usia = usia;
    new_node->next = start;
    start = new_node;
    return start;
    
}

struct node *insert_after(char nama[], char gender[], int usia, struct node *loc,struct node *start){
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->nama, nama);
    strcpy(new_node->gender, gender);
    new_node->usia = usia;
    new_node->next = loc->next;
    loc->next = new_node;
    return start;
}

struct node *insert_bef(char nama[], char gender[], int usia, char cari[],struct node *start){
    struct node *new_node, *ptr;
    new_node = (struct node *) malloc(sizeof(struct node));
    strcpy(new_node->nama,nama);
    strcpy(new_node->gender,gender);
    new_node->usia = usia;
    ptr = start;
    while(strcmp(ptr->next->nama, cari) != 0){
        ptr = ptr->next;
    }
    new_node->next =ptr->next;
    ptr->next = new_node;
    return start;
}

struct node * delete_beg(struct node *start){
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}



int main(){
    int option = 4, count;
    int usia,i, j;
    int toDelete;
    struct node *ptr;    
    char nama[15], gender[10];
    do{
        scanf("%d", &option);
        switch(option){
            case 1: 
            scanf("%d", &count);
            for(i = 0; i< count; i++){
                scanf("%s", nama);
                scanf("%s", gender);
                scanf("%d", &usia);
                if(start == NULL){
                    start = createList(nama,gender,usia, start);
                }else if(start->next == NULL){
                    if(start->usia > usia){
                        start = insert_end(nama, gender,usia,start);
                    }else{
                        if(start->usia == usia){
                            if(strcmp(start->gender, "Perempuan") == 0 && strcmp(gender, "Laki-laki") == 0){
                                start = insert_end(nama, gender,usia,start);
                            }else if(strcmp(start->gender, "Perempuan") == 0  && strcmp(gender, "Perempuan") == 0){
                                start = insert_end(nama, gender,usia,start);
                            }else if(strcmp(gender, "Perempuan") == 0 && strcmp(ptr->gender, "Laki-laki")==0){
                                start = insert_bef(nama, gender,usia,ptr->nama,start);
                            }
                            else{
                                start = insert_beg(nama, gender,usia,start);
                            }
                        }else{
                            start = insert_beg(nama, gender,usia,start);
                        }
                    }
                }else{
                    ptr = start;
                    int i;
                    while(ptr->usia > usia && ptr->next != NULL){
                        ptr = ptr->next;
                    }

                    if(ptr->usia == usia){
                        if(strcmp(ptr->gender, "Perempuan") == 0 && strcmp(gender, "Laki-laki") == 0){
                            while(strcmp(ptr->next->gender, "Laki-laki") == 0){
                                ptr = ptr->next;
                            }
                            if(ptr->next == NULL){
                                start = insert_end(nama, gender,usia,start);
                            }else{ 
                                start = insert_after(nama, gender, usia, ptr, start);
                            }

                            
                        }else if(strcmp(start->gender, "Perempuan") == 0  && strcmp(gender, "Perempuan") == 0){
                            start = insert_after(nama, gender, usia, ptr, start);
                        }else if(strcmp(gender, "Perempuan") == 0 && strcmp(ptr->gender, "Laki-laki")==0){
                            if(start == ptr){
                                start = insert_beg(nama, gender,usia,start);
                            }
                            else{
                                start = insert_bef(nama, gender,usia,ptr->nama,start);

                            }
                        }
                        else{
                            while(strcmp(ptr->next->gender, "Laki-laki") == 0){
                                ptr = ptr->next;
                            }
                            if(ptr->next == NULL){
                                start = insert_end(nama, gender,usia,start);
                            }else{
                                start = insert_after(nama, gender, usia, ptr->next, start);
                            }
                            
                        }
                    }else if(start->usia < usia){
                        start = insert_beg(nama, gender,usia,start);
                    }
                    else if(ptr->usia < usia){
                        start = insert_bef(nama, gender,usia,ptr->nama,start);

                    }
                    else{
                        start = insert_end(nama, gender,usia,start);
                    }    
                }
        }
        break;
        case 2:
            scanf("%d", &toDelete);
            for(j = 0; j<toDelete ; j++){
                start = delete_beg(start);
            }
            break;
        case 3: 
            if(start == NULL){
                printf("Daftar List Kosong \n");
            }else{
                start = display(start);
            }
            break;
        }
    
    }while(option != 0);
    
    return 0;

}

