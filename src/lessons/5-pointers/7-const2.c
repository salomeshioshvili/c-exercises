#include<stdio.h>
#include<assert.h>

double sum_data(const double *data, size_t size) {
  assert(data);
  double sum = 0;
  for(size_t i = 0; i < size; i++) {
    sum += data[i];
  }
  //data[0] = 100.0; // This will cause a compilation error
  return sum;
}

int main() {
  double data[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  size_t size = sizeof(data) / sizeof(data[0]);
  double result = sum_data(data, size);
  printf("Sum: %f\n", result);
  return 0;
}
