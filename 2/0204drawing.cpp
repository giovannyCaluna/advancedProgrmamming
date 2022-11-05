// 0204rajzteszt.cpp -- operation overriding
#include <iostream>
using namespace std;

// Shape: base class
class Shape {
public:
  virtual void draw(); // without virtual no override is done in derived classes
};

class Triangle : public Shape {
public:
  virtual void draw();
};

class Square : public Shape {
public:
  virtual void draw();
};

void Shape::draw()   {cout << "Shape" << endl;}
void Triangle::draw() {cout << "Triangle" << endl;}
void Square::draw()   {cout << "Square" << endl;}

void doIt(Shape &s) {
  s.draw(); // late binding (dynamic binding)
}

int main(int argc, char *argv[]) {
  Triangle t;
  Square s;
  doIt(t);
  doIt(s);

  return 0;
}

/*
Triangle
Square
*/
