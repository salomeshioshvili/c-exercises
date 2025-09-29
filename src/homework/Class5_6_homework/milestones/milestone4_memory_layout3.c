#include <stdio.h>
#include <stdlib.h>

int main() {
    // Heap array
    int* heap_arr = (int*)malloc(1000 * sizeof(int));
    printf("Size of heap_arr pointer: %zu bytes\n", sizeof(heap_arr));
    printf("Size of 1000 ints should be: %zu bytes\n", 1000 * sizeof(int));
    
    // Stack array
    int stack_arr[1000];
    printf("Size of stack_arr: %zu bytes\n", sizeof(stack_arr));
    
    printf("\nExplanation:\n");
    printf("• heap_arr is just a pointer (8 bytes on 64-bit systems)\n");
    printf("• sizeof(heap_arr) gives the size of the pointer, not the allocated memory\n");
    printf("• sizeof(stack_arr) gives the actual size of the entire array\n");
    printf("• The compiler knows the size of stack arrays at compile time\n");
    
    free(heap_arr);
    return 0;
}
