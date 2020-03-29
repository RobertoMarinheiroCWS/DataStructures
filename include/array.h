//
// Created by Roberto Marinheiro on 23/03/20.
//

#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H

// Array Definition
typedef struct{
    int *array;
    int size;
}Array;

// Array Functions
Array * create_array(int size); // allocates memory and returns an Array struct
void randomize_array(Array *array); //
void print_array(Array *array); // print array
void reverse_array(Array *array); // reverse the input array
void bubble_sort(Array *array); // bubble sort
void selection_sort(Array *array); // selection sort
int recursive_binary_search(Array *array, int start, int end, int element); // recursive binary search
void destroy_array(Array *array); // deallocates memory taken by Array struct
void test_array(); // test array functions

#endif //DATA_STRUCTURES_ARRAY_H
