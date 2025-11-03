#include <stdio.h>

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

int main() {
  printf("=== Exercise 2: Custom Logging System ===\n\n");

  printf("Testing console logger:\n");
  performTask(consoleLogger);

  printf("\nTesting file logger (check log.txt):\n");
  performTask(fileLogger);
  printf("Messages written to log.txt\n");

  return 0;
}
