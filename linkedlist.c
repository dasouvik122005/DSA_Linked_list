// Here, I discussed how to implement a linked list and how insertion and deletion occur at different position


#include <stdio.h>
#include <stdlib.h>

struct node *start;

typedef struct node {
    int data;
    struct node *next;  
} node;

node *getnode(int x) {
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr -> data = x;
    ptr -> next = NULL;
    return ptr;  // Returning the allocated node
}

node *build() {
    node *temp1, *temp2, *temp3, *temp4, *temp5;  // Corrected variable names
    temp1 = getnode(10);
    temp2 = getnode(20);
    temp3 = getnode(30);
    temp4 = getnode(40);
    temp5 = getnode(50);
    temp1 -> next = temp2;
    temp2 -> next = temp3;
    temp3 -> next = temp4;
    temp4 -> next = temp5;
    temp5 -> next = NULL;
    

    return temp1;  // Returning head of the list
}

void print(node *s) {  // Added parameter to function
    while (s != NULL) {
        printf("%d->", s->data);
        s = s->next;
    }
    printf("NULL \n");
}

void begin(int key){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    if (temp != NULL ){
        temp -> data = key;
        temp -> next = start;
        start = temp;
    }
}

void end(int key){
    struct node *temp, *ptr;
    temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp -> data = key;
        temp -> next = NULL;
        if(start == NULL){
            start = temp;
            return;
        }
        ptr = start;
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
        ptr -> next = temp;
    }
}

void del_beg(){
    struct node *ptr;
    if(start == NULL){
        return;
    }
    ptr = start;
    start = start ->next;
    free (ptr);
}

void del_end(){
    struct node *ptr;
    if(start == NULL || start->next == NULL){
        return;
    }
    ptr = start;
    while(ptr -> next -> next != NULL){
        ptr = ptr -> next;
    }
    free(ptr -> next);
    ptr -> next = NULL;
}

int main() {
    start = NULL;
    start = build();  
    print((start));
    begin(100);
    print(start);
    end(1000);
    print(start);
    del_beg();
    print(start);
    del_end();
    print(start);    
    return 0;
}
