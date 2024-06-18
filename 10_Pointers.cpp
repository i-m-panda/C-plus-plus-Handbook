#include<iostream>
#include<string>

// START READING AT main()

void printHello() {
  std::cout << "Hello!!!" << "\n\n";
}

void callPrintHello(void (*ptr)()) {
  ptr();
}

int* add(int a, int b) {
  int *c = new int; // if c was allocated in stack, it could have been deallocated before we could use it in calling function
  *c = a+b;
  return c;
}

void handle_1_D_array(int *A, int size_of_array) {
  for (int i = 0; i < size_of_array; i++) {
    std::cout << A[i] << " ";
  }
  std::cout << "\n";
}

void handle_2_D_array(int (*A)[3], int size_of_array) {
  for (int i = 0; i < size_of_array; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << A[i][j] << " ";
    }
  }
  std::cout << "\n";
}

void handle_3_D_array(int (*A)[2][2], int size_of_array) {
  for (int i = 0; i < size_of_array; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        std::cout << A[i][j][k] << " ";
      }
    }
  }
  std::cout << "\n";
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void addTen(int *A, int sizeOfArray) { // int *A or int A[] is the same
  for (int i = 0; i < sizeOfArray; i++){
    A[i] += 10;
  }
}

void printString(const char *C) {

  // c[0] = 'A'; // this is possible
  while (*C != '\0') {
    std::cout << *C;
    C++; // this is possible as C is pointer pointing to base address of the passed argument while calling printString
  }
  // another approach
  // int i = 0;
  // while (C[i] != '\0') {
  //   std::cout << C[i];
  //   i++;
  // }
  std::cout << "\n\n";
}

