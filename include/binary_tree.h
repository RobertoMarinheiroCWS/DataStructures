//
// Created by Roberto Marinheiro on 29/03/20.
//

#ifndef DATA_STRUCTURES_BINARY_TREE_H
#define DATA_STRUCTURES_BINARY_TREE_H

// Node Definition
typedef struct _Node{
    int value; // content
    struct _Node *left;
    struct _Node *right;
}Node;

// Binary Tree Definition
typedef Node *binary_tree; // tree

// Binary Tree Functions
Node *create_node(int value); // allocate memory and return a tree
void insert_node(Node *tree, int value); // insert node
void destroy_binary_tree(Node *tree); // deallocate binary tree memory

#endif //DATA_STRUCTURES_BINARY_TREE_H