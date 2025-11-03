#include <stdio.h>
#include <time.h>

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

void coloredTimestampedConsoleLogger(const char *message, LogLevel level) {
  // Current time
  time_t now = time(NULL);
  struct tm *timeinfo = localtime(&now);

  // Format timestamp
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

  // Color based on log level
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

void performTask(Logger logger) {
  logger("Task started", INFO);
  logger("Initializing resources", DEBUG);
  logger("Processing data", INFO);
  logger("Low memory warning", WARNING);
  logger("Validating results", DEBUG);
  logger("Task completed successfully", INFO);
}

int main() {
  printf("=== Exercise 3: Colored Timestamped Logger ===\n\n");

  printf("Demonstrating performTask with colored logger:\n");
  performTask(coloredTimestampedConsoleLogger);

  printf("\nAdditional demonstration of different log levels:\n");
  coloredTimestampedConsoleLogger("System initialization complete", DEBUG);
  coloredTimestampedConsoleLogger("User logged in successfully", INFO);
  coloredTimestampedConsoleLogger("Disk space running low", WARNING);
  coloredTimestampedConsoleLogger("Failed to connect to database", ERROR);

  return 0;
}
