#include <stdio.h>

int main() {
  int arr[10] = {0};
  // arr contains 10 integers initialized to 0
  arr[7] = 5;
  // &arr[0] is the address of the first element of arr
  printf("*(&arr[0] + 7) : %d\n", *(&arr[0] + 7));
  // This is equivalent to arr[7]
  printf("arr[7] : %d\n", arr[7]);
  // In C, arrays decay to pointers automatically
  printf("*(arr+7) : %d\n", *(arr + 7));
  return 0;
}
