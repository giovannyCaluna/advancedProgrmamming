// Default template parameters
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

  return 0;
}

/*
3
2
1
*/
