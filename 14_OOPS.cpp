// In C++, a class can be considered as a data type having some properties(data member) and methods(member functions)
// an object can be considered as a variable of this object

// Object oriented programming is usually used where you have a complex system with many entities, which can talk to each other
// Function programming is preferred when you have a small task, script or problem solving(usually in competive programminf or test)
  // you can use funtional programming for big software as well but it get's difficult to manage such software as it grows and evolve

// OOPS concepts
// enacapsulation: bundle related data and functionality together
// abstraction: hiding internal details
// inheritance: reusing the code
// polymorphism: same name difference functionality

#include<iostream>
#include<string>

class Person {
  private:
    int age; // data member
  public:
    std::string name;
    void print_basic_name() { // member function
      std::cout << "You are: " << name << "\n";
      std::cout << "You are " << age << " years old" <<"\n\n";
    };
    Person(int _age, std::string _name) { // constructor of Person class
      age = _age;
      name = _name;
    };
};

class Student : public Person { // Student inheriting Person class
  private:
    int marks = 0; // marks is private data member which can only updated via set_marks() method and marks can only be viewed via show_marks()
  public:
    void set_marks(int _marks) {
      if (_marks >= 0 && _marks <= 100) {
        marks = _marks;  
      }
    };
    void show_marks() {
      std::cout << "You have aquired: " << marks << " marks" << "\n\n";
    }
    Student(int _age, std::string _name): Person(_age, _name) {}; // calling parent constructor
};
// START READING AT main()
class BirdWatching {
  public:
    static int total_counter;
    std::string name;
    int bird_watching_counter;
    
    BirdWatching(std::string name){
      this->name = name;
      this->bird_watching_counter = 0;
    };
    void increase_counter() {
      this->bird_watching_counter++;
      total_counter++;
    }
    static void show_total_counter() {
      // this is a static function
      // static functions do not have this pointer
      // static functions can't access non static members of the class
      std::cout << "Total birds watched " << total_counter << "\n";
    }
    void show_counter() {
      std::cout << "Total birds watched by " << this->name << " : "<< this->bird_watching_counter << "\n";
    }
};
int BirdWatching::total_counter = 0; // IMPORTANT: declared static memebr within a class should be defined in file

// EXAMPLE FOR FRIEND FUNCTION ----------------------------
class Driver; // declaring Driver class

// declaring Printer class
class DriverPrinter {
  public:
    void print_driver_details(const Driver &driver);
};

class Driver {
  private:
    std::string name;
    int age;
    int experience;
  public:
    Driver() : name(""), age(0), experience(0) {};
    Driver(std::string name, int age, int experience): name(name), age(age), experience(experience) {};
    friend void DriverPrinter::print_driver_details(const Driver &driver); // declaring DriverPrinter::print_driver_details as a friend of class Driver
};

void DriverPrinter::print_driver_details(const Driver &driver) {
  std::cout << "driver name: " << driver.name << "\n";
  std::cout << "driver age: " << driver.age << "\n";
  std::cout << "driver experience: " << driver.experience << "\n\n";
};
// --------------------------------------------------------

// EXAMPLE FOR FRIEND CLASS -------------------------------

class Painter {
  private:
    std::string name;
    int age;
    int experience;
  public:
    Painter() : name(""), age(0), experience(0) {};
    Painter(std::string name, int age, int experience): name(name), age(age), experience(experience) {};
    friend class PainterPrinter; // declaring class PainterPrinter as a friend to class Painter
};

class PainterPrinter {
  public:
    void print_painter_details(const Painter &painter){
      std::cout << "painter name: " << painter.name << "\n";
      std::cout << "painter age: " << painter.age << "\n";
      std::cout << "painter experience: " << painter.experience << "\n\n";
    };
};


