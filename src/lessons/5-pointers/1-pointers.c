#include <stdio.h>

int main() {
  // Declare an integer variable
  int x = 5;
  // Declare a pointer variable that stores the address of x
  int *ptr = &x;
  // Dereference the pointer to get the value of x
  printf("Value of x: %d\n", *ptr);
  // Print the address of x
  printf("Address of x: %p\n", &x);
  // Print the address stored in ptr
  printf("Address stored in ptr: %p\n", ptr);
  return 0;
}
