#include <stdio.h>
int main() {
  int original = 5;
  int *alias = &original; // Reads as "alias points to to original"
  *alias = 10;            // Dereference alias and set the value to 10
  printf("original: %d\n", original);
  return 0;
}
