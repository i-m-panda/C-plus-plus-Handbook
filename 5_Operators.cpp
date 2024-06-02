// ARITHMETIC OPERATORS
// Binary operators (takes to 2 operands for performing operations)

// +(addition)[works for integer as well as floating point types]
// -(subtraction)[works for integer as well as floating point types]
// *(multiplication)[works for integer as well as floating point types]
// %(remainder)[works for integer types only | sign of the result depends upon sign of first operand | division by 0 gives undefined result]
// /(division)[works for integer as well as floating point types | division by 0 gives undefined result,
// when used with floating point number you may get infinite or -infinite]

// Unary operator(takes 1 operand for performing operations)
// Postfix, prefix
// --, ++
// int x = 10; int y = x++; // y = x happens first then x = x + 1
// int x = 10; int y = ++x; // x = x + 1 happens first then y = x

// ASSIGNMENT OPERATORS
// simple
// = 
// compound: x += 2 // x = x + 2 // this pattern is followed in case of compound assignment operator
// +=, -=, +=, /=, %=, &=, |=, <<=, >>=, ^=

// COMPARISION OPERATORS
// <, >, ==, <=, >=, !=, 
// <=>(added in C++ 20)
/* 
(A <=> B) < 0 is true if A < B
(A <=> B) > 0 is true if A > B
(A <=> B) == 0 is true if A and B are equal/equivalent.
*/

// LOGICAL OPERATORS
// Binary operators
// &&, and (true && true only returns true)
// ||, or (true || false, false || true returns true)
// Unary operators
// !, not (return the opposite of operand, true becomes false, false becomes true)

// short-circuiting in logical operators
// happens in &&, ||
// bool res = (5 > 10) && (x++); // x++ is not evaluated as first condition is false so there is no need to evaluate 2nd condition
// bool res = (10 > 5) || (x++); // x++ is not evaluated as first condition is true so there is no need to evaluate 2nd condition

// BITWISE OPERATORS
// works on integer operands, operands binary representation is used, bits are compareds to check the resultant binary number
// then it's integer representation is used as the answer

// Binary operators
// Bitwise AND (&)
// corresponding resultant bit is set true(1) only if both of the correspoding bits of operands are set true(1)

// Bitwise OR (|)
// corresponding resultant bit is set true(1) if any one of the correspoding bits of operands is set true(1)

// Bitwise XOR (^)
// corresponding resultant bit is set true(1) if any of the correspoding bits of operands differ from from eachother
 
// Left Shift (<<)
// shifts the bits of first operand to the left by the number of bits mentioned as 2nd operand
// x << y is equivalent to x * 2^y(mathematically)

// Right Shift (>>)
// shifts the bits of first operand to the right by the number of bits mentioned as 2nd operand
// x >> y is equivalent to floor(x / 2^y)(mathematically)

// Unary operator
// Bitwise NOT (~)
// inverts the bits of the binary representation of the operand
// it's not recommended to use this operator on signed numbers as different compiler may use different ways to store -ve numbers

// Operator Precedence Table in C++
// you can use brackets to increase precedence
/*

| Operator                          | Name                                    | Associativity |
|-----------------------------------|-----------------------------------------|---------------|
| () [] ->                          | Function call, Subscript, Member access | Left          |
| ++ --                             | Increment/Decrement                     | Right         |
| ! ~ - +                           | Logical/Bitwise NOT, Unary plus/minus   | Right         |
| * / %                             | Multiplication, Division, Modulus       | Left          |
| + -                               | Addition, Subtraction                   | Left          |
| << >>                             | Bitwise shift                           | Left          |
| < <= > >=                         | Relational operators                    | Left          |
| == !=                             | Equality operators                      | Left          |
| &                                 | Bitwise AND                             | Left          |
| ^                                 | Bitwise XOR                             | Left          |
| |                                 | Bitwise OR                              | Left          |
| &&                                | Logical AND                             | Left          |
| ||                                | Logical OR                              | Left          |
| ?:                                | Ternary conditional                     | Right         |
| = += -= *= /= %= &= ^= |= <<= >>= | Assignment and compound assignment      | Right         |
| ,                                 | Comma                                   | Left          |

*/
