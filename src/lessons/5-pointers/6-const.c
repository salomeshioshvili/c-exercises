#include<stdio.h>
#include<assert.h>

int main() {
  // A const variable cannot be modified after its initialization
  const int x = 10;
  // x = 20; // This will cause a compilation error


  // A pointer to a const variable cannot be used to modify the variable
  const int *p1 = &x; // Pointer to a const int
  // *p1 = 20; // This will cause a compilation error


  // A pointer can itself be const, but the value it points to can be modified
  int arr[5] = {1, 2, 3, 4, 5};
  int* const p2 = arr; // Const pointer to int
  p2[0] = 10; // This is allowed
  //p2 = arr+1; // This will cause a compilation error


  // A const pointer to a const variable
  const int* const p3 = &x; // Const pointer to a const int
  // *p3 = 20; // This will cause a compilation error
  // p3 = &arr[0]; // This will cause a compilation error


  int a = 1;
  int b = 2;
  printf("Address of a: %p\n", (void*)&a);
  printf("Address of b: %p\n", (void*)&b);
  printf("Distance between a and b: %ld bytes\n", (char*)&b - (char*)&a);

  return 0;
}
