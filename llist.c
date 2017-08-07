#include<stdio.h>
#include<stdlib.h>


struct node {
int value;
struct node *next;
};

typedef struct node llist;

int push(llist *node1, int num);
int iterate(llist *head);
llist *get_last(llist *head);
int pop(llist *head);

int main() {
    llist *head, *next = NULL;
    int element = 0;
    head = malloc(sizeof(llist));
    if(head == NULL) {
        printf ("Error: [[Element: head]]");
        return 1;
    }
    head->value = 1;
    head->next = NULL;

    //push(head, 2);
    //push(head, 3);
    printf("push 4\n");
    push(head, 4);
    
    printf("iterate\n");
    iterate(head);
    
    printf("pop\n");
    element = pop(head);
    printf ("%d\n", element); 

    printf("push 5\n");
    push(head, 5);

    printf("iterate\n");
    iterate(head);
    
    return 0;
}

int push(llist *current_node, int num ) {

    llist *new_node, *tail = NULL;;
    new_node = malloc(sizeof(llist));
    if(new_node == NULL) {
        printf("Malloc returned NULL\n");
        return 1;
    }
    tail = malloc(sizeof(llist));
    if(tail == NULL) {
        printf("Malloc returned NULL\n");
        return 1;
    }
    tail = get_last(current_node);
    new_node->value = num;
    new_node->next = NULL;
    tail->next = new_node; 
    return 0;

}

int iterate(llist *head) {
    llist *current_node = NULL;
    current_node = malloc(sizeof(llist));   
    if(current_node == NULL) {
        printf("Malloc returned NULL\n");
        return 1;
    }
    current_node = head;

    while (current_node != NULL){
        printf("%d\n", current_node->value);
        current_node = current_node->next;
   }
   return 0;
}

llist *get_last(llist *head) {
    llist *iterator = NULL;
    iterator = malloc(sizeof(llist));
    if(iterator == NULL) {
        printf("Error:get_last() function malloc error\n");
        exit(1);
    }
    iterator = head;
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    return iterator; 
}

int pop(llist *head){
    llist *curr_node, *next_node = NULL;
    curr_node = malloc(sizeof(llist));
    next_node = malloc(sizeof(llist));
    curr_node = head;
    int value;
    if (head->next == NULL) {
      value = head->value;
      head=NULL;
      return value;
    }
    next_node = head->next;

    while(next_node->next != NULL){
       curr_node = curr_node->next;
       next_node = next_node->next;
   }
   curr_node->next = NULL;
   value = next_node->value;
   free (next_node);
   return value; 
}
