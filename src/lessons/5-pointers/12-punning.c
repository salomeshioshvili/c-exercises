#include <stdio.h>

int main() {
  int x = 1178658487;
  float *float_ptr = (float *)&x;                  // Cast int* to float*
  printf("Value of x as float: %f\n", *float_ptr); // Dereference float*
  char bytes[4] = {1, 2, 3, 4};
  double* d_ptr = (double*)&bytes;
  printf("Value of bytes as double: %g\n", *d_ptr); // Dereference as double
  return 0;
}
