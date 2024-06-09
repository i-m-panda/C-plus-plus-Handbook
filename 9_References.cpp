#include<iostream>
#include<vector>
#include<string>

// this doesn't work as in the function below parameters are passed as value
/*
void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}
*/

// this works as parameters are being passed as reference
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void printVector(std::vector<int> &v1) {
  for(const auto x: v1) {
    std::cout << x << "\n";
  }
  std::cout << "\n";
}

int &return_reference() {
  static int xx = 10;
  return xx;
}

int main() {
  // reference variable are references to other variable, you can think of them as another name for the variable
  int x = 10, z = 20;
  int &y = x; // y is a reference variable of x, any changes made in x and y will be reflected in both the variables
  y++;
  std::cout << "x: " << x << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "\n";
  x++;
  std::cout << "x: " << x << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "\n";
  y = z; // this is simple assignment, meaning x and y becomes 20
  y++; // z doesn't get affected as you can only assign a reference only once
  std::cout << "x: " << x << "\n";
  std::cout << "y: " << y << "\n";
  std::cout << "z: " << z << "\n";
  std::cout << "\n";
  // references have several application:
    // - to modify passed parameters, this is helpful when you want to pass parameter as reference 
    // because by default parameters are passed as value
    swap(z, x);
    std::cout << "x: " << x << "\n";
    std::cout << "y: " << y << "\n";
    std::cout << "z: " << z << "\n";
    std::cout << "\n";
    // - avoid copy of large objects during function call
    // to avoid editing the passed parameter you can make the element "const"
    std::vector<int> v = {1 ,3 ,4 ,5, 6, 7, 8, 9};
    printVector(v);
    // - modifications of elements in for each loop
    for(auto x: v) {
      // this won't work as for foreach by default values are passed as value and not by reference
      x = x + 2;
    }
    printVector(v);
    for(auto &x: v) {
      x = x + 2;
    }
    printVector(v);
    // - avoiding copy of large objects in for each loop
    for(const auto &x: v) {
      std::cout << x << "\n";
    }
    std::cout << "\n";
  // some important points regarding reference
    // - we should NEVER return reference to a NON STATIC LOCAL variable of a function, 
    // consider the code in function return_reference() and the code below
    int &yy = return_reference();
    std::cout << "return_reference(): " << return_reference() << "\n";
    yy = 20;
    std::cout << "return_reference(): " << return_reference() << "\n";
    std::cout << "\n";
    // - references as used as alias
    // - must be assigned when declared
    // - must not refer to another location once it become an alias of some variable
    // - cannot be NULL
    // - safer and easier than pointers
  
  // R VALUE REFERENCE
    // r values are data values that are temporarily stored in memory, literals and expressions are exmaple of r values
    // you cannot use reference that are mentioned above to reference r values
    // you should use "const" if the value need not be updated
    // or
    // you should use "&&"" if the value needs to be updated

    // int &zz = 7945; // this won't compile
    const int &zz = 7945;
    int &&ii = 6834235;

    // std::string &s = "abhishek" // this won't compile
    const std::string &s = "abhishek";
    std::string &&ss = "abhishek";
    // use same trick while passing r values as argument to a function and you want update value or optimise function


    // ADDRESS AND DEREFERENCE OPERATORS IN C++
    // address operator(&): when used before a variable(except during declaration), it gives back the address of the variable
    // dereference operator(*): when used before an address(except during declaration), it gives back the value at the address
    int q = 123;
    std::cout << "&q: " << &q << "\n";
    std::cout << "*(&q): " << *(&q) << "\n";
    std::cout << "\n";
  return 0;
}