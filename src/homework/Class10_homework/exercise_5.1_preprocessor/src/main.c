#include <stdio.h>
#include "welcome.h"

int main() {
    const char* msg = get_welcome_msg();
    printf("%s\n", msg);
    return 0;
}