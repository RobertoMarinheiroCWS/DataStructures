//
// Created by Roberto Marinheiro on 29/03/20.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#define NAN 999999

// Stack Definition
typedef struct{
    int max_size, top;
    int *stack;
}Stack;

// Stack functions
Stack *create_stack(int size); // allocate memory and return a stack
int is_empty(Stack *stack); // check if stack is empty
int is_full(Stack *stack); // check if stack is full
void push(Stack *stack, int item); // add item in stack
int pop(Stack *stack); // remove item from stack
void reverse_stack(Stack *stack); // reverse the stack
void print_stack(Stack *stack); // print stack itens
void destroy_stack(Stack *stack); // deallocate stack memory
void test_stack(); // test stack functions

#endif //DATA_STRUCTURES_STACK_H
