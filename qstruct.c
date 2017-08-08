#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node llist;

void display();
int enq(int val);
void deq();
llist *front, *rear, *front1, *new_node;

int main() {
   enq(3); 
   enq(5);
   enq(5);
   enq(2);
   enq(2);
   display();
   deq();
   display();
}

void deq() {
    front1 = front;
    if(front == NULL) {
       printf("queue is empty\n");
    } else {
    printf("Front element = %d\n", front->value);
    free(front);    
    front = front1;
    }

}

int enq(int val) {
  if (rear == NULL) {
      rear = malloc(sizeof(llist));
      rear->value = val;
      rear->next = NULL; 
      front = rear; 
   } else {
      new_node = malloc(sizeof(llist));
      rear->next = new_node;
      new_node->value = val;
      new_node->next = NULL;
      rear = new_node;
   }

   return 0;
}

 void display() {
    front1 = front;
    if ((front == NULL) && (rear == NULL)) {
        printf("Queue is empty\n");
        return;
    }
    while (front1 != rear) {
        printf("%d\n", front1->value);
        front1 = front1->next;
    }

    if(front == rear) {
       printf("%d\n", front1->value);
    }
}
