#include <stdio.h>
#include <string.h>
#include <time.h>

// EXERCISE 1: Improving the stdlib

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


// EXERCISE 2: Custom Logging

typedef enum { DEBUG, INFO, WARNING, ERROR } LogLevel;

typedef void (*Logger)(const char *message, LogLevel level);

const char *getLogLevelString(LogLevel level) {
  switch (level) {
  case DEBUG:
    return "DEBUG";
  case INFO:
    return "INFO";
  case WARNING:
    return "WARNING";
  case ERROR:
    return "ERROR";
  default:
    return "UNKNOWN";
  }
}

void consoleLogger(const char *message, LogLevel level) {
  printf("[%s] %s\n", getLogLevelString(level), message);
}

void fileLogger(const char *message, LogLevel level) {
  FILE *file = fopen("log.txt", "a");
  if (file == NULL) {
    fprintf(stderr, "Error: Could not open log.txt for writing\n");
    return;
  }

  fprintf(file, "[%s] %s\n", getLogLevelString(level), message);
  fclose(file);
}

void performTask(Logger logger) {
  logger("Task started", INFO);
  logger("Initializing resources", DEBUG);
  logger("Processing data", INFO);
  logger("Low memory warning", WARNING);
  logger("Validating results", DEBUG);
  logger("Task completed successfully", INFO);
}

// ADVANCED MILESTONE: Colored Timestamped Console Logger


void coloredTimestampedConsoleLogger(const char *message, LogLevel level) {
  // Get current time
  time_t now = time(NULL);
  struct tm *timeinfo = localtime(&now);

  // Format timestamp
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

  // Select color based on log level
  const char *color;
  const char *levelStr = getLogLevelString(level);

  switch (level) {
  case DEBUG:
    color = "\033[37m"; // White
    break;
  case INFO:
    color = "\033[34m"; // Blue
    break;
  case WARNING:
    color = "\033[33m"; // Yellow
    break;
  case ERROR:
    color = "\033[31m"; // Red
    break;
  default:
    color = "\033[0m"; // Reset
    break;
  }

  printf("[%s] %s[%s]\033[0m %s\n", timestamp, color, levelStr, message);
}

// MAIN FUNCTION

int main() {
  // Test Exercise 1 - Error Handling
  printf("--- Exercise 1: Modern Error Handling ---\n");
  ErrorCode error1 = MACCES;
  ErrorCode error2 = MNOMEM;
  ErrorCode error3 = MINVAL;

  printf("Error MACCES: %s\n", getErrorMessage(error1));
  printf("Error MNOMEM: %s\n", getErrorMessage(error2));
  printf("Error MINVAL: %s\n", getErrorMessage(error3));

  printf("\n");

  // Test Exercise 2 - Custom Logging
  printf("--- Exercise 2: Custom Logging ---\n");
  printf("\nTesting console logger:\n");
  performTask(consoleLogger);

  printf("\nTesting file logger (check log.txt):\n");
  performTask(fileLogger);
  printf("Messages written to log.txt\n");

  printf("\n");

  // Colored Timestamped Logger
  printf("--- Advanced: Colored Timestamped Logger ---\n");
  performTask(coloredTimestampedConsoleLogger);

  printf("\n");
  printf("Additional demonstration of colored logger:\n");
  coloredTimestampedConsoleLogger("System initialization complete", DEBUG);
  coloredTimestampedConsoleLogger("User logged in successfully", INFO);
  coloredTimestampedConsoleLogger("Disk space running low", WARNING);
  coloredTimestampedConsoleLogger("Failed to connect to database", ERROR);

  return 0;
}

/*
 * COMPILATION:
 * gcc -Wall -Wextra -std=c11 Class11_homework.c -o Class11_homework
 *
 * EXECUTION:
 * ./Class11_homework
 */
