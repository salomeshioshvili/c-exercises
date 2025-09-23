#include<stdio.h>


int main(){
  // A pointer arithmetics example
  int arr[5] = {0,1,2,3,4};
  int *p = &arr[0]; // Equivalent to int *p = arr;
  // p is a pointer to the first element of arr
  printf("*p : %d\n", *p);

  int *second_element = p + 1;
  // p + 1 points to the second element of arr
  printf("*second_element : %d\n", *second_element);

  // We can explore the surrounding elements using pointer arithmetic
  for(int i=0; i<5; i++){
    printf("*(p + %d) : %d\n", i, *(p + i));
  }

  // What lies before the first element?
  // Undefined behavior, but often shows some garbage value
  // for(int i=0; i<100; i++){
  //   printf("*(p - %d) : %d\n", i, *(p - i));
  // }

  // Accessing an arbitrary address can lead to a segfault
  // int *some_address = (int *)0xDEADBEEF;
  // printf("Trying to access address 0xDEADBEEF\n");
  // printf("*((int *)0xDEADBEEF) : %d\n", *some_address);
  return 0;

}
