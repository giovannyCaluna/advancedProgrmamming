// Typename keyword, using a type defined in a template parameter
#include <iostream>
using namespace std;

// class in which we define a type T
class TypeInside {
public:
    typedef int T; // definition of type T
};

// Stack class that can store N number of TD::T type elements in an array
template<class TD, int N>
class Stack {
  // TD is a template parameter so the compiler does not know what symbol TD::T means
  // we have to tell that it is a type by providing the typename keyword!
  typename TD::T data[N]; // // N number of T type (defined in TD) elements array
  int size; // number of stored elements
public:
  // constructor, which sets the size to 0
  Stack() : size(0) {}
  // adding an element
  void push(const typename TD::T &e) {
    data[size++] = e;
  }
  // returning the last element
  typename TD::T pop() {
    return data[--size];
  }
};

int main() {
  // creating a stack storing 100 elements of type defined in TypeInside
  Stack<TypeInside, 100> stack;
  // adding elements
  stack.push(1);
  stack.push(2);
  stack.push(3);
  // getting elements and writing them to the console
  for (int i = 0; i < 3; i++) {
    cout << stack.pop() << endl;
  }
  return 0;
}

/*
3
2
1
*/
