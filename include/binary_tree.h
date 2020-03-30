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
void draw_binary_tree_primary(Node *tree); // draw binary tree primary
void print_tree(Node *tree); // print binary tree elements in increasing order
void test_binary_tree(); // tests binary tree functions
void print_post_order(Node *tree); // print post order
void mirror_binary_tree(Node* node); // mirror binary tree
Node *get_min_value_node(Node* node); // get the minimum node
Node *delete_node(Node *tree, int value); // delete node
void destroy_binary_tree(Node *tree); // deallocate binary tree memory

#endif //DATA_STRUCTURES_BINARY_TREE_H