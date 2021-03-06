//
// Created by Roberto Marinheiro on 29/03/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "include/array.h"
#include "include/stack.h"
#include "include/binary_tree.h"

// Array
// array creation
Array * create_array(int size){
    printf("\nCreate Array");
    Array *array = (Array*)calloc(1, sizeof(Array)); // Allocate Array: array
    array->size = size; // Set array size
    array->array = (int*)calloc(array->size ,sizeof(int)); // Allocate array->array
    for(int i=0; i<array->size; i++){ // Set [1,2 ... size], as default for all position
        array->array[i] = i;
    }
    print_array(array);
    return array;
}

// randomize array
void randomize_array(Array *array){
    printf("\nRandomize Array");
    int random = 0;
    for (int i = 0; i < array->size; ++i) {
        array->array[i] = rand() % (999 + 1) + 0;
    }
    print_array(array);
}

// print array
void print_array(Array *array){
    printf("\n[");
    for (int i = 0; i < array->size; ++i) {
        printf(" %d", array->array[i]);
        if(i != array->size -1){
            printf(",");
        }
    }
    printf("]");
}

// array reverse
void reverse_array(Array *array) {
    printf("\nReverse Array");
    int half_size = array->size / 2, aux = 0;
    for (int i = 0; i < half_size; i++) {
        aux = array->array[i];
        array->array[i] = array->array[array->size - i - 1];
        array->array[array->size - i - 1] = aux;
    }
    print_array(array);
}

// bubble sort
void bubble_sort(Array *array){
    printf("\nBubble Sort");
    int aux = 0;
    for (int i = 0; i < array->size; ++i) {
        for (int j = 0; j < array->size -1; ++j) {
            if(array->array[j] > array->array[j+1]){
                aux = array->array[j];
                array->array[j] = array->array[j+1];
                array->array[j+1] = aux;
            }
        }
    }
    print_array(array);
}

// selection sort
void selection_sort(Array *array){
    printf("\nSelection Sort");
    int minimum, aux;
    for (int i = 0; i < array->size - 1; ++i) {
        minimum = i;
        for (int j = i + 1; j < array->size; ++j) {
            if(array->array[minimum] > array->array[j]){
                aux = array->array[i];
                array->array[i] = array->array[j];
                array->array[j] = aux;
            }
        }
    }
    print_array(array);
}

// recursive binary search
int recursive_binary_search(Array *array, int start, int end, int element){
    if(start > end) return -1;
    int mid = (start+end) / 2;
    if(array->array[mid] == element){
        return mid;
    }
    else if( element < array->array[mid])
        return recursive_binary_search(array, start, mid - 1, element);
    else
        return recursive_binary_search(array, mid + 1, end, element);
}

// destroy array
void destroy_array(Array *array){
    printf("\nDestroy Array");
    free(array->array);
    free(array);
}

// test array
void test_array(){
    printf("\nTest Array");
    Array *array = create_array(100);
    reverse_array(array);
    randomize_array(array);
    bubble_sort(array);
    randomize_array(array);
    selection_sort(array);
    printf("\nBinary Search -> Searching: %d Result: %d ", array->array[10], recursive_binary_search(array, 0, 99, array->array[10]));
    destroy_array(array);
}

// Stack
// create stack
Stack *create_stack(int max_size){
    printf("\nCreate Stack");
    Stack *stack = (Stack*)calloc(1, sizeof(Stack)); // Allocate Stack: stack
    stack->top = 0; // Set top = 0
    stack->max_size = max_size; // Set max_size as the max_size in parameter
    stack->stack = (int*)calloc(stack->max_size, sizeof(int)); // Allocate stack list
    for (int i = 0; i < stack->max_size; ++i) { // Initializes as zeros
        stack->stack[i] = 0;
    }
    return stack; // return stack
}

// is empty
int is_empty(Stack *stack){
    return (stack->top == 0) ? 1 : 0;
}

// is full
int is_full(Stack *stack){
    return (stack->top == stack->max_size) ? 1 : 0;
}

// push
void push(Stack *stack, int item){
    if(!is_full(stack)){
        printf("\nPushing in Stack: %d", item);
        stack->top += 1;
        stack->stack[stack->top] = item;
    }else{
        printf("\nCan't push in stack -> Stack is full");
    }
}

// pop
int pop(Stack *stack){
    if(!is_empty(stack)){
        int item = stack->stack[stack->top];
        stack->stack[stack->top] = 0;
        stack->top -= 1;
        printf("\nPopping from Stack: %d", item);
        return item;
    }
    printf("\nCan't pop from stack -> Stack is empty, returning %d", NAN);
    return NAN; // returns a 'not_a_number
}

