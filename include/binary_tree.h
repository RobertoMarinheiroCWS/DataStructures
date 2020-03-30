//
// Created by Roberto Marinheiro on 29/03/20.
//

#ifndef DATA_STRUCTURES_BINARY_TREE_H
#define DATA_STRUCTURES_BINARY_TREE_H

#define space 5 // defining the space between nodes in draw binary tree

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
void draw_binary_tree_secondary(Node *tree, int depth, char *path, int right); // test binary tree
void draw_binary_tree_primary(Node *tree); // draw binary tree primary
void print_elements_in_order_binary_tree(Node *tree); // print binary tree elements in increasing order
void test_binary_tree(); // tests binary tree functions
#endif //DATA_STRUCTURES_BINARY_TREE_H