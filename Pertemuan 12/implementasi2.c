// TREE using C
// By Wendi Kardian
// IMPLEMENTASI Ke -2 


#include<stdio.h>
#include<stdlib.h>

typedef struct vertex{
    char label;
    struct vertex *sibling;
    struct vertex *child;
}Vertex;


Vertex *root = NULL;

Vertex * createVertex(char label){
    Vertex *new = (Vertex*)malloc(sizeof(Vertex));
    new->label =  label;
    new->sibling = NULL;
    new->child = NULL;
    return new;
}


void addChild(char c, Vertex *root){
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

Vertex *findVertex(char c, Vertex *root){
    Vertex *result = NULL;
    if(root != NULL){
        if(root->label == c){
            result = root;
        }else{
            Vertex *ptr = root->child;
            if(ptr != NULL){
                if(ptr->sibling == NULL){
                    if(ptr->label == c){
                        result =  ptr;
                    }else{
                        result = findVertex(c, ptr);
                    }
                }else{
                    int find = 0;
                    while(ptr->sibling != root->child && (find == 0)){
                        if(ptr->label == c){
                            result = ptr;
                            find = 1;
                        }else{
                            result = findVertex(c, ptr);
                            ptr = ptr->sibling;
                        }
                    }
                if(find == 0){
                    if(ptr->label == c){
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
                if(root->child->label == c){
                    dellAll(root->child);
                    root->child == NULL;
                }else{
                    printf("Vertex child not found\n");
                }
            }else{
                Vertex *ptr = NULL;
                int find = 0;
                while((delete->sibling != root->child) && (find == 0)){
                    if(delete->label == c){
                        find = 1;
                    }else{
                        ptr = delete;
                        delete = delete->sibling;
                    }
                }

                if(find == 0 && (delete->label == c)){
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
        printf(" %c", root->label);
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
        printf(" %c", root->label);
    }
}


int main(){
    root = createVertex('A');
    addChild('B', root);
    addChild('F', root);
    addChild('G', root);
    Vertex *rootB = findVertex('B', root);
    Vertex *rootG = findVertex('G', root);
    addChild('C', rootB);
    addChild('D', rootB);
    addChild('E', rootB);
    addChild('H', rootG);
    addChild('I', rootG);
    Vertex *rootI = findVertex('I', rootG);
    addChild('J', rootI);
    addChild('K', rootI);
    printf("============================\n        TREEE \n============================\n\n");
    printf("PRE ORDER : \n");
    preOrder(root);
    printf("\nPOST ORDER : \n");
    postOrder(root);
    return 0;
}