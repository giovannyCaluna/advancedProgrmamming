// exercise.cpp
// Task: Implement the methods and operators declared in IntSet.
//       Handle exceptions where possible.

#include <iostream>
using namespace std;

class Set {
protected:
  int max_item_count; // maximum number of items to be stored
  int item_count; // actual number of elements stored
public:
  virtual void clear() = 0; //removes all item from the set (resets values to zero)
  virtual void print() = 0; //prints the value of all item
  virtual int average() = 0; //the avg. of the contained items
};

class IntSet : public Set {
  int *item;
public:
  //constructor, maximum size of the set is given in parameter
   IntSet(int max) {
    item_count=0;
    max_item_count=max;
    item=new int[max_item_count];
  }

  //adds a new item
  IntSet operator+=(int i) {return *this;}
  //union of two set (result in 'this' set)
  IntSet operator+=(IntSet s) {return *this;}
  //assigns a set as value to a set
  IntSet operator=(IntSet s) {return *this;}
  //checks whether two sets are equal
  bool operator==(IntSet s) {return true;}
  //removes all item from the set (resets values to zero)
  void clear() {};
  //prints the value of all item
  void print() {cout << "Items: " << endl;}
  //the avg. of the contained items
  int average() {return 0;}
};

//calculate the avg. of the union of s1 and s2
void compute(IntSet s1, IntSet s2) {
  IntSet s3(10);
  s3=s1;
  s3+=s2;
  cout << "Average " << s3.average() << endl;
};

int main(int argc, char *argv[]) {
  IntSet iset1(10);
  for (int i=0; i<=7; i++) iset1+=i;
  iset1.print();

  IntSet iset2(10);
  for (int i=0; i<=7; i++) iset2+=10+i;
  iset2.print();

  IntSet iset3(0);
  iset3.print();

  compute(iset3, iset3);
  compute(iset3, iset1);
  compute(iset1, iset2);

  return 0;
}
