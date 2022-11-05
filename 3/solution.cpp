#include <iostream>
#include <string>
using namespace std;

class StackEmptyException {
};

// Stack class that can store any number of T type elements in a linked list
template<class T>
class Stack {
  struct Elem {
    T data;
    Elem *next;
  };
  Elem *head; // first (top) element
  int size; // number of stored elements
public:
  Stack() : head(nullptr), size(0) {}  // g++ -std=c++11
  ~Stack() {
    while (size)
      pop();
  }

  // adding an element
  void push(const T &e) {
    head = new Elem{e,head};  // g++ -std=c++11
    ++size;
  }
  // returning the last element
  T pop() {
    if (size == 0)
      throw StackEmptyException();
    Elem *p = head;
    head = head->next;
    T tmp = p->data;
    delete p;
    --size;
    return tmp;
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
  try {
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
    //stack2.push(A("three"));
    // getting elements and writing them to the console
    for (int i = 0; i < 3; i++) {
      cout << stack2.pop() << endl;
    }
  }
  catch (StackEmptyException) {
    cout << "StackEmptyException happened" << endl;
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
