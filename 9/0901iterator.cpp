// Iterator
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

// vector template, which implements an inner iterator class
template<class T, long N>
class Vector {
  T data[N];
public:
  // iterator inner class, the proper methods have to the implemented
  class iterator {
  public:
    iterator() : _p(nullptr) {} // default constructor
    iterator(const iterator &it) : _p(it._p) {}  // copy constructor
    T& operator*() {return *_p;}  // dereference
    T* operator->() {return _p;}
    iterator& operator++() {++_p; return *this;}  // prefix increment
    iterator operator++(int) {iterator temp(*this); ++_p; return temp;}  // postfix increment
    bool operator==(const iterator &it) {return _p == it._p;}  // logical equal
    bool operator!=(const iterator &it) {return _p != it._p;}  // logical not equal
  private:
    iterator(T *p) : _p(p) {}  // private constructor, which sets the iterator to a given element
    T *_p;                     // the elements referred to by the iterator
    friend class Vector<T,N>;  // making Vector friend, so that it can access the private constructor
  };

  iterator begin() {return iterator(data);}  // creating an iterator, which points to the first element of the vector
  iterator end() {return iterator(data + N);}  // creating an iterator, which points to the "element" after the last element of the vector

  // index operators
  T operator[](long i) const {return data[i];}
  T& operator[](long i) {return data[i];}
};

// initialize the vector with random values
template<class T, long N>
void init(Vector<T,N>& v) {
  for (auto it = v.begin(); it != v.end(); ++it)
    *it = rand() % 100;
  /*for (auto &it : v)
    it = rand() % 100;*/
}

// print the elements of a vektor to the console
template<class T, long N>
void print(string s, Vector<T,N>& v) {
  cout << s;
  for (auto it = v.begin(); it != v.end(); ++it)
    cout << setw(4) << *it;
  /*for (const auto &it : v)
    cout << setw(4) << it;*/
  cout << endl;
}

int main() {
  srand(time(0));

  Vector<int,5> v;
  init(v);
  print("v=", v);

  return 0;
}
/*
v=  34  50  75  76  44
*/
