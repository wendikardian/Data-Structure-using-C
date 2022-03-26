#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);


int main(){
    int option;
    do{
        printf("\n **** DOUBLE LINKED LIST MENU **** \n");
        printf("\n\n 1: Create a list ");
        printf("\n 2: Display the list");
        printf("\n 3: Add Node at the beginning");
        printf("\n 4: Add Node at the end");
        printf("\n 5: Add Node before aa given Node");
        printf("\n 6: Add Node After aa given Node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: EXIT");
        printf("\n\nEnter your option : ");
        scanf("%d", &option);
        switch (option){
            case 1:
                start = create_ll(start);
                printf("\n Double linked list has been created");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_before(start);
                break;
            case 10:
                start = delete_after(start);
                break;
            case 11:
                start = delete_list(start);
                printf("\n List has been deleted\n");
                break;

        }
    }while(option != 12);
    return 0;
}

struct node *create_ll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data : ");
    scanf("%d",&num);
    while(num != -1){
        if(start == NULL){
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            start = new_node;
        }else{
            ptr=start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next = new_node;
            new_node->prev = ptr;
            new_node->next = NULL;
        }
        printf("\nEnter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start){
    printf("Display the data\n");
    struct node *ptr;
    ptr = start;
    while(ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node;
    int num;
    printf("Inserting at the beginning \n");
    printf("Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
    return start;
}

struct node * insert_end(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\nInserting at the End");
    printf("\nEnter the data :");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != NULL){
        ptr= ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = NULL;
    return start;
}

struct node *insert_before(struct node * start){
    struct node *new_node, *ptr;
    int num, val;
    printf("Insert Before \n");
    printf("Enter the Data :");
    scanf("%d", &num);
    printf("Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val){
        ptr = ptr->next;
    }
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;
    return start;
}

struct node *insert_after(struct node * start){
    struct node *new_node, *ptr;
    int num, val;
    printf("Insert After\n");
    printf("Enter the data :");
    scanf("%d", &num);
    printf("Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val){
        ptr= ptr->next;
    }
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
    return start;
}

struct node *delete_beg(struct node *start){
    printf("Delete at the beginning \n");
    struct node *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}

struct node * delete_end(struct node *start){
    printf("Delete at the end \n");
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;

}

struct node * delete_after(struct node *start){
    struct node *ptr, *temp;
    int val;
    printf("Delete After \n");
    printf("Enter the value after which the node has to deleted : ");
    scanf("%d",&val);
    ptr = start;
    while(ptr->data != val){
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return start;
}

struct node *delete_before(struct node *start){
    struct node *ptr, *temp;
    int val;
    printf("Delete before\n");
    printf("Enter the value which the noode has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    while(ptr->data != val){
        ptr = ptr->next;
    }
    temp = ptr->prev;
    if(temp == start){
        start = delete_beg(start);
    }else{
        ptr->prev = temp->prev;
        temp->prev->next = ptr->next;
    }
    free(temp);
    return start;
}

struct node * delete_list(struct node *start){
    while(start!=NULL){
        start = delete_beg(start);
    }

    return start;
}