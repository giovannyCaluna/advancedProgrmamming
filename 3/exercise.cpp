//Exercise
//--------
//* Stack implementation with linked list

#include <iostream>
using namespace std;

template <class T>
class Stack {
  struct Elem {
    T data;
    Elem *next;
  };
  Elem *head;
public:
  Stack() : head(0) {}
  ~Stack() {
  	/*TODO*/
  }
  // adding an element
  void push(const T &e) {
    head = new Elem{e,head};  // g++ -std=c++11
  }
  // returning the last element
  T pop() {
  	T retVal = head->data;
  	Elem *oldHead = head;
  	head = head->next;
  	delete oldHead;
    return retVal;
  }
};

int main() {
  // creating a stack storing 3 int-s
  Stack<int> stack;
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

