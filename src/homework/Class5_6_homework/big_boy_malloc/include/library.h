#ifndef LIBRARY_H
#define LIBRARY_H

int* resize_array(int* arr, int new_capacity);
double calculate_sum(int* arr, int size);
double calculate_average(int* arr, int size);
void print_numbers(int* arr, int size);
int read_numbers(int** numbers, int* capacity, int* count);
void print_results(int* arr, int size);

#endif
