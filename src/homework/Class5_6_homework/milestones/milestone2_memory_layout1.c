#include <stdio.h>

int main() {
    // original example with int
    printf("=== Testing with int ===\n");
    int a = 1;
    int b = 2;
    printf("Address of a: %p\n", (void*)&a);
    printf("Address of b: %p\n", (void*)&b);
    printf("Distance between a and b: %ld bytes\n", (char*)&b - (char*)&a);
    
    // Test with double
    printf("\n=== Testing with double ===\n");
    double d1 = 1.0;
    double d2 = 2.0;
    printf("Address of d1: %p\n", (void*)&d1);
    printf("Address of d2: %p\n", (void*)&d2);
    printf("Distance between d1 and d2: %ld bytes\n", (char*)&d2 - (char*)&d1);
    
    // Test with char
    printf("\n=== Testing with char ===\n");
    char c1 = 'A';
    char c2 = 'B';
    printf("Address of c1: %p\n", (void*)&c1);
    printf("Address of c2: %p\n", (void*)&c2);
    printf("Distance between c1 and c2: %ld bytes\n", (char*)&c2 - (char*)&c1);
    
    // Test with mixed types
    printf("\n=== Testing with mixed types ===\n");
    int i = 42;
    double d = 3.14;
    printf("Address of i: %p\n", (void*)&i);
    printf("Address of d: %p\n", (void*)&d);
    printf("Distance between i and d: %ld bytes\n", (char*)&d - (char*)&i);
    
    printf("\n=== Answers ===\n");
    printf("• Distance is 4 bytes for int because int is 4 bytes on most systems\n");
    printf("• Double shows 8 bytes distance (doubles are 8 bytes)\n");
    printf("• Char shows 1 byte distance (chars are 1 byte)\n");
    printf("• Mixed types may have padding for alignment requirements\n");
    
    return 0;
}
