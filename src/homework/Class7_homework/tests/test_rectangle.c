#include "utest.h"
#include "rectangle.h"

UTEST(rectangle, area_basic) {
    Rectangle rect = {10, 20};
    ASSERT_EQ(200, area(rect));
}

UTEST(rectangle, area_zero_width) {
    Rectangle rect = {0, 20};
    ASSERT_EQ(0, area(rect));
}

UTEST(rectangle, area_zero_height) {
    Rectangle rect = {10, 0};
    ASSERT_EQ(0, area(rect));
}

UTEST(rectangle, area_negative_width) {
    Rectangle rect = {-5, 20};
    ASSERT_EQ(0, area(rect));
}

UTEST(rectangle, area_negative_height) {
    Rectangle rect = {10, -5};
    ASSERT_EQ(0, area(rect));
}

UTEST(rectangle, grow_basic) {
    Rectangle rect = {10, 20};
    grow(&rect, 5, 3);
    ASSERT_EQ(15, rect.width);
    ASSERT_EQ(23, rect.height);
}

UTEST(rectangle, grow_negative_delta) {
    Rectangle rect = {10, 20};
    grow(&rect, -3, -5);
    ASSERT_EQ(7, rect.width);
    ASSERT_EQ(15, rect.height);
}

UTEST(rectangle, grow_too_negative_delta) {
    Rectangle rect = {5, 8};
    grow(&rect, -10, -15);
    ASSERT_EQ(0, rect.width);
    ASSERT_EQ(0, rect.height);
}

UTEST(rectangle, grow_null_pointer) {
    // This test ensures the function doesn't crash with NULL pointer
    grow(NULL, 5, 3);
    // If we reach here, the function handled NULL gracefully
    ASSERT_TRUE(1);
}

UTEST_MAIN();
