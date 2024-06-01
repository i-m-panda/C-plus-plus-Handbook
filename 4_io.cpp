// I/O in C++
//                                       istream | ifstream            ostream | ofstream
// Input ----------------------------------> i/p stream -----> process ---> o/p stream -------------------------> Output
//       sequence of bytes from i/p device(keyboard, files,etc.)                        sequence of bytes to o/p device(monitor, file, etc.)

// istream: class for input stream
//    cin: object of istream for inputing data from i/p device
// ifstream: class for input stream from a file

// ostream: class for output stream
//    cout: object of ostream for outputing data to o/p device
//    cerr: object of ostream used for errors stream
//    clog: object of ostream used for logs stream
// ofstream: class for output stream to a file

// OUTPUT
// cout is used along with << (insertion operator)
// cout can be used to print variable, constants, result of expression, etc.
// endl & /n can be used to print new line, endl also flushes the o/p stream

// INPUT
// cin is used along with >> (extraction operator)
// it can be used to take user input
// you can use getline() to read the string with spaces, look at input_test3()
// caution: This function considers a new line or (‘\n’) character as the delimitation character and new line character is valid input for this function

#include<iostream>
#include<string>
#include<iomanip>

void input_test() {
  std::string name;
  std::cout << "Enter your name\n";
  std::cin >> name;
  std::cout << "Your name is: " << name << std::endl;
}

void input_test2() {
  int x, y;
  std::cout << "Enter 2 numbers\n";
  std::cin >> x >> y;
  std::cout << "Sum of your 2 numbers is: " << (x+y) << std::endl;
}

void input_test3() {
  std::string fullname;
  std::cout << "Enter your full name\n";
  getline(std::cin, fullname);
  std::cout << "Your full name is: " << fullname << std::endl;
}

// IO MANIPULATION
// to use stream manipulator you need to #include<iomanip> header file
// Boolean Values:
void io_bool_values() {
  std::cout << "-----starting io_bool_values()\n";
  bool a = true;
  std::cout << a << "\n";
  std::cout << std::boolalpha; // prints true false for boolean values
  std::cout << a << "\n";
  std::cout << std::noboolalpha; // prints 1 for true and 0 for false for boolean values (default behaviour)
  std::cout << a << "\n";
}

// Integer Values:
void io_int_values() {
  std::cout << "-----starting io_int_values()\n";
  int a = 43;
  // showbase & showpos once set are set for the whole program
  // you can use their conterpart noshowbase & noshowpos to revert the behaviour
  std::cout << std::showbase; // flag to print hexadecimal(0x) and octal(0) integers with their respective prefixes
  std::cout << std::showpos; // flag to print prefix positive sign(+) before the positive numbers
  std::cout << a << "\n";
  std::cout << std::hex; // flag for printing integer in hexadecimal format
  std::cout << a << "\n";
  std::cout << std::oct; // flag for printing integer in octal format
  std::cout << a << "\n";
  std::cout << std::uppercase; // flag to print everything in uppercase for hex and octal integers
  // you can use nouppercase to revert above flag
  std::cout << a << "\n";
  std::cout << std::dec; // flag for printing integer in decimal format
  std::cout << a << "\n";
  std::cout << std::noshowpos;
  std::cout << std::noshowbase;
  std::cout << std::nouppercase;
}
// formatting manipulation
// flags:
// setw(<INTEGER_FOR_SETTING_FIELD_WIDTH>) // needs to be used everytime you want to set a particular width
// setfill(<CHARACTER_FOR_FILLING_THE_EMPTY_FIELD_WIDTH>) // needs to be used once
// std::left // for left aligning, needs to be used once
// std::right // for right aligning, needs to be used once

void io_stream_formatting() {
  std::cout << "-----starting io_stream_formatting()\n";
  std::cout << std::setw(10);
  std::cout << std::setfill('#');
  std::cout << 31 << "\n";
  std::cout << std::left;
  std::cout << std::setw(10);
  std::cout << "Hey" << std::endl;
}

