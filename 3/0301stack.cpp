// Type template parameter
#include <iostream>
#include <string>
using namespace std;

// Stack class that can store any number of T type elements in an array
template<class T>
class Stack {
  T *data; // array pointer for storing the elements
  int size; // number of stored elements
  int capacity; // actual size of the array
public:
  // constructor, which
  // -allocates the array
  // -sets the size to 0
  // -sets the capacity to 1
  Stack() : data(new T[1]), size(0), capacity(1) {}
  // desktructor, which releases the array
  ~Stack() {delete[] data;} // [] indicates that the whole array will be released

  // adding an element
  void push(const T &e) {
    // when capacity is reached we double the size of the array
    if (size == capacity) {
      T *newdata = new T[capacity*2]; // allocating a larger array
      for (int i = 0; i < capacity; i++) // copying all stored elements
        newdata[i] = data[i];
      delete[] data; // releasing the old array
      data = newdata; // setting the pointer
      capacity = capacity*2; // set the new capacity
    }
    data[size++] = e; // add the new element and increase size
  }
  // returning the last element
  T pop() {
    return data[--size];
  }
};

class A {
  string s;
public:
  A() {}
  A(string s) : s(s) {}
  friend ostream& operator<<(ostream &o, const A &a) {
    return o << a.s;
  }
};

int main() {
  // creating a stack storing int-s
  Stack<int> stack;
  // adding elements
  stack.push(1);
  stack.push(2);
  stack.push(3);
  // getting elements and writing them to the console
  for (int i = 0; i < 3; i++) {
    cout << stack.pop() << endl;
  }

  // creating a stack storing A-s
  Stack<A> stack2;
  // adding elements
  stack2.push(A("one"));
  stack2.push(A("two"));
  stack2.push(A("three"));
  // getting elements and writing them to the console
  for (int i = 0; i < 3; i++) {
    cout << stack2.pop() << endl;
  }

  return 0;
}

/*
3
2
1
three
two
one
*/
