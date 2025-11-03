#include <stdio.h>
#include <math.h>

// The original function from Quake III
float Q_rsqrt(float number) {
  long i;
  float x2, y;
  const float threehalfs = 1.5F;
  
  x2 = number * 0.5F;
  y = number;
  
  // Step 1-2: Reinterpret float bits as long integer
  i = *(long *)&y;
  
  // Step 3: Apply the magic number (bit manipulation approximation)
  i = 0x5f3759df - (i >> 1);
  
  // Step 4: Reinterpret back to float
  y = *(float *)&i;
  
  // Step 5: Newton's method refinement (1st iteration)
  y = y * (threehalfs - (x2 * y * y));
  
  // Optional: 2nd iteration for higher accuracy (commented out like original)
  // y = y * (threehalfs - (x2 * y * y));
  
  return y;
}

int main(void) {
  printf("=== Exercise 3: Fast Inverse Square Root ===\n\n");
  
  float numbers[] = {1.0f, 4.0f, 9.0f, 16.0f, 100.0f};
  
  printf("Comparing Q_rsqrt (fast hack) with standard library:\n");
  printf("%-10s | %-15s | %-15s | %-10s\n", "x", "1/sqrt(x) (std)", "Q_rsqrt", "Error");
  printf("-----------|-----------------|-----------------|----------\n");
  
  for (int i = 0; i < 5; i++) {
    float x = numbers[i];
    float accurate = 1.0f / sqrtf(x);
    float fast = Q_rsqrt(x);
    float error = fabs(accurate - fast) / accurate * 100.0f;
    
    printf("%-10.1f | %-15.6f | %-15.6f | %.2f%%\n", x, accurate, fast, error);
  }
  
  printf("\nHow it works:\n");
  printf("1. Reinterpret float as integer to get approximation of log2(x)\n");
  printf("2. Magic number 0x5f3759df performs mathematical operations in bit space\n");
  printf("3. Reinterpret back as float (rough guess for 1/sqrt(x))\n");
  printf("4. One Newton iteration: y = y * (1.5 - 0.5*x*y*y) refines the result\n");
  printf("\nWhy it's fast: Integer operations are much faster than sqrt()!\n");
  
  return 0;
}