// --------------------------------------------------------
int main() {
  Student john(23, "John Williams");
  john.print_basic_name();
  john.set_marks(67);
  john.show_marks();

  // CONSTRUCTORS
  // these are special functions of class which has same name as class name, they don't have any return type
  // they are called implicitly when your object is created

  class Car {
    private:
      int topspeed;
      std::string transmission;
    public:
      // if you skip defining the constructors below, compiler will create default constructor
      // with no body, meaning data member will be initialized with garbage value
      Car() { // can use intializer list for constructor Car(): topspeed(0), transmission("manual")
        topspeed = 0;
        transmission = "manual";
      };
      Car(int _topspeed, std::string _transmission) { // can use intializer list for constructor Car(): topspeed(_topspeed), transmission(_transmission)
        topspeed = _topspeed;
        transmission = _transmission;
      };
      // using initializer list for initializing data member in constructor is more efficient
      void print_car_details() {
        std::cout << "Your car's topspeed is: " << topspeed << "\n";
        std::cout << "Your car's transmission is: " << transmission << "\n\n";
      }
  };

  Car honda; // topspeed: 0, transmission: manual
  Car hyundai(200, "automatic"); // topspeed: 200, transmission: automatic

  honda.print_car_details();
  hyundai.print_car_details();

  Car *benz = new Car(); // topspeed: 0, transmission: manual
  Car *volkswagon = new Car(220, "manual"); // topspeed: 220, transmission: manual

  benz -> print_car_details(); // if a pointer to class is created, you can access members using arrow operator(->)
  volkswagon -> print_car_details();

  // COPY CONSTRUCTORS
  // these are special function which are called when you create an object from existing object
  // if not defined in class, compilers creates one for the class but it copies member from one class to another one by one and copy is shallow copy
  // therefore it's always a good idea to define your own copy constructor if data member has data type pointers involved because we need deep copy of such data members

  class Animal {
    int *weight;
    std::string name;

    public:
      Animal(int _weight, std::string _name) {
        weight = new int(_weight);
        name = _name;
      };

      void set_weight(int _weight) {
        *weight = _weight;
      }

      void show_weight() {
        std::cout << name << " is an animal and it's weight is: " << *weight << "\n";
      }
  };

  Animal m1(200, "duke");
  // Animal m2;  ---
  //                ----> this will not call copy constructor because this will first call the default constructor, then it will call assignment operator
  // m2 = m1     ---
  Animal m2(m1); // this is how you create one object from another // same as Animal m2 = m1;
  m1.show_weight(); // 200
  m2.show_weight(); // 200
  std::cout << "\n\n";
  m2.set_weight(400);
  m1.show_weight(); // 400 // because there is no copy constructor defined for Animal class weight data member(weight and name) are shallow copied
  m2.show_weight(); // 400 // to resolve this you can implement your own copy constructor
  std::cout << "\n\n";

  class Bird {
    int *weight;
    std::string name;

    public:
      Bird(int _weight, std::string _name) {
        weight = new int(_weight);
        name = _name;
      };

      // this is copy constructor, which allocates new memory for "weight" and then copies the value on the new address(deep copy)
      Bird(const Bird &b) { // if we pass parameter as value and not reference then this copy constructor call the copy constructor and it becomes recursive and non terminating
        int _weight = *(b.weight);
        weight = new int(_weight);
        name = b.name;
      };

      // destructor
      ~Bird() {
        delete weight; // de-allocating dynamic memory
      }

      void set_weight(int _weight) {
        *weight = _weight;
      }

      void show_weight() {
        std::cout << name << " is a bird and it's weight is: " << *weight << "\n";
      }
  };

  Bird b1(1, "Sparrow");
  Bird b2 = b1; // or Bird b2(b1); // our copy constructor will be called this time
  b1.show_weight(); // 1
  b2.show_weight(); // 1
  std::cout << "\n\n";
  b2.set_weight(2); // only affects b2's weight
  b1.show_weight(); // 1
  b2.show_weight(); // 2
  std::cout << "\n\n";

  // DESTRUCTORS
  // these are called when an object is destroyed, means when it goes out of scope
  // destructors have same name as the class and they begun with tilde(~)
  // there can be mulitple constructors in the class but there can only be one destructor per class
  // when you have multiple objects in the same scope, they are destructed in reverse order of their creation
  // when you use delete then also constrcutor is called
  // just like constructor if you don't define the destructor, compilers create destructor for your class
  // use-case of destructor: they should be defined in a class if there is dynamic memory allocation in the class, as destructor don't take care of that
  // take a look at Bird class for destructor

  // "THIS" POINTER
  // C++ compiler passes a special pointer to member method and constructor called this pointer which refers to the object on which you are calling the function

  class Test1 {
    public:
      int x;
      Test1(int _x) {
        x = _x; // internally this can be represented as this->x = _x
      };
  };

  // you can use this pointer to access class members(properties and methods), take a look at class Test2 below to understang this pointer usage:
  class Test2 {
    public:
      int x;
      Test2(int x) {
        this->x = x;
      };
      void add_one() {
        this->x++; // accessing property
      };
      void add_one_and_show_updated_x() {
        this->add_one(); // accessing member method
        std::cout << this->x << "\n";
      };
  };

  Test2 t1(10);
  t1.add_one_and_show_updated_x(); // prints 11
  std::cout << "\n\n";

  // another use-case for this pointer is that it can be used for chaining of functions
  class Computer {
    int ram_size;
    std::string cpu;
    public:
      Computer &set_ram(int ram_size) {
        this->ram_size = ram_size;
        return *this;
      };
      Computer &set_cpu(std::string cpu) {
        this->cpu = cpu;
        return *this;
      };
      void show_details() {
        std::cout << "RAM: " <<this->ram_size << " MB" << "\n";
        std::cout << "CPU: " << this->cpu << "\n\n";
      };
  };

  Computer intel;
  (intel.set_ram(8000)).set_cpu("i9");
  intel.show_details();

  // cout also uses chaining | (std:cout << "something") will return pointer of type ostream which can be chanined further
  // IMPORTANT: this pointer is a const pointer, you can't change it

  // STATIC MEMBERS
  // static members are created once per class and they are shared across all objects of the class
  // to manipulate static memebers, static methods are used
  // take a look at BirdWatching class above

  BirdWatching william("John William");
  BirdWatching joseph("Chris Joseph");
  
  william.increase_counter();
  joseph.increase_counter();
  william.increase_counter();
  william.increase_counter();
  joseph.increase_counter();

  william.show_counter();
  joseph.show_counter();

  BirdWatching::show_total_counter();
  std::cout << "\n\n";
  // INHERITANCE
  // purpose of inheritance is reusability
  // you can create a class with common functionality and then make other classes inherit from that class to reuse the former class functionalities and properties
  // you can use access_specifiers to specify which properties and methods of class are accessible and where
    // public: accessible anywhere outside the class
    // private: not accessible outside the class
    // protected: not accessible outside the class except inherited class/es
    // you can use access_specifier to specify inheritance access as well
      // public: protected and public of base class remain as they are, in derived class
      // private: protected and public of base class become private in derived class
      // protected: protected and public of base class become protected in derived class

  // sample code for inheritence
  class ElectricalEquipment {
    protected:
      int voltage;
      int wattage;
    public:
      // if you create a parameterized constructor for a class, then compiler doesn't create a default constructor implicitly for this class
      ElectricalEquipment(int voltage, int wattage): voltage(voltage), wattage(wattage) {};
  };

  class LightBulb : public ElectricalEquipment {
    public:
      std::string brand;
      // IMPORTANT: use initializer list to initialize parent class members(call parent's class parameterized constructor)
      LightBulb(std::string brand, int voltage, int wattage): brand(brand), ElectricalEquipment(voltage, wattage) {};
      void show_details() {
        std::cout << "VOLTAGE: " << this->voltage << "\n";
        std::cout << "WATTAGE: " << this->wattage << "\n";
        std::cout << "BRAND: " << this->brand << "\n\n";
      }
  };
  // whenever a new object of dervied class is created -> the order below is followed
  // Base class default constructor is called implicitly if derived class is not calling constructor of base class explicitly
    // if in above situation base class default constructor is missing, you'll get compilation error
    // to resolve this you can either create a default constructor in base class or add a parameterized constructor in base class then call this parameterized constructor in derived class
  // derived class constructor is called
  LightBulb philips("Philips", 240, 15);
  philips.show_details();

  // MULTIPLE INHERITANCE & MULTI-LEVEL INHERITANCE
  // multiple inheritance: when a class inherits from mutiple classes
  class A1 {};
  class B1 {};
  class C1 : A1, B1 {}; // order of constructor call -> A1 -> B1 (the order in which they are defined)
  // multi-level inheritance: when there are multiple levels in inheritance
  class A2 {};
  class B2 : A2 {};
  class C2 : B2 {};
  // diamond-problem with multiple inheritance
  // if a class gets inherited by 2 class and then these 2 classes gets inherited by some other class then it creates a diamond problem
  //          A
  //          |
  //   ---------------
  //   |             |
  //   B             C    // in this scenrario if D's object is created, then A's constructor will be called twice and D's object will have 2 copies of A's data member(properties)
  //   |             |    // also when you access A class properties via D's object then compiler will throw an error(<VARIABLE_NAME> is ambigous)
  //   ---------------
  //          |
  //          D
  // in such scenarios we can use virtual keyword while inheriting from top level(A) class, consider the code below
  class A3 {
    public:
      int x;
  };
  class B3 : public virtual A3 {};
  class C3 : public virtual A3 {};
  class D3 : public B3, C3 {};
  D3 d3;
  std::cout << "d3.x: " << d3.x << "\n\n";

  // VIRTUAL FUNCTIONS
  // they implement runtime polymorphism 
    // this can be achieved when you have base class pointer or refernce pointing to a derived class object(which is allowed in C++)
  class Base1 {
    // class not using virtual function
    public:
      void print() {
        std::cout << "base1\n";
      };
  };
  class Derived1 : public Base1 {
    public:
      void print() {
        std::cout << "derived1\n";
      };
  };

  Base1 base1;
  Derived1 derived1;
  base1.print(); // print base1
  derived1.print(); // print derived1
  Base1 *pointer_to_derived1 = &derived1; // this is allowed // base class pointer pointing to derived class object
  Base1 &reference_to_derived1 = derived1; // this is allowed // base class reference pointing to derived class object
  pointer_to_derived1->print(); // print base1 // to avoid this you can use "virtual function" in base class
  reference_to_derived1.print(); // print base1 // to avoid this you can use "virtual function" in base class
  std::cout << "\n\n";

  class Base2 {
    public:
      virtual void print() {
        std::cout << "base2\n";
      };
  };
  class Derived2 : public Base2 {
    public:
      void print() override { // override keyword: it's used to increase readibility and avoid some error(which may occur if you are overriding a non virtual function)
        std::cout << "derived2\n";
      };
  };

  Base2 base2;
  Derived2 derived2;
  base2.print(); // print base2
  derived2.print(); // print derived2
  Base2 *pointer_to_derived2 = &derived2; // this is allowed // base class pointer pointing to derived class object
  Base2 &reference_to_derived2 = derived2; // this is allowed // base class reference pointing to derived class object
  pointer_to_derived2->print(); // print derived2 as we have made print function virtual in base class, it's decided at runtime as to which function needs to be called
  reference_to_derived2.print(); // print derived2 as we have made print function virtual in base class, it's decided at runtime as to which function needs to be called
  std::cout << "\n\n";
  
  // how virtual functions are implemented? (not in c++ standard, but most compiler use this approach):
  // compiler uses:
    // VPTR: maintained with every object, points to vtable
    // VTABLE: which is there with every class, stores address of all virtual function present in the class
  // when object of class is created, some code is added to the constructor, this code sets the vptr to the vtable of the class
  // on calling an overriden method of this object, compiler goes to vptr -> which gives the vtable -> from there it gets the address of the function to be called

  // OPERATOR OVERLOADING
  // with operator overloading you can use operators to perform operations on user-defined data types like classes
  // 2 ways to do operator overloading: 
    // 1. define operator function inside the class(consider the code below)
    // 2. define a global function that take class objects as arguments
  class Complex {
    int real;
    int imaginary;
    public:
      Complex(): real(0), imaginary(0) {};
      Complex(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
      };
      Complex operator+(const Complex &obj) {                // ------ 
        Complex result;                                      //       |
        result.real = this->real + obj.real;                 //       |------------> this is operator function in class which is facililating operator overloading
        result.imaginary = this->imaginary + obj.imaginary;  //       |
        return result;                                       //       |
      }                                                      // ------ 
      void print_number() {
        std:: cout << this->real << "+i" << this->imaginary << "\n";
      };
  };
  Complex complex1(3, 5);
  Complex complex2(20, 6);
  Complex complex3 = complex1 + complex2;
  complex1.print_number();
  complex2.print_number();
  complex3.print_number();
  // IMPORTANT: compiler implement assignment operator for a class implicitly which does a shallow copy of class members which make the code below possible
  Complex complex4;
  complex4 = complex3; // this is made possible by implicit implementation of assignment operator
  // there is no issue here as Complex class constructor is not doing dynamic memory allocation but if that was the case then we would have to implement our own assignment operator, consider the code below for the same
  class ComplexWithPointers {
    public:
      int *real;
      int *imaginary;
      ComplexWithPointers() {
        this->real = 0;
        this->imaginary = 0;
      };
      ComplexWithPointers(int real, int imaginary) {
        this->real = new int(real);
        this->imaginary = new int(imaginary);
      };
      // copy constructor
      ComplexWithPointers(const ComplexWithPointers &c){
        int _imaginary = *(c.imaginary);
        int _real = *(c.real);
        this->real = new int(_real);
        this->imaginary = new int(_imaginary);
      };
      ComplexWithPointers operator+(const ComplexWithPointers &c) {
        ComplexWithPointers result;
        result.real = new int(*this->real + *(c.real));
        result.imaginary = new int(*this->imaginary + *(c.imaginary));
        return result;
      }
      void operator=(const ComplexWithPointers &c) {
        int _imaginary = *(c.imaginary);
        int _real = *(c.real);
        this->real = new int(_real);
        this->imaginary = new int(_imaginary);
      }
      ~ComplexWithPointers() {
        delete this->real;
        delete this->imaginary;
      }
      void print_number() {
        std:: cout << *(this->real) << "+i" << *(this->imaginary) << "\n";
      };
  };
  std::cout << "\n";
  ComplexWithPointers complex_with_pointers1(2, 4);
  ComplexWithPointers complex_with_pointers2(5, 8);
  ComplexWithPointers complex_with_pointers3(11, 5);
  complex_with_pointers1.print_number();
  complex_with_pointers2.print_number();
  complex_with_pointers3.print_number();
  ComplexWithPointers complex_with_pointers4 = complex_with_pointers2; // copy constructor gets called
  complex_with_pointers4.print_number();
  ComplexWithPointers complex_with_pointers5;
  complex_with_pointers5 = complex_with_pointers3; // assigment operator gets called(which we have implemented) 
  // meaning if you make changes in complex_with_pointers4 or complex_with_pointers3, it won't affect each other
  complex_with_pointers5.print_number();
  ComplexWithPointers complex_with_pointers6;
  complex_with_pointers6 = complex_with_pointers1 + complex_with_pointers3; // + operator gets called(which we have implemented)
  complex_with_pointers6.print_number();

  // some important points regarding operator overloading
    // - the purpose of operator overloading is to increase readibility and intuitiveness of the code
    // - operator functions should follow it's purpose nothing more, nothing less, meaning a + operator should add 2 objects, people shouldn't have the need to look into the
    // implementation of overloaded operator function, if they do, you are doing something wrong.
    // - operators like ., ::, ?. and sizeof can't be overloaded
    // - IMPORTANT: if a class is doing dynamic memory allocation then it needs to implement 3 things:
      // - copy constructor
      // - assignment operator
      // - destructor(to avoid memory leak, de-allocate memory)

  // FRIEND FUNCTIONS & CLASSES
  // C++ gives weird freedom to programmers, a class can specify a class as friend or declare a function as friend, which then can allow classes/functions to access class members even if they have
  // private as access_specifier

  // FRIEND FUNCTION
  // look at the declaration and definition Driver and DriverPrinter above
  std::cout << "\n";
  DriverPrinter driver_printer;
  Driver john_driver("John Wilson", 35, 7);
  // function print_driver_details of DriverPrinter is able to access the private properties of Driver class as Driver class has declared print_driver_details of DriverPrinter as a friend
  driver_printer.print_driver_details(john_driver);
  // you can also set global functions as friends

  // FRIEND CLASS
  // look at the declaration and definition Painter and PainterPrinter above
  std::cout << "\n";
  PainterPrinter painter_printer;
  Painter jacob_painter("Jacob Mark", 25, 3);
  // function print_painter_details of PainterPrinter is able to access the private properties of Painter class as Painter class has declared PainterPrinter class as a friend
  painter_printer.print_painter_details(jacob_painter);

  // some points regarding friendship in C++
    // - granted: a class specify what are it's friends
    // - not mutual
    // - not transitive
    // - not inherited
  
  return 0;
}