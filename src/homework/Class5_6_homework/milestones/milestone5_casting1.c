#include <stdio.h>

int main() {
    int int_val = 42;
    
    float float_val = (float)int_val;
    printf("Integer %d as float: %f\n", int_val, float_val);
    
    float* float_ptr = (float*)&int_val;
    printf("Integer %d reinterpreted as float: %f\n", int_val, *float_ptr);
    
    int_val = 0x40000000;
    printf("Integer 0x%x reinterpreted as float: %f\n", int_val, *(float*)&int_val);
    
    return 0;
}
