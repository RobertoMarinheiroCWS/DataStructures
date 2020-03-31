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
Node *clone_node(Node *node); // clone node
void insert_node(Node *tree, int value); // insert node
void draw_binary_tree_secondary(Node *tree, int depth, char *path, int right); // test binary tree
void draw_binary_tree_primary(Node *root); // draw binary tree primary
void print_tree(Node *root); // print binary tree elements in increasing order
void test_binary_tree(); // tests binary tree functions
void print_post_order(Node *root); // print post order
void mirror_binary_tree(Node* node); // mirror binary tree
void destroy_binary_tree(Node *root); // deallocate binary tree memory
void test_binary_tree(); // test binary tree

// @TODO -> build delete_tree(Node *root, int value);

#endif //DATA_STRUCTURES_BINARY_TREE_H