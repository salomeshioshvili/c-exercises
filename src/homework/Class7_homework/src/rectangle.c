#include "rectangle.h"

int area(Rectangle r) {
    if (r.width <= 0 || r.height <= 0) {
        return 0;
    }
    return r.width * r.height;
}

void grow(Rectangle *r, int dw, int dh) {
    if (r == 0) {
        return;
    }
    
    int new_width = r->width + dw;
    int new_height = r->height + dh;
    
    if (new_width > 0) {
        r->width = new_width;
    } else {
        r->width = 0;
    }
    
    if (new_height > 0) {
        r->height = new_height;
    } else {
        r->height = 0;
    }
}
