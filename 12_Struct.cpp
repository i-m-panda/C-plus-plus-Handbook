#include<iostream>
#include<string>

// A structure is a user-defined data type in C/C++. A structure creates a data type 
// that can be used to group items of possibly different types into a single type. 

// syntax:
// struct <STRUCT_NAME> {
//   member1;
//   member2;
//   member3;
//   .
//   .
//   .
//   memberN;
// };

struct Car {
  int top_speed;
  bool is_electric;
  std::string engine;
};

typedef struct Battery {
  int capacity;
  int peak_voltage;
} B; // assigning B as an alias to struct Battery

struct Person {
  int age;
  std::string name;

  Person(int a, std::string n) {
    // constructor initializing data member
    age = a;
    name = n;
  }

  void print_info() {
    // member method
    std::cout << "You are: " << name << "\nYour age is: " << age << "\n\n";
  }
};

void print_car_information(Car car) {
  std::cout << "============= " << " =============" << "\n";
  std::cout << "Top Speed of your car is: " << car.top_speed << "\n";
  std::cout << "Your car has: " << car.engine << "\n";
  std::cout << "Is your car electric: " << std::boolalpha << car.is_electric << "\n";
  std::cout << "============= " << " =============" << "\n\n";
}

void print_car_information_using_reference(Car &car) {
  // you can modify the struct as parameter is passed as reference
  car.top_speed = 200;
  std::cout << "============= " << " =============" << "\n";
  std::cout << "Top Speed of your car is: " << car.top_speed << "\n";
  std::cout << "Your car has: " << car.engine << "\n";
  std::cout << "Is your car electric: " << std::boolalpha << car.is_electric << "\n";
  std::cout << "============= " << " =============" << "\n\n";
}

void print_car_information_using_pointer(Car *car) {
  // you can modify the struct as parameter is passed as pointer
  car->top_speed = 220;
  car->is_electric = false;
  std::cout << "============= " << " =============" << "\n";
  std::cout << "Top Speed of your car is: " << car->top_speed << "\n";
  std::cout << "Your car has: " << car->engine << "\n";
  std::cout << "Is your car electric: " << std::boolalpha << car->is_electric << "\n";
  std::cout << "============= " << " =============" << "\n\n";
}

void print_car_information_using_pointer_without_changing(const Car *car) {
  // car->top_speed = 150; // somthing like this is not allowed as car is const although it's passed as pointer, you can do the same thing references
  std::cout << "============= " << " =============" << "\n";
  std::cout << "Top Speed of your car is: " << car->top_speed << "\n";
  std::cout << "Your car has: " << car->engine << "\n";
  std::cout << "Is your car electric: " << std::boolalpha << car->is_electric << "\n";
  std::cout << "============= " << " =============" << "\n\n";
}

