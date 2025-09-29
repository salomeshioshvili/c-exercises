#include <stdio.h>
#include "rectangle.h"

int main() {
    Rectangle rect = {10, 20};
    
    printf("Rectangle: width=%d, height=%d\n", rect.width, rect.height);
    printf("Area: %d\n", area(rect));
    
    grow(&rect, 5, 3);
    printf("After growing by (5, 3): width=%d, height=%d\n", rect.width, rect.height);
    printf("New area: %d\n", area(rect));
    
    return 0;
}
