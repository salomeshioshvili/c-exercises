# Welcome Message Project

A C project demonstrating preprocessor features: macros, conditional compilation, and build systems.

## Description

This project prints a welcome message in different languages (English and Spanish). The language is selected at **compile time** using preprocessor directives.

## Project Structure

```
exercise_5.1_preprocessor/
├── include/
│   └── welcome.h          # Function declarations
├── src/
│   ├── welcome.c          # Welcome message logic
│   └── main.c             # Main program
├── test/
│   ├── utest.h            # Unit testing framework
│   └── test_welcome.c     # Unit tests
├── CMakeLists.txt         # Build configuration
├── .gitignore             # Git ignore rules
├── README.md              # This file
└── environment.yml        # Conda environment
```

## Prerequisites

- CMake (>= 3.10)
- C compiler (gcc or clang)
- Make

## Setup

1. Create and activate the Conda environment:
```bash
conda env create -f environment.yml
conda activate c_preprocessor
```

## Building with CMake (Recommended)

**Build in English:**
```bash
cmake -DLANGUAGE=EN -B build
cmake --build build
./build/main
```

**Build in Spanish:**
```bash
cmake -DLANGUAGE=ES -B build
cmake --build build
./build/main
```

## Building with Command Line

**English:**
```bash
cc -Iinclude -DLANGUAGE=EN src/welcome.c src/main.c -o welcome
./welcome
```

**Spanish:**
```bash
cc -Iinclude -DLANGUAGE=ES src/welcome.c src/main.c -o welcome
./welcome
```

## Running Unit Tests

The project includes unit tests using the `utest` framework.

**Run tests with English:**
```bash
cmake -DLANGUAGE=EN -B build
cmake --build build
./build/test_welcome
```

**Run tests with Spanish:**
```bash
cmake -DLANGUAGE=ES -B build
cmake --build build
./build/test_welcome
```

**Use CTest for detailed output:**
```bash
cmake -DLANGUAGE=EN -B build
cmake --build build
cd build
ctest --verbose
```

**Expected test output:**
```
[==========] Running 5 tests from 1 test case.
[ RUN      ] Welcome.ReturnsNonNull
[       OK ] Welcome.ReturnsNonNull
[ RUN      ] Welcome.MessageNotEmpty
[       OK ] Welcome.MessageNotEmpty
[ RUN      ] Welcome.MessageContainsText
[       OK ] Welcome.MessageContainsText
[ RUN      ] Welcome.EnglishMessage
[       OK ] Welcome.EnglishMessage
[ RUN      ] Welcome.ConsistentMessage
[       OK ] Welcome.ConsistentMessage
[==========] 5 tests from 1 test case ran.
[  PASSED  ] 5 tests.
```

### Test Coverage

The unit tests verify:
- Function returns a valid (non-NULL) pointer
- Message is not empty
- Message contains expected language-specific content
- Language-specific tests (English: "Hello, World!" / Spanish: "Hola, Mundo!")
- Consistent output across multiple calls

## What I Learned

- **Preprocessor directives**: `#if`, `#ifndef`, `#elif`, `#else`, `#endif`
- **Macros**: Text substitution that happens before compilation
- **Conditional compilation**: Including/excluding code at compile time based on preprocessor conditions
- **Compile-time configuration**: Using `-D` flags to control program behavior
- **Unit testing**: Writing tests that adapt to compile-time configurations
- **Build systems**: Using CMake to manage compilation and testing

## Key Concepts

1. **Preprocessing happens before compilation**: The preprocessor modifies the source code before the compiler sees it
2. **Macros are text substitution**: They're not variables or functions; they're literally text replaced in the code
3. **Conditional compilation**: Only one branch of `#if/#elif/#else` makes it into the final executable
4. **Separation of concerns**: Headers declare interfaces, source files implement them
5. **Include guards**: `#pragma once` prevents multiple inclusions of the same header
6. **Testing with preprocessor**: Tests can use conditional compilation to verify different build configurations

## Supported Languages

- `EN` - English ("Hello, World!")
- `ES` - Spanish ("Hola, Mundo!")

## Troubleshooting

**If build fails:**
```bash
# Clean build directory and retry
rm -rf build
cmake -DLANGUAGE=EN -B build
cmake --build build
```

**If tests fail:**
- Verify that `LANGUAGE` is defined correctly in CMakeLists.txt
- Check that `utest.h` exists in the `test/` directory
- Ensure the welcome library is correctly linked to the test executable

**To see preprocessor output:**
```bash
# View what the preprocessor does
cc -E -DLANGUAGE=EN -Iinclude src/welcome.c
```

## Author

- Name: Salome Shioshvili
- Contact: sshioshvili.ieu2024@student.ie.edu
