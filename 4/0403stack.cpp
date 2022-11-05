// Template specialisation
#include <iostream>
using namespace std;

// Stack class that can store N number of T type elements in an array
// If we do not provide arguments, then it will be able to store 100 int-s
template<class T = int, int N = 100>
class Stack {
  T data[N]; // N number of T type elements array
  int size; // number of stored elements
public:
  // constructor, which sets the size to 0
  Stack() : size(0) {}
  // adding an element
  void push(const T &e) {
    data[size++] = e;
  }
  // returning the last element
  T pop() {
    return data[--size];
  }
};

// Special case
// If we want to store only one element then it is superfluous to use an array,
// it is enough to store only the given value.
template<class T>
class Stack<T,1> {
  T data; // one piece of type T element, which will be stored
public:
  // adding an element
  void push(const T &e) {
    data = e;
  }
  // returning the element
  T pop() {
    return data;
  }
};

int main() {
  // creating a stack
  // we do not provide arguments, so it will store 100 int-s
  Stack<> stack;
  // adding elements
  stack.push(1);
  stack.push(2);
  stack.push(3);
  // getting elements and writing them to the console
  for (int i = 0; i < 3; i++) {
    cout << stack.pop() << endl;
  }
  // creating a stack for storing 1 element.
  Stack<int,1> smallst;
  // adding elements
  smallst.push(1);
  smallst.push(2);
  // getting the element and writing it to the console
  cout << smallst.pop() << endl;
  return 0;
}

/*
3
2
1
2
*/
