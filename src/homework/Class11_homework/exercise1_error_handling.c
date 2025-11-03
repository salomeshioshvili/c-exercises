#include <stdio.h>

typedef enum {
  MACCES, // Permission denied
  MNOMEM, // Out of memory
  MINVAL  // Invalid argument
} ErrorCode;

const char *getErrorMessage(ErrorCode error) {
  switch (error) {
  case MACCES:
    return "Permission denied";
  case MNOMEM:
    return "Out of memory";
  case MINVAL:
    return "Invalid argument";
  default:
    return "Unknown error";
  }
}

int main() {
  printf("=== Exercise 1: Modern Error Handling ===\n\n");

  ErrorCode error1 = MACCES;
  ErrorCode error2 = MNOMEM;
  ErrorCode error3 = MINVAL;

  printf("Error MACCES: %s\n", getErrorMessage(error1));
  printf("Error MNOMEM: %s\n", getErrorMessage(error2));
  printf("Error MINVAL: %s\n", getErrorMessage(error3));

  return 0;
}

/*
 * MILESTONE QUESTIONS:
 *
 * Q1: You do not need to handle invalid error codes in your getErrorMessage
 *     function. Why?
 *
 * A1: Enum = safety lock. You can ONLY pass MACCES, MNOMEM, or MINVAL.
 *     Compiler won't let us pass random numbers or wrong values.
 *
 * Q2: strerror() returns a char* but we don't need to free it. Why?
 *     The pointer is not marked as const, so it seems we could modify the
 *     string, but that would be a bad idea. Why?
 *
 * A2: strerror() gives us the library's shared memory (like a shared notepad).
 *     Don't need to free() because we don't own it. The library owns it.
 *     Don't modify because it's shared by everyone. If you change it,
 *     everyone sees your changes. Next strerror() call overwrites it anyway.
 */