int main() {
  // Pointers: are the variables that store the address of other variables
  int a = 12334; // integer variable storing value 10
  // <DATA_TYPE> *<VARIABLE_NAME> is the notation to declare a pointer variable of type <DATA_TYPE>
  int *p = &a; // pointer to integer variable storing address of an integer variable, "&a" will return the address of "a"
  // p itself is also a variable so it's also stored in someplace in memory just like any other variable
  std::cout << "address of a: " << p << "\n"; // prints the address at which a is stored
  std::cout << "address of a: " << &a << "\n"; // prints the address at which a is stored
  std::cout << "address of p: " << &p << "\n"; // prints the address at which a is stored
  std::cout << "value stored at a: " << *p << "\n"; // prints the value stored at address of a, this is dereferencing
  // you can use dereferencing to not only get the value at an address but to also modify the value at an address, like below:
  *p = 67543;
  std::cout << "value stored at a now is: " << a << ", using variable name\n";
  std::cout << "value stored at a now is: " << *p << ", by dereference a pointer storing address of the variable\n";
  // IMPORTANT: you should never use or dereference a pointer variable without initialization, that may produce unintended results
  // you can use pointer arithmetic to access pointers before or after your declared pointer, like below
  std::cout << "pointer at p+1 address: " << p+1 << "\n";
  std::cout << "value at p+1 address: " << *(p+1) << "\n"; // this might give you unexpected result, as anything can be stored at p+1 location
  // also let's assume if p is pointer to integer and is storing an integer's memory address say "2000" and your compiler uses 4 bytes
  // to store an integer then p+1 would be the address "2004" and p+2 would be address "2008", so on and so forth
  // similarly for a pointer to character, say c, if compiler uses 1 byte to store char, and assuming c is holding an address
  // to a character say at 50003 then c+1 would be "50004"
  // you can modify the value using pointer arithmetic as well, but it's usually done in case of containers like arrays

  // pointer variables are strongly typed meaning you need a pointer of a particular type to store the address of a particular
  // type of variable, hence int*(pointer to integer) will only be able to hold the address of an integer, similarly char*
  // will be able to hold the address of a character, technically you can store other types by type casting but this will
  // cause unintended behaviour most probable one is loss of information

  // it's important for pointers to be strongly typed because the address of any variable is usually the starting bit
  // and to fetch the value at the address compiler need to know the type of the variable(to know the size of the variable)
  char *c = (char*)p; // NOT RECOMMENDED
  std::cout << "address of c: " << c << "\n";
  std::cout << "value at c address: " << *c << "\n";

  // VOID POINTER
  // void pointer is generic pointer
  void *p0 = p; // this is possible, although you can't dereference a void pointer, also you can't perform pointer arithmetic on void pointers
  // therefore in order to dereference the void pointer, it needs to be type casted into correct pointer type
  std::cout << "\nvoid pointer, type casted to int* and then dereferenced: " << *(static_cast<int*>(p0)) << "\n\n";

  // POINTERS TO POINTERS
  // you can store address of a variable in a pointer variable, using pointer to pointer you can store the address of 
  // a pointer storing address of a variable and this can go on like using pointer to pointer to pointer you can store 
  // the address of a pointer storing an address of a pointer that is storing the address of a variable. Look at the code 
  // below to understand
  int z = 222;
  int *q0 = &z;
  int **q1 = &q0;
  int ***q2 = &q1;
  std::cout << "\n";
  std::cout << "q0 is storing address of z: " << q0 << "\n";
  std::cout << "*q0 is the value at z: " << *q0 << "\n";
  std::cout << "\n";
  std::cout << "q1 is storing the address of q0: " << q1 << "\n";
  std::cout << "*q1 is storing the address of z: " << *q1 << "\n";
  std::cout << "**q1 is the value of z: " << **q1 << "\n";
  std::cout << "\n";
  std::cout << "q2 is storing the address of q1: " << q2 << "\n";
  std::cout << "*q2 is storing the address of q0: " << *q2 << "\n";
  std::cout << "**q2 is storing the address of z: " << **q2 << "\n";
  std::cout << "***q2 is the value of z: " << ***q2 << "\n";
  std::cout << "\n";
  ***q2 = **q1 + 4;
  std::cout << "value of z is incremented by 4 using dereferencing: " << z << "\n";

  // POINTERS AS FUNCTION ARGUMENTS - CALL BY REFERENCE
  // if you want to update the actual argument in calling function by using business logic of formal argument you can use pointers
  // look at the swap function above and the code below:
  int x1 = 11, x2 = 22;
  std::cout << "\nbefore swap\n";
  std::cout << "x1: " << x1 << " x2: " << x2 << "\n";
  swap(&x1, &x2); // passing address of x1 and x2 as actual argument
  std::cout << "after swap\n";
  std::cout << "x1: " << x1 << " x2: " << x2 << "\n";

  // ARRAYS AND POINTERS

  // int a[4] = {43, 124, 483, 872};
  // int x = 20;
  // int *x0 = &x;
  // Memory
  //         200    204    208    212    216    220    224    228    232
  // __________________________________________________________________________
  // <--   | 43   |124   |483   |872   |      |      | 20   |      |      | -->
  // ______|______|______|______|______|______|______|______|______|______|____
  //         a[0]   a[1]   a[2]   a[3]                 x0
  
  // &a[0] is equvivalent to a which would be 200 if above memory is mapped
  // &a[1] is equvivalent to (a + 1) which would be 204 if above memory is mapped
  // &a[2] is equvivalent to (a + 2) which would be 208 if above memory is mapped

  // a[0] is equvivalent to *a 
  // a[1] is equvivalent to *(a + 1)
  // a[2] is equvivalent to *(a + 2)

  // x0 or &x would be 224 if above memory is mapped
  // *x0 would be 20 which would be value stored in x

  // as array are stored in contiguos memory location, you can use pointer arithmetic to go to address of a specific array index
  int arr1[4] = {43, 124, 483, 872};
  std::cout << "\n" << "arr1: " << arr1 << ", is the base address or address of a[0] " << "\n";
  std::cout << "arr1[0]: " << *arr1 << ", is the dereference of the value stored at address of a[0] or arr1 " << "\n";

  // similarly you can access the address of a[2] like below using pointers:
  std::cout << "\n" << "&arr1[2]: " << arr1+2 << ", is the address of a[2] " << "\n";
  // and the value at a[2] like below using pointer:
  std::cout << "arr1[2]: " << *(arr1+2) << ", is the dereference of the value stored at address of a[2] or arr1+2 " << "\n";

  // following the above logic you can access address of element of arr1 at "i" index, like below:
  // &arr1[i] or (arr1 + i)
  // also you can access the value of element of arr1 at "i" index, like below:
  // arr1[i] or *(arr1 + i)

  // IMPORTANT:
  // although arr1 returns the base address of the arr1 array, you can't arr1++ (this is not possible)
  int *arr10 = arr1;
  arr10++; // this is possible and allowed

  // ARRAY AS FUNCTION ARGUMENT
  // arrays are always passed as reference not by value, it makes sense because array can have any amount of elements
  // so when you pass array as an argument, called function receives the base address of the array, say array arr1 is passed
  // as an argument then called function will receive &arr1 or &arr1[0] as the formal argument
  // due to these reasons you can't use sizeof trick to calculate no. of elements in an array in called function, also
  // if you make any changes in the array in called function, you will see the changes being refelected in the calling function
  // consider the code in the addTen() and below to strengthen the concept explained above

  int size_of_arr1 = sizeof(arr1)/sizeof(arr1[0]);
  std::cout << "\nbefore calling addTen()\n";
  for (auto &element : arr1) {
    std::cout << element << " ";
  }
  std::cout << "\n";
  addTen(arr1, size_of_arr1);
  std::cout << "after calling addTen()\n";
  for (auto &element : arr1) {
    std::cout << element << " ";
  }
  std::cout << "\n";

  // CHARACTER ARRAY AND POINTERS
  // to store a string in a character array, size of the array >= no. of characters in a string + 1
  // + 1 is because strings in character are terminated ny null character('\0')
  char s1[20]; s1[0] = 'J'; s1[1] = 'O'; s1[2] = 'H'; s1[3] = 'N';
  std::cout << "\n" << s1 << "\n"; // results in undefined behaviour as string is not null terminated above, let's fix that
  s1[4] = '\0';
  std::cout << s1 << "\n"; // should print "JOHN"
  std::cout << strlen(s1) << ": length of string s1\n";
  std::cout << sizeof(s1) << ": sizeof of s1 character array\n";

  // other ways to initialize character array
  char s2[] = "WELCOME"; // here string is implicitly null terminated
  std::cout << strlen(s2) << ": length of string s2\n";
  std::cout << sizeof(s2) << ": sizeof of s2 character array\n";

  // another way to initialize character array
  char s3[] = {'D', 'O', 'E', '\0'}; // here null termination have to be explicit
  std::cout << strlen(s3) << ": length of string s3\n";
  std::cout << sizeof(s3) << ": sizeof of s3 character array\n";

  // ARRAYS AND POINTERS ARE DIFFERENT TYPES THAT ARE USED IN SIMILAR MANNER
  // what's allowed for pointers 
  char c1[] = "Hello";
  char *c2 = c1; // c2 now has the base address of c1 character array
  // we can use c2 to modify character array and also to access c1 character array element or complete character array
  std::cout << "\n" << c2 << "\n";
  c2[0] = 'A';
  std::cout << c2 << "\n";
  std::cout << c2[3] << "\n"; // *(c2+3), c1[3] is *(c1+3)
  c2++; // this is allowed
  std::cout << c2 << "\n\n";

  // what's not allowed for character arrays(or arrays for that matter)
  // c1 = c2; // can't set array pointer(storing base address) to some other pointer(or anything for that matter)
  // c1++; // can't modify array pointer(storing base address), once you store pointer

  // ARRAYS ARE ALWAYS PASSED TO FUNCTION BY REFERENCE
  // look at the code below and observe printString() method above
  char c3[] = "Hello world!!"; // stored on stack
  // this works(not recommended), stored as a constant during 
  // the compile time, in this case you can't do this: c3[0] = "A";
  // char *c3 = "Hello world!!";
  printString(c3);

  // 2D ARRAYS AND POINTERS

  int b[2][3] = {{4, 1, 6}, {2, 8, 3}};
  
  // Memory
  //           400       404       408       412       416       420
  // ___________________________________________________________________________
  // <--   |   4     |   1     |   6     |   2     |   8     |   3     |  -->
  // ______|_________|_________|_________|_________|_________|_________|________
  //         b[0][0]   b[0][1]   b[0][2]   b[1][0]   b[1][1]   b[1][2]

  // b[0] -> 1-D array of 3 integers
  // b[1] -> 1-D array of 3 integers
  // b returns the address of 1-D array of 3 integer, therefore int *p = b will not work
  int (*pointer_for_b_array)[3] = b;
  std::cout << b << "\n"; // &b[0] or 400 (if you consider above memory mapping)
  std::cout << *b << "\n"; // b[0] or &b[0][0] or 400 (if you consider above memory mapping)
  std::cout << b+1 << "\n"; // &b[1] or 412 (if you consider above memory mapping)
  std::cout << *(b+1) << "\n"; // b[1] or &b[1][0] or 412 (if you consider above memory mapping)
  std::cout << *(b+1) + 2 << "\n"; // b[1]+2 or &b[1][2] or 420 (if you consider above memory mapping)
  std::cout << *(*b+1) << "\n\n"; // b[0][1] or 1

  // pointer_for_b_array and b can be used interchangebly
  std::cout << pointer_for_b_array << "\n"; // &b[0] or 400 (if you consider above memory mapping)
  std::cout << *pointer_for_b_array << "\n"; // b[0] or &b[0][0] or 400 (if you consider above memory mapping)
  std::cout << pointer_for_b_array+1 << "\n"; // &b[1] or 412 (if you consider above memory mapping)
  std::cout << *(pointer_for_b_array+1) << "\n"; // b[1] or &b[1][0] or 412 (if you consider above memory mapping)
  std::cout << *(pointer_for_b_array+1) + 2 << "\n"; // b[1]+2 or &b[1][2] or 420 (if you consider above memory mapping)
  std::cout << *(*pointer_for_b_array+1) << "\n\n"; // b[0][1] or 1

  // for 2-D  array
  // b[i][j] = *(b[i] + j) = *(*(b + i) + j)
  // b or *b or b[0] or &b[0][0] = 400 (if you consider above memory mapping)

  // 3D or MULTI-DIMENSIONAL ARRAYS AND POINTERS
  int o[3][2][2] = {{{4, 1}, {2, 6}}, {{11, 8}, {5, 3}}, {{7, 32}, {9, 12}}};
  
  // Memory
  //          800          804          808          812          816          820          824          828          832          836          840          844
  // ________________________________________________________________________________________________________________________________________________________________________
  // <-- |     4      |     1      |   2        |   6        |   11       |   8        |   5        |   3        |   7        |   32       |   9        |   12       |  -->
  // ____|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|_______
  //       o[0][0][0]   o[0][0][1]   o[0][1][0]   o[0][1][1]   o[1][0][0]   o[1][0][1]   o[1][1][0]   o[1][1][1]   o[2][0][0]   o[2][0][1]   o[2][1][0]   o[2][1][1]

  // o[0] -> 2-D array of 1-D array of 2 elements
  // o[0][0] -> 1-D array of 2 elements
  // o[0][0][0] -> element stored in a 1-D array

  int (*pointer_for_o_array)[2][2] = o;

  std::cout << o << "\n"; // 800 (if you consider above memory mapping)
  std::cout << *o << "\n"; // o[0] or &o[0][0] or 800 (if you consider above memory mapping)
  std::cout << *(o[0][1] + 1) << "\n"; // o[0][1][1] or 6
  std::cout << *(o[1] + 1) << "\n\n"; // o[1][1] or &o[1][1][0] or 824 (if you consider above memory mapping)

  // pointer_for_o_array and o can be used interchangebly

  std::cout << pointer_for_o_array << "\n"; // 800 (if you consider above memory mapping)
  std::cout << *pointer_for_o_array << "\n"; // o[0] or &o[0][0] or 800 (if you consider above memory mapping)
  std::cout << *(pointer_for_o_array[0][1] + 1) << "\n"; // o[0][1][1] or 6
  std::cout << *(pointer_for_o_array[1] + 1) << "\n"; // o[1][1] or &o[1][1][0] or 824 (if you consider above memory mapping)

  // for 3-D array
  // o[i][j][k] = *(o[i][j]+k) = *(*(o[i]+j)+k) = *(*(*(o+i)+j)+k)

  // PASSING ARRAYS TO FUNCTIONS USING POINTERS
  // 1-D array, have a look at the method definition for handle_1_D_array
  handle_1_D_array(arr1, 4);
  // 2-D array, have a look at the method definition for handle_2_D_array
  handle_2_D_array(b, 2);
  // 3-D array, have a look at the method definition for handle_3_D_array
  handle_3_D_array(o, 3);

  // DYNAMIC MEMORY ALLOCATION
  // memory architecture from a program execution perspective
  // ___________________
  // |                 | --
  // |                 |   |
  // |      HEAP       |   |
  // |                 |   |--> Free storage
  // |                 |   |
  // |                 |   |
  // |_________________| --
  // |                 | --
  // |                 |   |--> Function calls, local variables
  // |      STACK      |   |
  // |_________________| --
  // |                 | --
  // |  STATIC/GLOBAL  |   |--> Global/static variable
  // |_________________| --
  // |                 | --
  // |      CODE       |   |--> Instructions
  // |_________________| --

  // - Dynamic memory allocation happens on heap, which is a free pool of memory
  // - Any dynamic memory allocation remains allocated during the program life-cycle, unless it's freed explicitly
  // - C function for dynamic memory are: 
    // - malloc: function signature: void* malloc(size_t size) | definition: allocates the memory on heap according to passed argument(number of bytes), allocates default value as garbage value
    // - calloc: function signature: void* calloc(size_t, num, size_t size) | definition: allocates the memory on heap by multiplying the first argument with second argument(no. of bytes for data type), allocates deafult value as zero
    // - realloc: function signature: void* malloc(void* ptr, size_t size) | definition: reallocates the memory on heap and copies the data from previous memory(pass as first argument)
    // - free: definition: deallocated the memory for the pointer that is passed as argument, please note that it can still be accessed, but it's not recommended to access deallocated memory 
  // - C++ operators for dynamic memory are: new, delete // C++ obviously has backward compatibility to C hence C methods can also be used for dynamic memory manipulation
  // - code below should give you some idea of how dynamic memory allocation works in C and C++

  // dynamic memory allocation in C
  int t = 89; // goes on stack
  int *t1;
  t1 = (int*)malloc(sizeof(int)); // malloc returns a void pointer, allocates asked amount of memory in heap and returns the pointer to the location
  *t1 = 20; // this will write the value 20 at the memory location in heap
  std::cout << "\n" << *t1 << "\n";
  free(t1);
  t1 = (int*)malloc(sizeof(int)); // new pointer, pointing to new location is returned
  // previous memory allocated will still be present and allocated until the program, instructs to delete it using free(), which we did one line above
  *t1 = 25; // this will write the value 25 at the new memory location in heap
  std::cout << *t1 << "\n";
  *t1 = t; // this will write the value of "t" i.e. 89 at the new memory location in heap
  std::cout << *t1 << "\n\n";
  free(t1);
  // for allocating memory for array
  t1 = (int*)malloc(20*sizeof(int)); // this will allocate contiguous memory of 80bytes(if each integer is taking 4 bytes) for int array of 20 elements
  free(t1);
  

  // dynamic memory allocation in C++
  int *t2;
  t2 = new int; // new and delete are type safe operators, so no type casting is required
  *t2 = 78;
  std::cout << *t2 << "\n";
  // to free the memory allocated use delete operator, if not used, memory leaks will occur
  delete t2;
  t2 = new int;
  *t2 = 68;
  std::cout << *t2 << "\n";
  *t2 = t;
  std::cout << *t2 << "\n\n";
  delete t2;
  t2 = new int[20];
  delete[] t2;

  // RETURNING POINTER FROM FUNCTION
  // while returning pointer from a funtion we have to be sure that the memory shouldn't be reused or deallocated
  // before we use it in the calling function, one way to resolve this issue is by returning pointer from heap or global memory location

  // take a look at add() function above
  int g = 1, u = 5;
  int *sum = add(g, u);
  std::cout << *sum << "\n\n";
  delete sum;

  // FUNCTION POINTERS
  void (*ptr)(const char*); // parenthesis are important void *ptr(const char*); is not valid as this statement becomes function declaration
  ptr = &printString; // ptr = printString is also valid and preferred
  (*ptr)("Hello world"); // ptr("Hello world") is also valid and preferred

  // another example
  int* (*pointer_to_sum)(int, int);
  pointer_to_sum = add;
  int *ii = pointer_to_sum(6, 9);
  std::cout << *ii << "\n\n";
  delete ii;

  // use-cases for function pointer is callbacks, calling a function within other function
  // example:
  callPrintHello(printHello); // callPrintHello(&printHello); is also valid
  
  // NULL POINTERS
  // dereferencing a pointer which is not intialized or have been deallocated can cause your program to behave in a weird way
  // you can use null pointer to tackle this issue

  // if you are not assiging value to pointer during declaration then:
  // initialize the pointer as NULL -> before dereferencing check if the pointer is valid or not -> dereference the pointer

  int *nptr = NULL;
  // some computation
  // if (nptr) {} will also work
  if (nptr != NULL) { // without this if condition, if nptr was not initialized, then it would cause weird bugs to popup
    std::cout << *nptr << "\n\n";
  } else {
    std::cout << "nptr is NULL pointer hence it can't be dereferenced" << "\n\n";
  }
  // application of null pointer
  // - for pointers with no valid memory address initially
  // - for functions returning invalid output
  // - for DS like trees, linked list, etc.

  // nullptr in C++
  // - replacement of null pointer of C
  // - introduced in C++ 11
  // nullptr has type nullptr_t, therefore something like this: int x = nullptr is not allowed

  int *nptr1 = nullptr;
  if (nptr1) {
    std::cout << *nptr1 << "\n\n";
  } else {
    std::cout << "nptr1 is nullptr hence it can't be dereferenced" << "\n\n";
  }

  return 0;  
}

