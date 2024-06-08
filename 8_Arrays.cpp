#include<iostream>
int main() {
  // Arrays: is a collection of items of same data type, they are stored in contiguous memory location

  // Declaration + initialization of an array:

  // <DATA_TYPE> name_of_the_array[<SIZE_OF_ARRAY>] = {<ELEMENT_1>, <ELEMENT_2>, ... , <ELEMENT_N>};
  // you can also use <DATA_TYPE> name_of_the_array[] = {<ELEMENT_1>, <ELEMENT_2>, ... , <ELEMENT_N>};
  // in above case compiler figure out the size of array based on number of elements

  // Declaration without initialization of an array:
  // int arr[5];
  // or
  // int n = 5; int arr[n] // was not allowed in older version of C++
  // if you try to access a declared but not initialized array, you will get some garbage value

  // another way to auto initialize remaining elements to 0, we can do something like this:
  int arr1[10] = {2, 4, 5, 83, 92, 23}; // this will generate the following array: [2, 4, 5, 83, 92, 23, 0, 0, 0, 0]

  // alternate way to intialize an array, using initializer list initialization
  int arr2[] {1, 3, 5}; // [1, 3, 5]
  int arr3[4] {4, 5, 2, 6}; // [4, 5, 2, 6]
  int arr4[7] {1, 2}; // [1, 2, 0, 0, 0, 0, 0]

  // using sizeof of operator to determine size of the array
  // sizeof operator returns the size of argument passed in bytes

  int size_of_arr2 = sizeof(arr2) / sizeof(arr2[0]); // should return 3 as 12/4 = 3

  // ARRAY TRAVERSAL
  for (int i = 0; i < size_of_arr2; i++) {
    std::cout << arr2[i] << "\n";
  }

  std::cout << "\n";

  for(int x: arr2) {
    std::cout << x << "\n";
  }

  std::cout << "\n";

  // MODIFICATION DURING ARRAY TRAVERSAL
  for (int i = 0; i < size_of_arr2; i++) {
    arr2[i] = arr2[i] * 2;
    std::cout << arr2[i] << "\n";
  }

  std::cout << "\n";

  for(int &x: arr3) {
    x = x * 2;
  }
  for (int i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++) {
    std::cout << arr3[i] << "\n";
  }
  std::cout << "\n";

  // TYPES OF ARRAYS

  // FIXED SIZE
  // Allocated on function call stack
    // all of the above mentioned ways of initialization and declaration are allocated on function call stack
  // Allocated on heap
    // int *arr = new int[n] // using pointers

  // DYNAMIC SIZE
    // vectors in c++ STL
  return 0;
}

