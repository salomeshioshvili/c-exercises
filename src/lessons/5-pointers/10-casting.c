#include <stdio.h>

int main() {
  int x = 5;
  double y = (double)x; // Cast int to double
  printf("x: %d, y: %f\n", x, y);
  int z = (int)7.999; // Cast double to int (truncates)
  printf("z: %d\n", z);
  return 0;
}
