#include <string>
#include <iostream>

using namespace std;

class Date {
    private: string name;
    private: 
    int year, month, day;
    public:
    Date(): year(1996), month(9), day(10) {};

    Date(int y, int m, int d): year(y), month(m), day(d) {};

    ~Date(){}

    int getYear(){
        return year;
    }
      int getDay() {return day;}
    void print(){
        cout << "Im  Giovanny and my bithday is on " << year <<"/" << month << "-" << day << endl;
    }
  Date operator++(int) {Date tmp=*this; day++; return tmp;}

};
int main (int argc, char *argv[]){
    Date gioBirthday(1996,2,1);
    gioBirthday.print();
    gioBirthday.operator++(5);
    gioBirthday.print();
    cout << gioBirthday.getDay(); ;

}
