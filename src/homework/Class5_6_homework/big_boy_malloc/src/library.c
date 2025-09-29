#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int* resize_array(int* arr, int new_capacity) {
    int* new_arr = realloc(arr, new_capacity * sizeof(int));
    return new_arr;
}

double calculate_sum(int* arr, int size) {
    if (!arr || size <= 0) return 0;
    
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculate_average(int* arr, int size) {
    if (!arr || size <= 0) return 0;
    return calculate_sum(arr, size) / size;
}

void print_numbers(int* arr, int size) {
    if (!arr || size <= 0) {
        printf("No numbers to print.\n");
        return;
    }
    
    printf("Numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int read_numbers(int** numbers, int* capacity, int* count) {
    if (!numbers || !capacity || !count) {
        printf("Invalid parameters!\n");
        return -1;
    }
    
    int input;
    while (scanf("%d", &input) == 1 && input >= 0) {
        if (*count >= *capacity) {
            *capacity *= 2;
            int* new_arr = resize_array(*numbers, *capacity);
            if (!new_arr) {
                printf("Memory reallocation failed!\n");
                return -1;
            }
            *numbers = new_arr;
        }
        
        (*numbers)[*count] = input;
        (*count)++;
        printf("Enter next number: ");
    }
    
    return 0;
}

void print_results(int* arr, int size) {
    if (!arr || size <= 0) return;
    
    print_numbers(arr, size);
    printf("Sum: %.2f\n", calculate_sum(arr, size));
    printf("Average: %.2f\n", calculate_average(arr, size));
}
