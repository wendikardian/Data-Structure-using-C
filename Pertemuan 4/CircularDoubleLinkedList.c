#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main(){
    int option;
    do{
        printf("\n\n ** MAIN MENU *** \n");
        printf("1. Create a list\n");
        printf("2. Display the list\n");
        printf("3. Add at the beginning of the list\n");
        printf("4. Add at the end of the list\n");
        printf("5. Delete at the beginning of the list\n");
        printf("6. Delete at the end of the list\n");
        printf("7. Delete at the give value\n");
        printf("8. EXIT\n");
        printf("\n\n enter your option : ");
        scanf("%d", &option);
        switch (option){
            case 1:
                start = create_ll(start);
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
                start = delete_beg(start);
                break;
            case 6:
                start = delete_end(start);
                break;
            case 7:
                start = delete_node(start);
                break;
        }
    }while(option != 8);
    return 0;
}


struct node *create_ll(struct node *start){

    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to end inserting \n");
    printf("Enter the data : ");
    scanf("%d",&num);
    while(num != -1){
        if(start == NULL){
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->data = num;
            new_node->next = NULL;
            start = new_node;
        }else if(start->next == NULL){
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data =num;
            new_node->prev = start;
            new_node->next = start;
            start->next = new_node;
            start->prev = new_node;
        }
        else{
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            ptr = start;
            while(ptr->next != start){
                ptr =ptr->next;
            }
            new_node->prev = ptr;
            ptr->next = new_node;
            new_node->next= start;
            start->prev = new_node;
        }
        printf("Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr->next != start){
        printf("%d \t", ptr->data);
        ptr =ptr->next;
    }
    printf("%d\t", ptr->data);
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *ptr, *new_node;
    int num;
    printf("\nEnter the data to insert at the beginning : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    new_node->prev = ptr;
    ptr->next = new_node;
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *ptr, *new_node;
    int num;
    printf("\nEnter data to insert at the end : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
    new_node->next = start;
    start->prev = new_node;
    return start;
}

struct node * delete_beg(struct node *start){
    struct node *ptr, *temp;
    ptr = start;
    printf("\nDeleting at the beginning \n");
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->next = start->next;
    temp = start;
    start= start->next;
    start->prev = ptr;
    free(temp);
    return start;
}


struct node * delete_end(struct node *start){
    struct node *ptr;
    printf("\ndeleting at the end of the node\n");
    ptr = start;
    while(ptr->next != start){
        ptr = ptr->next;
    }
    ptr->prev->next = start;
    start->prev = ptr->prev;
    free(ptr);
    return start;
}


struct node *delete_node(struct node *start){
    struct node *ptr;
    int val;
    printf("\nEnter the value the node which has to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    if(ptr->data ==val){
        start = delete_node(start);
        return start;
    }else{
        while(ptr->data !=val && ptr->next !=start){
            ptr = ptr->next;
        }
        if(ptr->data == val){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }else{
            printf("\nData not found :( \n");
        }
        
        return start;
    }
}