#include <stdio.h>
#include <assert.h>

#define Type double

int main() {
    Type a;
    size_t addr = (size_t)&a;
    
    printf("Address of variable: %p\n", (void*)&a);
    printf("Address as integer: %zu\n", addr);
    printf("Size of Type: %zu bytes\n", sizeof(Type));
    printf("Address modulo size: %zu\n", addr % sizeof(Type));
    
    assert(addr % sizeof(Type) == 0);
    printf("Assertion passed!\n");
    
    printf("\nExplanation:\n");
    printf("This always works because the compiler ensures memory alignment.\n");
    printf("Variables are placed at addresses that are multiples of their size\n");
    printf("for optimal memory access performance.\n");
    
    return 0;
}
