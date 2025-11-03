#include "welcome.h"

// Define macros for both languages
#define HELLO_EN "Hello, World!"
#define HELLO_ES "Hola, Mundo!"

// Define language identifiers as numbers
#define EN 1
#define ES 2

// Check if LANGUAGE is NOT defined, if so, set a default
#ifndef LANGUAGE
#define LANGUAGE EN
#endif

// Function implementation
const char* get_welcome_msg() {
    #if LANGUAGE == EN
        return HELLO_EN;
    #elif LANGUAGE == ES
        return HELLO_ES;
    #else
        #error "LANGUAGE must be defined as EN or ES"
    #endif
}