// C++ was first standardised in 1998 C++98
// standards: C++03, C++11, C++14, C++17, C++20, C++23 is being worked upon

// standard document specify the rules of the language
// software that checks these rules are compilers and interpreters

// GCC is most popular compiler of C++, sometimes compilers doesn't have the latest implementation of a language standard
// compilers also provide tools like setting the sign bits, etc.

// C++ is statically typed language(meaning, type has to be defined for a variable)

// C++ uses header files(that stores declaration, variables, functions, classes, constants, etc.)
// # is a preprocessor directive, first step of compilation is preprocessing, the preprocessor generates the code
// from your code along with the declarations mentioned in the included header file
#include<iostream>

// In C++ you can use namespace to divide code into different logical groups, for example std contains standard lib functions
// and types, it also helps in avoiding name collision
using namespace std;

// program execution start at main(), return type of main function should be int
int main() {
  std::cout<< "Whats up";
  return 0;
}

// C++ code compilation process:
// Source code -> |Compiler| -> Object code + Object code <- |Linker| <- Libraries
//                                          |
//                                          |
//                                          V
//                                     Executable code

// compiler, linker, object code, executable code is machine specific(not platform independent)

/* MULTI LINE COMMENT */
// SINGLE LINE COMMENT

// Variable naming convention is same as other popular languages
