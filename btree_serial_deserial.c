#include<stdio.h>
#include<stdlib.h>

struct node {
    int node_value;
    struct bst *lstree;
    struct bst *rstree;
};

typedef struct node bst;

bst *insert_node(bst *root, int node);
void iterate(bst *root);

int main () {
    bst *root = NULL;
    int node_values[6] = {20, 4, 8, 25, 30, 31};
    int i =0;
 
    root = (struct node*) malloc(sizeof(bst));
    if (root == NULL) {
       printf("Error: root node, malloc failed\n");
       return 1;
    }
    
    for (i = 0; i<=5; i++) {
       root = insert_node(root, node_values[i]);
    }
    
   iterate(root);


   return 0;
}


bst *insert_node(bst *root, int node) {
   bst *new_node = NULL;

    new_node = (struct node*) malloc(sizeof(bst));
    if (new_node == NULL) {
       printf("Error: new_node node, malloc failed\n");
       return new_node;
    }

    if (root == NULL) {
        new_node->node_value = node;
        new_node->lstree = new_node->rstree = NULL; 
        return new_node;
    }

    if(node < root->node_value) {       
       new_node->lstree = insert_node(root->lstree, node);
    } else {
       new_node->rstree = insert_node(root->rstree, node);
    }

    return new_node;
}

void iterate(bst *root) {
   if (root) {
      printf("%d\n", root->node_value);
      iterate(root->lstree);
      iterate(root->rstree);
      return;
   }
   
   printf("Tree is empty\n");
   return;
}
