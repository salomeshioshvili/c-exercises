#include "name_length.h"
#include <stddef.h>

int name_length(const char* name) {
    if (name == NULL) {
        return 0;
    }
    
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] != ' ') {
            count++;
        }
    }
    return count;
}