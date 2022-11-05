// 0205nevter.cpp -- namespaces

#include <iostream>

namespace X { // X namespace
  int i=0;
  int j=0;
  int k=0;
}

int k=1; //global variable -> global namespace

int main(int argc, char *argv[]) {
 // int i=1;
//j++; // ERROR: j is undefined
  using namespace X;
  i++; std::cout << "i = " << i << std::endl; //local variable i
  j++; std::cout << "j = " << j << std::endl; //variable j declared in namespace X
//  k++; // ERROR: k is ambiguous
  ::k++; std::cout << "::k = " << ::k << std::endl; //:: global k (access global namespace by using ::)
  X::k++; std::cout << "X::k = " << X::k << std::endl; //variable k declared in namespace X

  return 0;
}

/*
i = 2
j = 1
::k = 2
X::k = 1
*/
