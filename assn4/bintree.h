#ifndef BINTREE_H
#define BINTREE_H

// Node structure should have an int node_id, an int data, and pointers to left and right child nodes
typedef struct _node {
    int node_id;
    int data;
    struct _node *left;
    struct _node *right;
} node, *pnode;

///*** DO NOT CHANGE ANY FUNCTION DEFINITIONS ***///
// Declare the tree modification functions below...

void bintree_init(void);
void insert_node(int, int);
void remove_node(int);
int find_node_data(int);

#endif
