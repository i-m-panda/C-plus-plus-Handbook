// FUINCTION: sub routine that do something, and can be called multiple times to perform a job
// Function syntax in c++
/*
RETURN_TYPE FUNCTION_NAME(PARAM_1, PARAM_2, ... PARAM_N) {
  FUNCTION_BODY
}
*/

// Function execution process uses function call stack(LIFO) to maintain the order and data of functions execution

// FUNCTION DECLARATION AND DEFINITION
// 2 ways to use function:
// define -> use
// declare -> use -> define

// declaration example
// int sum(int a, int b); or int sum(int, int);

// definition example
/*
int sum(int a, int b) {
  return a+b;
}
*/
// you can provide default arguments for functions either in function definition or declaration also all default
// args should appear at the end in order of parameters
// int sum(int a, int b, int c = 0) // declaration
// definition
/*
int sum(int a, int b, int c = 0) {
  return a+b+c;
}
*/

// INLINE FUNCTIONS
// - inline function reduces the function call overhead
// - when the inline function is called whole code of the inline function gets 
// inserted or substituted at the point of the inline function call
// - it's useful if the function itself is small
// - substitution is performed at compile time
// - declaring function as inline is just a suggestion to compiler
// - mordern compiler may implicitly make some functions inline
// - too much use of inline may increase the binary size file
// - when we define a method inside a class, it's automatically treated as inline suggestion to the compiler

// FUNCTION OVERLOADING
// - same name functions with different kind of inputs(either type or number of parameters),
// compiler calls the correct function based on arguments provided
// - if you have same function body for all the functions, then instead using function overloading use templates
// - can't overload a function by differing return type
// - when using function overloading, be careful with the usage of default parameters as they may result in ambiguous call issue
#include<iostream>

void printNum(int n = 0) {
  std::cout << n << "\n";
}

void printNum() {
  std::cout << 3 << "\n";
}

int main() {
  // printNum(); this will result in error as compiler can't decide which function has to be called
  return 0;
}
