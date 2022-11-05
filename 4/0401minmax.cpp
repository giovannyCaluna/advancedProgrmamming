// Function templates
#include <iostream>
#include <string>
using namespace std;

// template function which sorts the values of the parameters so that 'a' parameter becomes the smaller and 'b' the larger
template<class T>
void minmax(T &a, T &b) {
  // switch if needed
  if (a > b) {
    T temp = b;
    b = a;
    a = temp;
  }
}

class A {
  string s;
public:
  A() {}
  A(string s) : s(s) {}
  bool operator>(const A &a) {return s > a.s;}
  friend ostream& operator<<(ostream &o, const A &a) {
    return o << a.s;
  }
};

int main() {
  // 1. example, when there is no need to switch
  int x = 2;
  int y = 7;
  minmax<int>(x,y);
  cout << x << "<" << y << endl;

  // 2. example, when the values have to be switched + automatic type deduction
  int z = 7;
  int w = 2;
  minmax(z,w);
  cout << z << "<" << w << endl;

  // 3. example, with non-primitive type
  A a1("six");
  A a2("two");
  minmax(a1,a2);
  cout << a1 << "<" << a2 << endl;  // six < two lexicographically

  return 0;
}

/*
2<7
2<7
six<two
*/
