#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
    T *data;
    int size;
    int capacity;

public:
Stack(int n): data(new T[1]), size(0),capacity(n){}

~Stack(){
    delete[] data;
}

int getSize(){
    return size;
}

void push(const T &e){
    cout << "Addd"<< endl;
        cout << "size"<< size <<endl;
        cout << "capacity"<< capacity <<endl;

    if(size == capacity){
        T* copy = new T[capacity*2];
        for(int i =0; i <= capacity ; i++){
            copy[i]=data[i]; 
        }
        delete[] data;
        data = 
        ;
        capacity= capacity*2;
    }
    data[size++]=e;
}
T pop(){
    return data[--size];
}

};


class A {
    string s;
public:
A(){}
A(string s):s(s){}
    friend ostream& operator<<(ostream &o,const A &a){
        return o << a.s;
    }

};

int main(){
    Stack<string> stack(2);//  = new Stack<string>(2);
    stack.push("Holita");
        stack.push("Holita");
            stack.push("Holita");
                stack.push("Holita");
                    stack.push("Holita");
                        stack.push("Holita");
                            stack.push("Holita");

                            for(int i =0; i< stack.getSize()  ; i++){
                                cout << stack.pop() << endl;

                            }

}