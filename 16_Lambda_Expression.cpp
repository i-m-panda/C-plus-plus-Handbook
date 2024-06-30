#include<iostream>
#include<vector>
#include<algorithm>
// lambda expressions are anonymous functions
// introduced in C++ 11 version
// they are generally used for small functionality, think of compare function argument of builtin sort function

// their major use-case is passing them as an argument where creating a function that won't be used again doesn't make sense
// signature of lambda expression:
// capture list      arrow operator+return type  function body
//     |   parameter list     |                     |
//     |         |            |                     |
//     V         V            V                     V
//    [ ] (            ) -><TYPE> {                              }  

// - capture list: as lambda functions by default can't access variable outside function body, you can pass variables in capture list to provide lambda
// function access to those varibles, you can even pass them by reference to allow lambda functions to modify them
// - parameters: function parameters 
// - arrow operator with return type: is used to define return type of the function but in small functionality, compiler can guess it, so we can opt that out
// - function-body: function logic goes here

// you can also store the lambda function in a variable and then use it as per your needs
int compute(int a, int b, int (*computer)(int, int)) {
  return computer(a, b);
};
int main() {
  int x = 10, y = 50;
  int addition = compute(x, y, [](int a, int b){ return a+b;});
  int multiplication = compute(x, y, [](int a, int b){ return a*b;});
  std::cout << "addition of 10, 50: " << addition << "\n";
  std::cout << "multiplication of 10, 50: " << multiplication << "\n";

  // lambda functions are specially useful for containter helper functions like find_if and for_each, etc.
  std::vector<int> v {10, 45, 2, -5, 6, 24, 1};
  std::cout << "\n";
  std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << ", ";});
  std::cout << "\n";

  auto result = std::find_if(v.begin(), v.end(), [](int x){ return x > 10;});
  std::cout << "\n" << *result << "\n";

  // IMPORTANT: capture list follows these rules if you are trying to capture the variables for your lambda functions
  /*
  +-----------+------------------------------------------+
  | []        | Nothing                                  |
  +-----------+------------------------------------------+
  | [=]       | Everything by value                      |  // you need to use mutable keyword if you want to write expression that modify value, although the original values won't be changed
  +-----------+------------------------------------------+
  | [&]       | Everything by reference                  |
  +-----------+------------------------------------------+
  | [=, &X]   | Everything by value and X by reference   |
  +-----------+------------------------------------------+
  | [&, x]    | Everything by reference and X by value   |
  +------------------------------------------------------+
  |       Static and global variables are always         |
  |       captured                                       |
  +------------------------------------------------------+
  */
  return 0;
}