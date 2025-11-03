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
  printf("=== Exercise 1: Printing Bits ===\n\n");
  
  printf("0xDEADBEEF: ");
  print_bits32(0xDEADBEEF);
  
  printf("255:       ");
  print_bits32(255);
  
  printf("1:         ");
  print_bits32(1);
  
  printf("-1:        ");
  print_bits32(-1);
  
  return 0;
}
