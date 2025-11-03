#include <stdio.h>

typedef struct {
  int a;     // offset 0
  double b;  // offset 8 (double needs alignment)
  char c;    // offset 16
} repro_t;

typedef struct {
  char *name;
  int offset;
} netField_t;

#define NETF(x) #x, (int)&(((repro_t*)0)->x)

netField_t reproFields[] = {
  {NETF(a)},
  {NETF(b)},
  {NETF(c)},
};

int main(void) {
  printf("\n--- How It Works ---\n\n");
  
  printf("Step 1: Start with NULL pointer cast to struct\n");
  printf("  (repro_t*)0  →  A fake pointer at address 0\n\n");
  
  printf("Step 2: Access field through fake pointer\n");
  printf("  ((repro_t*)0)->a  →  Access member 'a'\n");
  printf("  ((repro_t*)0)->b  →  Access member 'b'\n");
  printf("  ((repro_t*)0)->c  →  Access member 'c'\n\n");
  
  printf("Step 3: Get the address of each field\n");
  printf("  &(((repro_t*)0)->a)  →  Address where 'a' would be (0 + 0 = 0)\n");
  printf("  &(((repro_t*)0)->b)  →  Address where 'b' would be (0 + 8 = 8)\n");
  printf("  &(((repro_t*)0)->c)  →  Address where 'c' would be (0 + 16 = 16)\n\n");
  
  printf("Step 4: Cast address to int (= byte offset!)\n");
  printf("  (int)&(...)  →  This IS the offset!\n\n");
  
  printf("Step 5: Use stringizing operator # for field names\n");
  printf("  #a becomes \"a\"\n");
  printf("  #b becomes \"b\"\n");
  printf("  #c becomes \"c\"\n\n");
  
  printf("Why Is it Clever:\n\n");
  printf("Field names and offsets computed at COMPILE TIME\n");
  printf("NO runtime overhead (all during compilation)\n");
  printf("Never actually dereferences NULL\n");
  printf("Works with any struct automatically\n");
  
  return 0;
}
