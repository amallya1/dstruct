#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *lstree;
    struct node *rstree;
};

typedef struct node bstree;

bstree* insert_node(bstree *root, int value);
//int insert2_node(bstree **root, int value);
void iterate(bstree *root);

int main () {
    bstree *root = NULL;
    root = malloc(sizeof(bstree));
    if(root == NULL) {
        printf("Error: Node creation , malloc returned null");
        return 1;
    }
    root->key = 20;
    root->lstree = NULL;
    root->rstree = NULL;
    for (int i=0; i<25;i++){
      root=insert_node(root, i);
    }
    return 0;
}

bstree* insert_node(bstree *new_node, int value) {
    if (new_node == NULL) {
        new_node = malloc(sizeof(bstree));
        if (new_node == NULL) {
            return NULL;
        }
        new_node->key = value;
        printf("%d\n", new_node->key);
        new_node->lstree = NULL;
        new_node->rstree = NULL;
        return new_node;
    }
    if (value < new_node->key) {
        new_node->lstree = insert_node(new_node->lstree, value);
    } else {
        new_node->rstree = insert_node(new_node->rstree, value);
    }
    return new_node;
}


/*
int insert2_node(bstree **new_node, int value) {
    if (new_node == NULL) {
        new_node = malloc(sizeof(bstree));
        if (new_node == NULL) {
            return 1;
        }
        **new_node.key = value;
        printf("%d\n", *new_node->key);
        *new_node->lstree = NULL;
        *new_node->rstree = NULL;
        return 0;
    }
    if (value < *new_node->key) {
        insert_node(&new_node->lstree, value);
    } else {
        insert_node(&new_node->rstree, value);
    }
    return 0;
}
*/

void iterate(bstree *root) {
    if (root == NULL) {
        return;
    }

    iterate(root->lstree);
    printf("%d\n", root->key);
    iterate(root->rstree);

    return;  
}
