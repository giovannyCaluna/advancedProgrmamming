// Non-type template parameter
#include <iostream>
using namespace std;

// Stack class that can store N number of T type elements in an array
template<class T, int N>
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

int main() {
  // creating a stack storing 3 int-s
  Stack<int,3> stack;
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
