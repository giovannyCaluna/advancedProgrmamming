// 0203shape.cpp -- virtual, pure virtual, protected
#include <iostream>
using namespace std;

class Shape1 {
public:
  virtual void draw() {} ; // virtual (interface for derived classes)
};

class Shape1a : public Shape1 {
public:
  void draw() {cout << "Shape1a::Draw" << endl;} // virtual
};

class Shape2 { // abstract class (has at least 1 pure virtual method)
public:
  virtual void draw()=0; // mark pure virtual methods with '=0'
};

class Shape2a : public Shape2 {
public:
  void draw() {cout << "Shape2a::Draw" << endl;} // virtual
};

class Shape3 {
protected:
  void draw1() { // protected (outside the class only derived classes can access)
    cout << "Shape3::Draw1" << endl;
  }
public:
  void draw2() { // public, everybody can access
    cout << "Shape3::Draw2" << endl;
  }
};

class Shape3a : public Shape3 {
public:
  void draw() {
    cout << "Shape3a::Draw" << endl;
    draw1(); // from derived class Draw1() can be invoked
  }
};

int main(int argc, char *argv[]) {
  Shape1 s1;
//  Shape2 s2; // ERROR: abstract class
  Shape1a s1a;
  s1a.draw();
  Shape2a s2a;
  s2a.draw();
  Shape3 s3;
//  s3.draw1(); // ERROR: Draw1 is protected
  s3.draw2();
  Shape3a s3a;
  s3a.draw();

  return 0;
}

/*
Shape1a::Draw
Shape2a::Draw
Shape3::Draw2
Shape3a::Draw
Shape3::Draw1
*/
