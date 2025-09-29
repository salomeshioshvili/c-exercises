#include <stdio.h>
#include <stdlib.h>
#include "library.h"

#define INITIAL_CAPACITY 2

int main() {
    int* numbers = malloc(INITIAL_CAPACITY * sizeof(int));
    if (!numbers) {
        printf("Initial memory allocation failed!\n");
        return 1;
    }
    
    int capacity = INITIAL_CAPACITY;
    int count = 0;
    
    printf("Enter numbers (negative to stop): ");
    
    int result = read_numbers(&numbers, &capacity, &count);
    if (result != 0) {
        free(numbers);
        return result;
    }
    
    if (count > 0) {
        print_results(numbers, count);
    } else {
        printf("No numbers entered.\n");
    }
    
    free(numbers);
    return 0;
}
