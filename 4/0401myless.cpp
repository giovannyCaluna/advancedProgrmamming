// Function templates
#include <iostream>
using namespace std;

template<class T>
bool myless(const T &a, const T &b) {
  return a < b;
}

int main() {
  long x = 2;
  double y = 5.0;
  //if (myless(x,y)) // automatic type deduction does not work in this case
  if (myless<double>(x,y))
    cout << "smaller" << endl;
  else
    cout << "larger" << endl;
  return 0;
}
