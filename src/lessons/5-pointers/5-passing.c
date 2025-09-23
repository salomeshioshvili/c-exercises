#include <stdio.h>

void increment_val(int x /*This is called passing by value*/) { x++; }

void increment_ptr(int *x /*This is called passing by pointer*/) {
  // Receiving a pointer allows us to modify the original variable
  // But forces us to check for NULL
  if (x == NULL) {
    printf("The pointer is null\n");
    return;
  }
  (*x)++;
}

int main() {
  int x = 5;
  increment_val(x);
  printf("%d\n", x); // This will print 5, we did not modify the original x
  increment_ptr(&x);
  printf("%d\n", x); // This will print 6, we modified the original x
  return 0;
}
