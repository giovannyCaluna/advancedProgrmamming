// 0201date.cpp -- create class, operator overloading
#include <string>
#include <iostream>
using namespace std;

//Date class
class Date {
private:
  int year, month, day; // year, month, day data fields
public:
  //default constructor
  Date() : year(1980), month(1), day(1) {}
  //constructor with parameters to set year, month, day based on the given parameters
  Date(int y, int m, int d) : year(y), month(m), day(d) {}
  //destructor
  ~Date() {}
  //Returns the year datafield of the date.
  int getYear() {return year;}
  //Returns the month datafield of the date.
  int getMonth() {return month;}
  //Returns the day datafield of the date.
  int getDay() {return day;}
  //sets the date by setting year, month, day datafields.
  void set(int y, int m, int d) {
    year=y; month=m; day=d;
  }
  //prints the actual values of the datafield members.
  void print() {
    cout << "Date:" << year << "." << month << "." << day << endl << endl;
  }
  //overloading prefix '++' operator for Date datatype. Simply increments the day field without check.
  Date operator++() {day++; return *this;}
  //overloading postfix '++' operator for Date datatype. Original value has to be preserved -> create a tmp and return it.
  //Ex: date++ will results the following call: date.operator++(0)
  Date operator++(int) {Date tmp=*this; day++; return tmp;}
  //operator+=  Ex: date+=3  -> increments the value of day by 3.
  Date operator+=(int n) {day+=n; return *this;}
  //two date objects are equal if and only if their data members are equal (year, month, day)
  bool operator==(Date d) {return (year==d.year && month==d.month && day==d.day);}
};

int main(int argc, char *argv[]) {
  //create a date object using default constructor. Object will be placed in the stack memory.
  Date begin;
  cout << "Date:" << begin.getYear() << "." << begin.getMonth() << "." << begin.getDay() << endl;
  cout << "set" << endl;
  //setting date
  begin.set(2000,9,10);
  begin.print();

  cout << "now" << endl;
  //create a date object using constructor with parameters
  Date now(2004,9,12);
  now.print();

  cout << "now++" << endl;
  //increment the value of day field by 1
  now++;
  now.print();

  cout << "now+=4" << endl;
  //increment the value of day field by 4
  now+=4;
  now.print();

  cout << "Other" << endl;
  Date other(2003,9,21);
  other.print();

  cout << "? now == other" << endl;
  //investigate whether the two date objects are equal
  if (other==now)
    cout << "Equal" << endl;
  else
    cout << "Not equal" << endl;

  return 0;
}

/*
Date: 1980.1.1
Set
Date: 2000.9.10

Now
Date: 2004.9.12

Now++
Date: 2004.9.13

Now+=4
Date: 2004.9.17

Other
Date: 2003.9.21

? Now==Other
Not equal
*/