// FLOATING POINT DEFAULT PRINTING FORMAT
void floating_point_default_printing() {
  std::cout << "-----starting floating_point_default_printing()\n";
  // - no trailing zeros (trailing zeros are omitted while printing)
  double a = 1.2300;
  std::cout << a << "\n"; // 1.23
  // - default precision is 6
  double b = 1234.47464567; // 1234.47
  std::cout << b << "\n";
  double c = 123447.464567; // 123447
  std::cout << c << "\n";
  double d = 123447.564567; // 123448
  std::cout << d << "\n";
  // - precision means total digits(excluding the digits used after "e")
  // - when value before decimal point doesn't fit in 6 digits, power format is used
  double e = 123447564.567; // 1.23448e+08
  std::cout << e << "\n";
  double f = 134e+2;
  std::cout << f << "\n"; // 13400
  double g = 134e+5;
  std::cout << g << "\n"; // 1.34e+07
  double h = 1.34e+5;
  std::cout << h << "\n"; // 134000
}

// FLOATING POINT MANIPULATING DEFAULT PRINTING FORMAT
void floating_point_manipulate_default_printing() {
  std::cout << "-----starting floating_point_manipulate_default_printing()\n";
  std::cout << std::showpoint;
  double a = 1.2300;
  std::cout << a << "\n"; // 1.23000
  // - setprecision changes default precision to whatever you pass as argument
  std::cout << std::setprecision(4);
  double b = 1234.47464567;
  std::cout << b << "\n"; // 1234.
  std::cout << std::showpos;
  double c = 123447.464567; // +1234e+05
  std::cout << c << "\n";
  std::cout << std::noshowpos;
  double d = 123447.564567; // 1234e+05
  std::cout << d << "\n";
  // - precision means total digits(excluding the digits used after "e")
  // - when value before decimal point doesn't fit in 6 digits, power format is used
  std::cout << std::uppercase;
  double e = 123447564.567; // 1.234E+08
  std::cout << e << "\n";
  double f = 134e+2;
  std::cout << f << "\n"; // 1.340E+04
  double g = 134e+5;
  std::cout << g << "\n"; // 1.340E+07
  double h = 1.34e+5;
  std::cout << h << "\n"; // 1.340E+05
}

// FLOATING POINT FIXED & SCIENTIFIC FLAGS
// flags: 
// std::fixed (never uses e notation, precision means digits after decimal point, trailing 0s are added if digits are not enough)
// std:: scientific (always uses e notation, precision means digits after decimal point, trailing 0s are added if digits are not enough)
// std::defaultfloat (default printing)

void floating_point_scientific_fixed_printing() {
  std::cout << "-----starting floating_point_scientific_fixed_printing()\n";
  std::cout << std::setprecision(6);
  double a = 3.14, b = 1234567.896, c = 9.2e+7;
  std::cout << std::fixed;
  std::cout << a << "\n"; // 3.140000
  std::cout << b << "\n"; // 1234567.896000
  std::cout << std::setprecision(2);
  std::cout << a << "\n"; // 3.14
  std::cout << b << "\n"; // 1234567.90
  std::cout << c << "\n"; // 92000000.00

  std::cout << std::setprecision(6);
  std::cout << std::nouppercase;
  std::cout << std::scientific;
  std::cout << a << "\n"; // 3.140000e+00
  std::cout << b << "\n"; // 1.234568e+06
  std::cout << std::setprecision(2);
  std::cout << a << "\n"; // 3.14e+00
  std::cout << b << "\n"; // 1.23e+06
  std::cout << c << "\n"; // 9.20e+07

  std::cout << std::defaultfloat;
  std::cout << std::setprecision(6);
}

int main() {
  std::cout << "hello world!!" << "\n";
  input_test3();
  input_test();
  input_test2();
  io_bool_values();
  io_int_values();
  io_stream_formatting();
  floating_point_default_printing();
  floating_point_manipulate_default_printing();
  floating_point_scientific_fixed_printing();
  return 0;
}
