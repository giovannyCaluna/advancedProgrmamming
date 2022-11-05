#include <iostream>
using namespace std;
    
namespace X {
    int i=0;
    int j=0;
    int k=0;
}


class Shape{
    public:
        virtual void draw();
    
};
class Triangle: public  Shape{
    public:
        virtual void draw();
};
void Shape::draw()   {cout << "Shape" << endl;}

    void Triangle::draw(){   
        cout<<"Gio, you did it";
    };

void letsDraw(Shape &s){
    int a = 5;
    try{
        s.draw(); // late binding (dynamic binding)
        throw a;
    }catch (int i){
        cout << "El rror encontrado es :"<< i;
    }
  
}
void doIt(Shape &s) {
  s.draw(); // late binding (dynamic binding)
}

int main(){
    using namespace X;
    cout << X::i << endl;
    Triangle triangle;

   letsDraw(triangle);
   //doIt(triangle);
     
}