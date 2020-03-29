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

#endif //DATA_STRUCTURES_BINARY_TREE_H