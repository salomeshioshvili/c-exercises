#include <stdio.h>
#include <stdlib.h>

int* resize_array(int* arr, int old_size, int new_size) {
    int* new_arr = realloc(arr, new_size * sizeof(int));
    return new_arr;
}

double calculate_sum(int* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculate_average(int* arr, int size) {
    if (size == 0) return 0;
    return calculate_sum(arr, size) / size;
}

void print_numbers(int* arr, int size) {
    printf("Numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int* numbers = malloc(2 * sizeof(int));
    int capacity = 2;
    int count = 0;
    int input;
    
    printf("Enter numbers (negative to stop): ");
    
    while (scanf("%d", &input) == 1 && input >= 0) {
        if (count >= capacity) {
            capacity *= 2;
            numbers = resize_array(numbers, count, capacity);
            if (!numbers) {
                printf("Memory allocation failed!\n");
                return 1;
            }
        }
        
        numbers[count] = input;
        count++;
        printf("Enter next number: ");
    }
    
    if (count > 0) {
        print_numbers(numbers, count);
        printf("Sum: %.2f\n", calculate_sum(numbers, count));
        printf("Average: %.2f\n", calculate_average(numbers, count));
    } else {
        printf("No numbers entered.\n");
    }
    
    free(numbers);
    return 0;
}
