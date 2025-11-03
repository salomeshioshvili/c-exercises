#include <stdio.h>

void print_bits32(int x) {
  for (int i = 31; i >= 0; i--) {
    int bit = (x >> i) & 1;
    printf("%d", bit);
    if (i % 4 == 0 && i != 0) {
      printf(" ");
    }
  }
  printf("\n");
}

int main(void) {
  printf("=== Exercise 2: Negative Integers ===\n\n");
  
  printf("Positive 1:\n");
  printf("Binary: ");
  print_bits32(1);
  
  printf("\nNegative -1:\n");
  printf("Binary: ");
  print_bits32(-1);
  
  printf("\nAnother example:\n");
  printf("Positive 5:\n");
  printf("Binary: ");
  print_bits32(5);
  
  printf("\nNegative -5:\n");
  printf("Binary: ");
  print_bits32(-5);

  return 0;
}
