#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

///*** DO NOT CHANGE ANY FUNCTION DEFINITIONS ***///

// Recall node is defined in the header file
node *root = NULL;

node* find_node_and_prev(int, pnode*);
void find_min(node*, pnode*);

// Insert a new node into the binary tree with node_id and data
void insert_node(int node_id, int data) {
    node *new_node = (node *) malloc(sizeof(node));
    node *prev = NULL;
    node *node = root;

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->node_id = node_id;
    new_node->data = data;
    while(node != NULL) {
        prev = node;
        if (node_id < node->node_id)
            node = node->left;
        else
            node = node->right;
    }
    if (prev == NULL)
        root = new_node;
    else if (node_id > prev->node_id)
        prev->right = new_node;
    else
        prev->left = new_node;
}

node * find_node(int node_id) {
    return find_node_and_prev(node_id, NULL);
}

node * find_node_and_prev(int node_id, pnode *nodep) {
    node *prev = NULL;
    node *node = root;

    while (node != NULL && node->node_id != node_id) {
        prev = node;
        if (node_id < node->node_id)
            node = node->left;
        else if (node_id > node->node_id)
            node = node->right;
    }
    if (nodep != NULL) {
        *nodep = prev;
    }

    return node;
}

// Find the node with node_id, and return its data
int find_node_data(int node_id) {
    node *node = find_node(node_id);

    return node == NULL ? 0 : node->data;
}

void find_min(node *node, pnode *minp) {
    while (node->left != NULL)
        node = node->left;
    *minp = node;
}

///***** OPTIONAL: Challenge yourself w/ deletion if you want ***///
//Find and remove a node in the binary tree with node_id. 
//Children nodes are fixed appropriately.
void remove_node(int node_id) {
    node *prev;
    node *target = find_node_and_prev(node_id, &prev);

    if (target == NULL)
        return;
    if (target->left == NULL && target->right == NULL) {
        if (prev == NULL)
            root = NULL;
        else {
            if (prev->left == target)
                prev->left = NULL;
            else
                prev->right = NULL;
        }
    }
    else if (target->left != NULL && target->right != NULL) {
        node *successor;
        node *new_node = malloc(sizeof(node));

        find_min(target->right, &successor);
        printf("successor: %d\n", successor->node_id);
        new_node->node_id = successor->node_id;
        new_node->data = successor->data;
        remove_node(successor->node_id);
        printf("target->right: %d\n", target->right->node_id);
        printf("prev: %d\n", prev->node_id);
        new_node->left = target->left;
        new_node->right = target->right;
        if (prev == NULL) {
            root = new_node;
        }
        else {
            if (target == prev->left)
                prev->left = new_node;
            else
                prev->right = new_node;
        }
    }
    else {
        if (prev == NULL) {
            if (target->left != NULL)
                root = target->left;
            else
                root = target->right;
        }
        else {
            if (target->left != NULL) {
                if (target == prev->left)
                    prev->left = target->left;
                else
                    prev->right = target->left;
            }
            else {
                if (target == prev->left)
                    prev->left = target->right;
                else
                    prev->right = target->right;
            }
        }
    }
    free(target);
}

