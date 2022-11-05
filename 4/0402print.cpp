// Constant function template parameter
#include <iostream>
using namespace std;

// function template, which prints the integer number arriving in template parameter.
template<int N>
void print() {
  cout << N << endl;
}

int main() {
  // examples of printing
  print<2>();
  print<7>();
  print<77>();
  return 0;
}

/*
2
7
77
*/
