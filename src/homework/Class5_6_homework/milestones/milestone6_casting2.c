#include <stdio.h>

int main() {
    int x = 0;
    
    // Cast int* to double* and dereference
    double* d_ptr = (double*)&x;
    printf("Value of x as double: %g\n", *d_ptr);
    
    // Same with float
    float* f_ptr = (float*)&x;
    printf("Value of x as float: %g\n", *f_ptr);
    
    printf("\nExplanation:\n");
    printf("• double is 8 bytes, int is 4 bytes\n");
    printf("• Reading 4-byte int as 8-byte double reads uninitialized memory\n");
    printf("• This causes unpredictable results (undefined behavior)\n");
    printf("• float is 4 bytes like int, so it reads the same memory = 0.0\n");
    
    return 0;
}
