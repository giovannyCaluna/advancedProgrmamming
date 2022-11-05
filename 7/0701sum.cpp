// Template metaprogramming
#include <iostream>
using namespace std;

template<int N>
struct sum {
  static const int val = N + sum<N-1>::val;
};

template<>
struct sum<0> {
  static const int val = 0;
};

int main() {
  cout << "sum(10) == " << sum<10>::val << endl;
  return 0;
}
