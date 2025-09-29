#include <stdio.h>

void root_privileged_print(const char* message, long user) {
    if (user == 0xbada55) {
        printf("Root says: %s\n", message);
    } else if (user == 0xdeadbeef) {
        printf("Users do not have access to this function\n");
    }
}

void injection() {
    // shooting blindly
    long hack = 0xbada55;
    long* ptr = &hack;
    
    *(ptr + 1) = 0xbada55; 
    *(ptr - 1) = 0xbada55;  
    *(ptr + 2) = 0xbada55;
    *(ptr - 2) = 0xbada55;
    *(ptr + 3) = 0xbada55;
    *(ptr - 3) = 0xbada55;
}

int main() {
    volatile long user = 0xdeadbeef;
    injection();
    root_privileged_print("ALL YOUR BASE ARE BELONG TO US", user);
    return 0;
}
