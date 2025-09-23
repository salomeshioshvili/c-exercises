#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

void cleanup() {
    printf("Program ending. errno = %d\n", errno);
}

void print_array(int *arr, int size) {
    assert(arr != NULL);
    assert(size >= 0);

    if (size == 0) {
        printf("Empty Array\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int vectorized_divide(int *a, int *b, int *result, int size) {
    assert(a != NULL && b != NULL && result != NULL);
    assert(size >= 0);

    for (int i = 0; i < size; i++) {
        if (b[i] == 0) {
            fprintf(stderr, "Error: Division by zero at index %d\n", i);
            return -1;
        }
        result[i] = a[i] / b[i];
    }
    return 0; 
}

int main() {
    atexit(cleanup);

    int numbers[5] = {1, 2, 3, 4, 20};
    int divisors[5] = {0, 1, 2, 3, 4};
    int results[5] = {0};

    if (vectorized_divide(numbers, divisors, results, 5) != 0) {
        return EXIT_FAILURE;
    }
    print_array(results, 5);
    return EXIT_SUCCESS;
}