// Primitive Types
// INTEGER TYPES: 
// short[2 byte], unsigned short[2 byte], int[4 byte], unsigned int[4 byte],
// long[4 byte], unsigned long[4 byte], long long [8 byte], unsigned long long[8 byte]

// CHAR TYPES: 
// char[1 byte], unsigned char[1 byte], w_char_t(wide character and supports unicode), 
// char8_t(supports unicode 8), char16_t(supports unicode 16), char32_t(supports unicode 32)

// FLOATING TYPES:
// float[4 byte](may not store the exact number representation), double[8 byte], long double

// OTHER TYPES:
// bool[1 byte], void

// Non-primitive Types
// arrays, pointer, vector, string, class, struct, etc.

/*
Data Type               | Size (in bytes)  | Range
------------------------|------------------|-------------------------------------------
short int               | 2                | -32,768 to 32,767
unsigned short int      | 2                | 0 to 65,535
unsigned int            | 4                | 0 to 4,294,967,295
int                     | 4                | -2,147,483,648 to 2,147,483,647
long int                | 4                | -2,147,483,648 to 2,147,483,647
unsigned long int       | 4                | 0 to 4,294,967,295
long long int           | 8                | -(2^63) to (2^63)-1
unsigned long long int  | 8                | 0 to 18,446,744,073,709,551,615
signed char             | 1                | -128 to 127
unsigned char           | 1                | 0 to 255
float                   | 4                | -3.4×10^38 to 3.4×10^38
double                  | 8                | -1.7×10^308 to1.7×10^308
long double             | 12               | -1.1×10^4932 to1.1×10^4932
wchar_t                 | 2 or 4           | 1 wide character
*/

#include<iostream>

int main() {
  int a1 = -11;
  unsigned int a2 = 2;
  short b1 = -1;
  unsigned short b2 = 123;
  long c1 = -120912412L;
  unsigned long c2 = 123786126322L;
  long long c3 = -1231728475471LL;
  unsigned long long c4 = 7812538135LL;

  char d1 = 'b';
  unsigned char d2 = 'x';
  wchar_t arrow = L'←';
  char16_t star = u'✩';
  char32_t victory = U'✌';

  float e1 = 1.2f;
  double e2 = 2.45678;
  long double e3 = 43.9238428764L;
  long double e4 = 1.1426e-3;

  bool yes = true;
  std::cout << a1 << ", " << a2 << ", " << b1 << ", " << b2 << ", " << c1 << ", " << c2 << ", " << c3 << ", " << c4 << ", ";
  std::cout << d1 << ", " << d2 << ", " << arrow << ", " << star << ", " << victory << ", " << e1 << ", " << e2 << ", " << e3 << ", " << e4 << ", " << yes;
  return 0;
}

// sizeof() is an operator in C++ that return the size of a datatype(compiler dependent, can also be used with variables and literals)
// in bytes. It's evaluated at compile time

// if you use smaller datatype to store big value, you'll get overflow error
