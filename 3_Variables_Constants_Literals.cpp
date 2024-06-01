// GLOBAL VARIABLE VS LOCAL VARIABLE 
// non-initialised local variable gets default value as garbage value until you intialise it
// non-initialised global variable gets default value as 0 or equivalent of 0 according the variable's datatype

// if you want to access global variable before it's intialisation, you can use extern keyword
// which does the external linkage, for example:

#include<iostream>
#include<typeinfo> // because we are using typeid()
using namespace std;

extern int i;
void extern_usecase() {
  std::cout << i << std::endl;
}
int i = 100;

// variable's scope precedence is from innermost -> outermost

// within same scope you can't have more than one variable with same name

// STATIC VARIABLES: local variables created once and can be accessed during the lifetime of a program
// they have internal linkage, also they get the default value as 0 or equivalent of 0 according the variable's datatype

// STATIC DATA MEMBERS: are shared across all the objects of the class

// STATIC METHOD: can only access static data member of the class

void test() {
  static int x;
  cout << x << endl;
}

// CONSTANTS: you can't modify the constant once you assign them value, technically you can use pointer to modify that value 
// but it's bad practice
// its alternative can be preprocessor directive like below but there is no type checking for such values,
// also there is no scope or other properties that you get from variables

// using const
const double PI = 3.1452;

// using directive
#define C 299792458;

// AUTO keyword: is used to automatically determine the datatype(default datatype is used)
// of variable based on the literal, it's can be used because:
// - if a function return type is auto, it can return different type without changing the definition
// - implicit conversion doesn't happen
// - can be useful for lengthy data type especially non-primitive datatypes
// - used with lambda functions
// one disadvantage is reduced readibility of the program if auto is being overused

// you can use typeid to determine the type of variable, look for main() function for it's usage

// LITERALS in C++
// INTEGER LITERALS:
// PREFIXES:
/*
  Prefix    | Type         | Literal
  ---------------------------------
  No prefix | Decimal      | 2
  0x        | Hexadecimal  | 0x1A
  0         | Octal        | 016
  0b        | Binary       | 0b11
*/
// SUFFIXES:
/*
  Suffix | Type    | Literal
  ---------------------------------
  u   | Unsigned   | 124u
  L   | Long       | 12314513L
  LL  | Long Long  | 1242454764674LL
*/
// FLOATING POINT LITERALS:
// PREFIXES:
/*
  Prefix | Type                   | Literal
  -------------------------------------------------------------------
  0x | Hexadecimal floating point | 0x1A.1p2 // 26.0625*2^2 = 104.25
*/
// SUFFIXES:
/*
  Suffix   | Type        | Literal
  ---------------------------------
  No suffix| double      | 1.234
  f        | float       | 1.234f
  l        | long double | 1.23434756l
*/
// CHARACTER & STRING LITERALS:
// PREFIXES:
/*
  Prefix    | Type    | Literal
  --------------------------------
  No Prefix | ASCII   | 'e'
  u8        | UTF-8   | u8'e'
  u         | UTF-16  | u'e'
  U         | UTF-32  | U'e'
  L         | wchar_t | L'e'

  char a = 'b';
  char *s = "abc";
  string s1 = "courses";
*/

// TYPE CONVERSION/CASTING
// Implict

// most primitive datatypes can be converted implicitly, there maybe loss of information in such conversion
// casting presedence: bool -> char -> short int -> int -> unsigned int -> long -> unsigned long -> long long ->
// unsigned long long -> float -> double -> long double (used when you have 2 0r more types in an expression)

// Explicit
// consider the code below to understand the problem
void divide() {
  int x = 5, y = 2;
  double divison = x/y;
  cout << "5/2: " << divison << endl;
}
// division in above program would be 2 instead of 2.5 even if you are storing the result in double
// division happens before assignment, division result in integer as operands are integer, therefore we need
// to explicitly type one of the operand to double to get the result of operation as double
// there are 2 ways to do it: 
// 1. C style explict conversion: double divison = double(x)/y;
// 2. C++ style explict conversion: double divison = static_cast<double>(x)/y; // advantage of static cast is 
// that it does validaty check before conversion which doesn't happen in C style conversion


int main() {
  divide();
  extern_usecase();
  test();
  auto b = 20;
  auto c = 34.5;
  cout << PI << ", " << C;
  cout << "\nb is of type " << typeid(b).name() << ", c is of type " << typeid(c).name() << endl;
  return 0;
}