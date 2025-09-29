#include "utest.h"
#include "library.h"
#include <stdlib.h>

UTEST(calculate_sum, basic_tests) {
    int arr[] = {1, 2, 3, 4, 5};
    double sum = calculate_sum(arr, 5);
    ASSERT_EQ(sum, 15.0);
    
    // Test with NULL array
    sum = calculate_sum(NULL, 5);
    ASSERT_EQ(sum, 0.0);
    
    // Test with zero size
    sum = calculate_sum(arr, 0);
    ASSERT_EQ(sum, 0.0);
}

UTEST(calculate_sum, advanced_tests) {
    int arr[] = {-1, -2, 3, 4};
    double sum = calculate_sum(arr, 4);
    ASSERT_EQ(sum, 4.0);
    
    // Single element
    int single[] = {42};
    sum = calculate_sum(single, 1);
    ASSERT_EQ(sum, 42.0);
}

UTEST(calculate_average, basic_tests) {
    int arr[] = {2, 4, 6, 8};
    double avg = calculate_average(arr, 4);
    ASSERT_EQ(avg, 5.0);
    
    avg = calculate_average(NULL, 5);
    ASSERT_EQ(avg, 0.0);
}

UTEST(calculate_average, advanced_tests) {
    int arr[] = {10};
    double avg = calculate_average(arr, 1);
    ASSERT_EQ(avg, 10.0);
    
    int dummy[] = {1, 2, 3};
    avg = calculate_average(dummy, 0);
    ASSERT_EQ(avg, 0.0);
}

UTEST(resize_array, basic_tests) {
    int* arr = malloc(2 * sizeof(int));
    ASSERT_TRUE(arr != NULL);
    arr[0] = 1;
    arr[1] = 2;
    
    int* new_arr = resize_array(arr, 4);
    ASSERT_TRUE(new_arr != NULL);
    ASSERT_EQ(new_arr[0], 1);
    ASSERT_EQ(new_arr[1], 2);
    
    free(new_arr);
}

UTEST(resize_array, advanced_tests) {
    int* new_arr = resize_array(NULL, 5);
    ASSERT_TRUE(new_arr != NULL);
    free(new_arr);
    
    // Test multiple expansions
    int* arr = malloc(sizeof(int));
    ASSERT_TRUE(arr != NULL);
    arr[0] = 42;
    
    arr = resize_array(arr, 8);
    ASSERT_TRUE(arr != NULL);
    ASSERT_EQ(arr[0], 42);
    
    free(arr);
}

UTEST_MAIN();
