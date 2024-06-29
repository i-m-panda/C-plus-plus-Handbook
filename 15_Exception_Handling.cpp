#include<iostream>
#include<exception>
// Exceptions are runtime anomalies or abnormal conditions that a program encounters during its execution
// In C++
  // we can use "throw" to throw an exception
  // we can use "try" to wrap the code where we suspect the code can fail
  // we can use "catch" to catch an expection, this prevents program to crash unexpectedly and allow us to bring our program to stable state

// SYNTAX
/*
try {         
  // Code that might throw an exception
  throw Some_error; // explictly 
 } 
catch( ExceptionType ExceptionName e )  {   
  // catch block catches the exception that is thrown from try block
}
*/

// TYPE OF EXCEPTIONS THAT CAN BE THROWN IN C++
/*
+------------------------+-----------------------------------------------------------+
| Exception              | Description                                               |
+------------------------+-----------------------------------------------------------+
| std::exception         | Exception and parent class of all standard C++ exceptions.|
| std::bad_alloc         | Generally thrown by new.                                  |
| std::bad_cast          | Generally thrown by dynamic_cast.                         |
| std::bad_typeid        | Generally thrown by typeid.                               |
| std::bad_exception     | Useful device to handle unexpected exceptions.            |
| std::logic_failure     | Can be detected by reading code.                          |
| std::runtime_error     | Cannot be detected by reading code.                       |
| std::domain_error      | Thrown when using a mathematically invalid domain.        |
| std::invalid_argument  | Thrown when using invalid arguments.                      |
| std::length_error      | Thrown when a large std::string is created.               |
| std::out_of_range      | Thrown by the at method.                                  |
| std::overflow_error    | Thrown when a mathematical overflow occurs.               |
| std::range_error       | Thrown when attempting to store an out-of-range value.    |
| std::underflow_error   | Thrown when a mathematical underflow occurs.              |
+------------------------+-----------------------------------------------------------+
*/

// EXAMPLE
int main() {
  std::cout << "Enter your age.\n";
  int age;
  try {
    std::cin >> age;
    if (age < 10) {
      throw std::runtime_error("You are not allowed to play");
    }
    std::cout << "You can play!!\n";    
  } catch(const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  // above program never fails based on user input

  // - you can have multiple catch blocks to handle multiple types of errors
  std::cout << "\n";
  try {
    throw 0;
  } catch(int e) {
    // this gets executed
    std::cerr << "caught an error of type int\n";
  } catch(double e) {
    std::cerr << "caught an error of type double\n";
  }
  std::cout << "\n";
   try {
    throw 0.1; // if you throw an error of type other than int or double, the program will crash
  } catch(int e) {
    std::cerr << "caught an error of type int\n";
  } catch(double e) {
    // this gets executed
    std::cerr << "caught an error of type double\n";
  }
  // - a catch block catches the error based on type of error thrown, if no matching type catch is found then program terminates abruptly
  // - you can also use throw on a function to specify which type of exception it can throw (this is: Dynamic Exception Specification which 
  // is deprecated in C++11 standard as it may cause program to terminate with an error of different type is thrown than what is mentioned in function definition)
  // - nesting is allowed for try catch blocks
  // - there is a special catch block catch(...) to catch any kind of exception, which gets executed(if implemented) when no matching type catch block is found
   std::cout << "\n";
   try {
    throw "I am string error";
  } catch(int e) {
    std::cerr << "caught an error of type int\n";
  } catch(double e) {
    std::cerr << "caught an error of type double\n";
  } catch(...) {
    // this gets executed
    std::cerr << "caught an error which was not caught by other catch blocks\n";
  }
  // - when an exception is thrown, all objects created inside the enclosing try block are destroyed before the control is transferred to the catch block
  // - you can obviously re-throw the caught error or a new error from the catch block

  // USER DEFINED EXCEPTION
  // in C++ you throw built in exceptions, primitive data type errors and user-defined exception as well
  class HelloWorld {};
  try {
    throw HelloWorld();
  } catch(const HelloWorld &e) {
    std::cout << "\n" << "World says hello" << "\n";
  }
  
  // you can define your own execption class by inheriting from exception class and overriding "what" function of the exception class, consider the code below
  class WeirdException : public std::exception {
    // virtual function in exception class, name of function: what, returns const char*, it's const function(doesn't change data member), throw list is empty(it doesn't throw error which are not caught here)
    public: virtual const char* what() const throw() {
      return "Weird exception has happened";
    }
  };

  try {
    throw WeirdException();
  } catch (const WeirdException &e) {
    std::cout << e.what() << "\n\n";
  };

  return 0;
};