int main() {
  struct Car tesla;  // keyword struct can be leftout(mandatory in C) in C++ // Car tesla; this is allowed in C++
  tesla.top_speed = 120; // if you don't initialise value then you get garbage value stored as data member
  tesla.is_electric = true;
  tesla.engine = "V8";

  // this way you can populate the structure but you have to follow the order in which data members were defined
  B duracell = { 3000, 240 }; // this way duracell.capacity = 3000 and duracell.peak_voltage = 240

  // this is C style initialization for struct, called designated initialization, with this use can initialize the data members in any order
  // you can also skip some data members initialization and in that case they get default value(only works if some values are initialized)
  // IMPORTANT: it is C style initialization so it might not work in C++(depends on compiler)
  B eveready = { .peak_voltage=220, .capacity = 2500};

  std::cout << "topspeed: " << tesla.top_speed << "\n"; // data member can be accessed via dot(.) operator
  std::cout << "is car electric: " << tesla.is_electric << "\n";
  std::cout << "engine: " << tesla.engine << "\n\n";

  // struct is a C style construct, we have classes in C++ which we can use in place of struct
  // STRUCT VS CLASS
    // class has all the members private by default
    // struct has all the members public by default

  // structures can act like classes as well, they support all the features of classes like, constructor, destructor, member methods, etc.
  // take a look at Person struct above

  Person john(30, "John Doe");
  john.print_info();

  // WHEN TO USE STRUCT AND CLASS
  // use struct when you want to compose multiple items and related functions together
  // when you want to focus on object oriented programming and it's features like data abstraction, encapsulation, polymorphism, etc. use classes
  // so the general rule of thumb use struct for small, isolated problem solving, for industry ready OOPs code use classes where logic 
  // is complex and there are several entities talking to eachother and remember the struct members are public by default and in class private by default
  // IMPORTANT: the inheritance behaviour is also different between struct(public by default) and class(private by default) but we change it using access specifier

  // STRUCTURE POINTERS
  // structure pointers can be created in a similar way we create pointers to primitive data type, consider the code below to understand usage:

  Person *pointer_to_john = &john;
  std::cout << pointer_to_john -> name << "\n\n"; // you can access member using -> (arrow operator) on struct pointer
  pointer_to_john -> age = 32; // modify the member using -> operator
  pointer_to_john -> print_info();

  // ARRAY OF STRUCTURES
  // syntax is same as creating array of primitive data type

  Battery batteries[5];
  for (int i = 0; i < 5; i++) {
    batteries[i].capacity = (i+1)*2000;
    batteries[i].peak_voltage = i+200+(i*i);
  }
  
  for (int i = 0; i < 5; i++) {
    std::cout << "battery " << i+1 << " capacity: " << batteries[i].capacity << ", peak voltage: " << batteries[i].peak_voltage << "\n";
  }
  std::cout << "\n";

  // PASSING STRUCTURE AS ARGUMENTS TO FUNCTIONS
  // by default struct are passed by value
  print_car_information(tesla);
  print_car_information_using_reference(tesla);
  print_car_information_using_pointer(&tesla);
  print_car_information_using_pointer_without_changing(&tesla);

  // STRUCTURE ALIGNMENT
  struct s1 {
    char c1;
    double d1;
    char c2;
  };

  struct s2 {
    char c1;
    char c2;
    double d1;
  };

  // output of 2 statements below is machine dependent and is most proabably different
  std::cout << "sizeof of s1: " << sizeof(s1) << "\n"; // for 64 bit architecture with gcc compiler you will get 24 as output
  std::cout << "sizeof of s2: " << sizeof(s2) << "\n\n"; // for 64 bit architecture with gcc compiler you will get 16 as output

  // reason why the size of s1 is 24 and s2 is 16 even though they have similar data member is because structure has alignment requirements
  // structure alignment requirement same as the largest member requirement which in case of s1 and s2 is double

  // primitive data type as well has alignment requirements as well
  // for example if an int is stored in 4 bytes then it's going to be stored at an address that begins where last 2 bits are 0 0, multiple of 4
  // similarly for double if it takes 8 bytes then it's going to be stored at an address that begins where last 3 bits are 0 0 0, multiple of 8
  
  //     ____________________________________________________________________________________________________
  // S1  | c1 |////////////////////////////|             d1               | c2 |////////////////////////////|
  //     ----------------------------------------------------------------------------------------------------
  //        1              7                              8                  1                7                 = 24

  //     _______________________________________________________________
  // S2  | c1 | c2 |////////////////////|             d1               |
  //     ---------------------------------------------------------------
  //        1    1          6                         8                      = 16

  // when creating structure for optimal alignment either declare members in increasing or decreasing order of size of members

  struct s3 {
    double d1;
    char c1;
    char c2;
  };

  std::cout << "sizeof of s3: " << sizeof(s3) << "\n\n"; // for 64 bit architecture with gcc compiler you will get 16 as output
  //     _______________________________________________________________
  // S3  |             d1               | c1 | c2 |////////////////////|
  //     ---------------------------------------------------------------
  //                    8                  1    1          6                 = 16

  // why alignment is needed?
    // CPU access physical memory in the form of words(4 bytes in a 32bit machine and 8 bytes in a 64bit machine)
      // this read cycle is efficient instead of reading each byte at a time
    // without alignment it will be inefficient to store data that span across multiple words
      // meaning if a machine is reading 1 byte at a time and it wants to read a double, it's going to take 8 read cycle to read one double data type data
      // 64bit machine would take 1 read cycle to read 1 double data type data
      // 32bit machine would take 2 read cycle to read 1 double data type data
    
    // if we remove alignment like below:
    //     __________________________________________
    // S2  | c1 | c2 |             d1               |
    //     ------------------------------------------
    //        1    1               8                    = 10
    // it would take lesser space i.e. 10 bytes but it would require 2 read cycle to read d1, in first read cycle it would read
    // c1, c2 and 6 byte of d1 and then it would read 2 more bytes of d1 which is inefficient
  
  // compilers take care of structure alignment
  // compilers like clang and gcc allows compact representation, you can tell the compiler to do compact representation
  struct s4 {
    char c1;
    char c2;
    double d1;
  }__attribute__((packed));
  // s4 will be represented like below:
  //     __________________________________________
  // s4  | c1 | c2 |             d1               |
  //     ------------------------------------------
  //        1    1               8                    = 10
  std::cout << "sizeof of s4: " << sizeof(s4) << "\n\n"; // for 64 bit architecture with gcc compiler you will get 10 as output
  return 0;
}