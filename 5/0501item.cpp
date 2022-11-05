// Stream manipulator
#include <iostream>
using namespace std;

// Stream manipulator: a function, which gets an ostream reference as
// parameter and returns the same ostream reference.
// Manipulates the stream settings (thus its name), it cannot have parameters.

// This example does not alter the stream, it only writes an
// increasing number to it.
ostream& item(ostream &os) {
  static int cnt = 1;
  return os << cnt++;
}

int main() {
  // We use the manipulator here: we "write" the function to the stream.
  // For calling the function, there is an overloaded << operator in the STL.
  cout << item << ". element" << endl;
  cout << item << ". element" << endl;
  cout << item << ". element" << endl;
  return 0;
}
