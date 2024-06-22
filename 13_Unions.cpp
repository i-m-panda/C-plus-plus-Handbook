#include<iostream>

int main() {
  // Syntactically a union is similar to struct or a class
  // They are declared/defined in same way, they can be passed to functions in same way, they are accessed in same way

  // They differ from struct in respect to how they are internally represented and stored
  // Unions use single memory to store data members
  // Meaning if a struct has 3 int then it will be allocated atleast 3 * size of int but if a union has same members then it will be allocated
  // 1 * size of int and it's going to store the member in the same memory
  // if union has different data type members then it's going to allocate the memory according to the largest data type member

  union U1 {
    int i1;
    int i2;
    int i3;
  };

  union U2 {
    char c;
    int i;
    double d;
  }; // U2 will use 8 byte of memory(double data type, as it's the biggest data type in U2)
  
  std::cout << "sizeof of u1: " << sizeof(U1) << "\n"; // for 64 bit architecture with gcc compiler you will get 4 as output
  std::cout << "sizeof of u2: " << sizeof(U2) << "\n\n"; // for 64 bit architecture with gcc compiler you will get 8 as output

  // in union data member refer to the same location
  U1 u1;

  u1.i1 = 20; // i1, i2, i3 becomes 20 as they refer to same memory location
  std::cout << "u1.i1: " << u1.i1 << ", u1.i2: "<< u1.i2 << ", u1.i3: "<< u1.i3 << "\n";

  u1.i3 = 40; // i1, i2, i3 becomes 20 as they refer to same memory location
  std::cout << "u1.i1: " << u1.i1 << ", u1.i2: "<< u1.i2 << ", u1.i3: "<< u1.i3 << "\n\n";

  // APPLICATIONS OF UNIONS
  // TYPE PUNNING: Technique used to see internal representation of one data type into another data type, without any explicit type casting
  union IntFloat {
    int i;
    float j;
  };
  
  IntFloat int_float;
  int_float.j = 2.3f;

  std::cout << "int_float.i: " << int_float.i << ", which is how 2.3f is represented in integer internally(integer value equivalent to binary representation)" << "\n";

  union IntCharArr {
    int i;
    char binary[4];
  };

  IntCharArr int_char_arr;
  int_char_arr.i = 512;
  
  // binary[0] = 0 in byte or 0000 in 4 bits
  // binary[1] = 2 in byte or 0010 in 4 bits
  // binary[2] = 0 in byte or 0000 in 4 bits
  // binary[3] = 0 in byte or 0000 in 4 bits
  std::cout << "int_char_arr.binary[0], int_char_arr.binary[1], int_char_arr.binary[2], int_char_arr.binary[3]: " << (int)int_char_arr.binary[0] << ", " << (int)int_char_arr.binary[1] << ", " << (int)int_char_arr.binary[2] << ", " << (int)int_char_arr.binary[3] << "\n\n";

  // USING ANONYMOUS UNION TO USE ONE TYPE FOR MULTI USE
  // example:
  struct Node {
    int data;
    union {
      struct {
        Node *left, *right;
      };
      struct {
        Node *prev, *next;
      };
    };
  };
  // above node structure can be used for doubly linked list as well as binary tree

  return 0;
}