// Smart Pointers are used to solve memory leak problem
// smart pointers are class wrapper around normal pointer to handle deallocation of memory

#include<iostream>
#include<memory>
// implementation of generic smart pointer
template <class T>

class SmartPointer {
  T *pointer_to_t;
  public:
    SmartPointer(T *ptr = nullptr) {
      this->pointer_to_t = ptr;
    }
    ~SmartPointer() {
      delete this->pointer_to_t;
    }
    T& operator*() { // this is needed to access the pointer of class T
      return *(this->pointer_to_t);
    }
    T* operator->() { // this is needed to access the value of the pointer of class T
      return this->pointer_to_t;
    }
};

class Employee {
  public:
    int age;
    std::string name;
  Employee(int age, std::string name): age(age), name(name) {};
};

int main() {
  SmartPointer<int> sp(new int()); // after main ends this memory will be de-allocated
  *sp = 3;
  std::cout << *sp << "\n\n";
  SmartPointer<Employee> sp_emp(new Employee(25, "John")); // after main ends this memory will be de-allocated
  std::cout << sp_emp->name << "\n";
  std::cout << sp_emp->age << "\n\n";

  // one issue with smart pointers is that if more than one pointer is referring to memory allocated by smart pointer then after de-allocation, you may get error de-referencing one of the pointer
  // so memory should only be de-allocated 0 pointers are referencing to it, which is difficult to implement, therefore C++ provide several type of smart pointer to tackle situations like this


  // You can find these builtin smart pointer in "memory" header file

  // UNIQUE_PTR

  // it's a built in smart pointer that should point to one memory
  // copy constructor or assignment operator doesn't exists in unique_ptr class
  std::unique_ptr<Employee> u_ptr_emp = std::make_unique<Employee>(35, "Ryan"); // compiler using C++ standard < C++14 can use this instead std::unique_ptr<Employee> u_ptr_emp(new Employee(35, "Ryan"));
  std::cout << u_ptr_emp->name << "\n";
  std::cout << u_ptr_emp->age << "\n\n";
  // std::unique_ptr<Employee> u_ptr_emp_2 = u_ptr_emp; // this is not allowed but you can use "move()" to move the ownership from 1 pointer to another
  std::unique_ptr<Employee> u_ptr_emp_2 = std::move(u_ptr_emp);
  std::cout << u_ptr_emp_2->name << "\n";
  std::cout << u_ptr_emp_2->age << "\n\n";
  // one advantage is it causes very less overhead

  // SHARED_PTR

  // it's a smart pointer that can be used to have co-ownership distributed across multiple pointers, it keeps a reference count which can be accessed by use_count()
  // and the assigned memory is only de-allocated if all the pointers referencing the memory stop referencing
  std::shared_ptr<Employee> s_ptr_emp = std::make_shared<Employee>(27, "Roger");
  std::shared_ptr<Employee> s_ptr_emp_2 = s_ptr_emp;
  std::shared_ptr<Employee> s_ptr_emp_3 = s_ptr_emp;
  std::cout << s_ptr_emp->name << "\n";
  std::cout << s_ptr_emp->age << "\n";
  std::cout << s_ptr_emp.use_count() << "\n\n";
  std::cout << s_ptr_emp_2->name << "\n";
  std::cout << s_ptr_emp_2->age << "\n";
  std::cout << s_ptr_emp_2.use_count() << "\n\n";
  std::cout << s_ptr_emp_3->name << "\n";
  std::cout << s_ptr_emp_3->age << "\n";
  std::cout << s_ptr_emp_3.use_count() << "\n\n";
  // one disadvantage is that it has some overhead as it maintains a reference count

  // WEAK_PTR

  // it's a smart pointer which are used with shared pointer but there is no ownership so no increase in reference count
  std::weak_ptr<Employee> w_ptr;
  w_ptr = s_ptr_emp_3;
  std::cout << w_ptr.use_count() << "\n"; // shows reference count of shared pointer
  std::cout << s_ptr_emp_3.use_count() << "\n\n";
  std::shared_ptr<Employee> s_ptr_emp_4 = w_ptr.lock();
  std::cout << s_ptr_emp_4->name << "\n";
  std::cout << s_ptr_emp_4->age << "\n";
  std::cout << s_ptr_emp_4.use_count() << "\n";

  // you can't derefernce a weak_ptr to dereference it you need to convert it into shared_ptr using lock() first
  // you can use expired() on weak_ptr to know if the object has been de-allocated(returns true) or not(returns false)
  // weak_ptr are useful for caching and also help in de-allocating cyclic references
  return 0;
}