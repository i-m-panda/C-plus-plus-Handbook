#include<iostream>
#include<string>

// START READING AT main()

int main() {

  // String in C++ are sequence of characters
  // string characters are internally stored as characters only
  //                       |----> C-style string
  //     String in C++  ---|
  //                       |----> C++ string class

  // C-STYLE STRING
  // is a character array terminated by null character('\0')

  char s1[] = "abc"; // stored in an char array: [ a | b | c | \0]
  char s2[] = {'a', 'c', 'b', '\0'};  // stored in an char array: [ a | c | b | \0]
  // if we skip null character in C-Style string, compiler won't be able to find the end of the string or it might think string terminated 
  // somewhere else, which will cause your program to become unreliable or downright buggy.

  // some common function for C-Style string
    // strlen(arg1): returns the length of string
    std::cout << strlen(s1) << "\n";
    // strcmp(arg1, arg2): returns 0 if arg1 is lexigraphically equal to arg2, 
    // returns -ve if arg1 is lexigraphically smaller than arg2, returns +ve if arg1 is lexigraphically bigger than arg2 
    std::cout << strcmp(s1, s2) << "\n";
    // strcpy(arg1, arg2): if you create a character array and you want to initialise it later, that's not allowed in such case
    // you can use strcpy, "arg1" is the character array, "arg2" is the string you want to assign to "arg1"
    char s3[9];
    // s3 = "hello" is not allowed
    strcpy(s3, "hello"); // this is allowed
    std::cout << s3 << "\n\n";

    // C++ STRING CLASS (RECOMMENDED)
    // internally stored as C-style string only

    std::string str1 = "hello world";
    std::cout << str1 << "\n";

    // advantages:
      // we don't have to worry about size, you append, reduce the string but you don't need to worry about string's size
      // no need of strcpy, you can define the string and assign the value later without any issue
      // supports comparison operators like +, <, >, ==, <=, >= // strcmp is not required
      // has richer library support

    // common functions:
      // length(): returns the length of string
      std::cout << str1.length() << "\n";
      // substr(arg1, agr2): create substring from a string, where arg1 is the index from where the substring starts and arg2 is the 
      // length of the substring, can work with only 1 param as well, in such case it makes the substring till the end of the string
      std::cout << str1.substr(2, 5) << "\n";
      std::cout << str1.substr(3) << "\n";
      // find(arg1): checks if the given argument string is present in the string or not, if more than 1 occurence is present then we get index of first occurence
      // return index, if string is present else returns string::npos
      std::cout << str1.find("el") << "\n";
      std::cout << (str1.find("asjdbas") == std::string::npos) << "\n\n";

      // READING A STRING WITH SPACE\S FROM USER
      std::string full_name;
      std::cout << "Enter your full name" << "\n";
      getline(std::cin, full_name);
      std::cout << "Your name is: " << full_name << "\n";
      // you can also, pass 3rd argument to getline() function which will be delimiter for input, by default it's carriage return/new line

  return 0;
}
