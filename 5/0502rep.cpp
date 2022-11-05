// Stream effector
#include <iostream>
using namespace std;

// Stream effector: similarly to manipulators, these are also used for
// modifying the streams, but these can get parameter(s) as well.
// For this, we have to use a class instead of a function.
class rep {
  // Data fields, which store the values of the parameters of the constructor.
  char chr;
  int cnt;
public:
  // The constructor makes it possible to parameterise the effector.
  // We store the values of the parameters so that we can access them later.
  rep(char chr, int cnt) : chr(chr), cnt(cnt) {}
  // The function to manipulate the stream. (Not a member of the class,
  // only a friend!) It handles what happens when we write an already created
  // and initialised (with the constructor) object to a stream.
  // The example does not manipulate the stream, it only writes characters
  // into it.
  friend ostream& operator<<(ostream &os, const rep &r){
    for (int i = 0; i < r.cnt; ++i)
      os << r.chr;
    return os;
  }
};

int main() {
  // Here we use the effector. Looks like there is a function call and we write
  // its result to the stream, but we only create an object.
  // This object will be written to the stream. The << operator implements
  // what happens.
  cout << "something" << rep(' ',33) << "something" << endl;
  return 0;
}