// reverse stack
void reverse_stack(Stack *stack){
    printf("\nReverse stack");
    int item, max_size = stack->max_size;
    Stack *aux = create_stack(max_size);
    while(!is_empty(stack)){ // popping from stack and pushing in aux
        item = pop(stack);
        push(aux, item);
    }
    print_stack(aux);
    destroy_stack(aux);
}

// print stack
void print_stack(Stack *stack){
    if(is_empty(stack)){
        printf("\nCan't print stack -> stack empty");
        return;
    }
    printf("\nPrint Stack\n");
    for (int i = stack->top; i > 0; --i) {
        if(i == stack->top){
            printf(" | %d | --> TOP \n", stack->stack[stack->top]);
        }else {
            printf(" | %d | \n", stack->stack[i]);
        }
    }
}

// destroy stack
void destroy_stack(Stack *stack){
    printf("\nDestroy Stack");
    free(stack->stack);
    free(stack);
}

// test stack
void test_stack(){
    Stack *stack = create_stack(5);
    push(stack, 1);
    push(stack, 0);
    push(stack, 3);
    push(stack, 2);
    push(stack, 4);
    print_stack(stack);
    reverse_stack(stack);
    destroy_stack;
}

// Binary Tree
// create node
Node *create_node(int value){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// clone node
Node *clone_node(Node *node){
    Node *new = (Node*)calloc(1, sizeof(Node));
    new->value = node->value;
    new->left = node->left;
    new->right = node->right;
    return node;
}

// insert node
void insert_node(Node *root, int value){
    if(root->value == 0){
        // insert in current position because is empty
        root->value = value;
    }
    else{
        if (value < root->value){
            // insert left
            if (root->left != NULL){
                insert_node(root->left, value);
            }
            else{
                root->left = create_node(value);
                root->left->left = NULL;
                root->left->right = NULL;
            }
        }
        else{
            if (value >= root->value){
                // insert right
                if (root->right != NULL){
                    insert_node(root->right, value);
                }
                else{
                    root->right = create_node(value);
                    root->right->left = NULL;
                    root->right->right = NULL;
                }
            }
        }
    }
}

// draw binary tree secondary
void draw_binary_tree_secondary(Node *root, int depth, char *path, int right){
    if(root== NULL){
        return;
    }
    depth++; // increase spacing
    draw_binary_tree_secondary(root->right, depth, path, 1); // start with right node

    if(depth > 1){
        path[depth-2] = 0; // set | draw map
        if(right)
            path[depth-2] = 1;
    }
    if(root->left)
        path[depth-1] = 1;

    printf("\n"); // print root after spacing

    for(int i=0; i<depth-1; i++){
        if(i == depth-2) printf("+");
        else if(path[i]) printf("|");
        else printf(" ");
        for(int j=1; j<space; j++)
            if(i < depth-2) printf(" ");
            else printf("-");
    }

    printf("%d\n", root->value);

    for(int i=0; i<depth; i++){ // vertical spacers below
        if(path[i]) printf("|");
        else printf(" ");
        for(int j=1; j<space; j++)
            printf(" ");
    }
    draw_binary_tree_secondary(root->left, depth, path, 0); // go to left node
}

// draw binary tree primary
void draw_binary_tree_primary(Node *root){
    char path[255] = {};
    draw_binary_tree_secondary(root, 0, path, 0); //initial depth is 0
    printf("\n");
}

// print binary tree elements in increasing order
void print_tree(Node* node) {
    if (node == NULL) return;
    print_tree(node->left);
    printf("%d ", node->value);
    print_tree(node->right);
}

// print post order
void print_post_order(Node* node) {
    printf("\nPrint Post order\n");
    if (node == NULL) return;
    print_tree(node->left); // first recur on both subtrees
    print_tree(node->right);
    printf("%d ", node->value); // then deal with the node
}

// mirror binary tree
void mirror_binary_tree(Node* node){
    if (node==NULL) return;
    else{
        Node* temp;
        mirror_binary_tree(node->left);
        mirror_binary_tree(node->right);
        // swap
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

// destroy binary tree
void destroy_binary_tree(Node *root){
    if(root){
        destroy_binary_tree(root->left);
        destroy_binary_tree(root->right);
        free(root);
    }
}

// destroy node
void destroy_node(Node *node){
    free(node);
}

// test binary tree
void test_binary_tree(){
    Node *root = create_node(5);
    insert_node(root, 2);
    insert_node(root, 3);
    insert_node(root, 4);
    insert_node(root, 6);
    draw_binary_tree_primary(root);
    print_post_order(root);
    mirror_binary_tree(root);
    draw_binary_tree_primary(root);
    destroy_binary_tree(root);
}

// Main
int main() {
//    test_array();
//    test_stack();
    test_binary_tree();
    return 0;
}