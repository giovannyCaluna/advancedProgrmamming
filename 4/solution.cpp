#include <iostream>
using namespace std;

template<int N>
void print() {
  cout << N << endl;
}
template<>
void print<1>() {
  cout << "one" << endl;
}
template<>
void print<2>() {
  cout << "two" << endl;
}
template<>
void print<3>() {
  cout << "three" << endl;
}
//...four, five, six...
template<>
void print<7>() {
  cout << "seven" << endl;
}
//...eight, nine, ten

//---------------------------------------------------------
class Date {
  int year, month, day;
public:
  Date(int y, int m, int d) : year(y), month(m), day(d) {}
  bool operator<(const Date &d) {return day < d.day;}
  friend ostream& operator<<(ostream &o, const Date &d) {
    return o << d.year << "." << d.month << "." << d.day;
  }
};

template <class T, int N>
void bubblesort(T a[]) {
	bool switched;
	do {
		switched=false;
		for (int i=0; i<N-1; ++i) {
			if (a[i+1] < a[i]) {
				T tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
		  		switched=true;
			}
		}
	} while (switched);
}

int main() {
  print<2>();
  print<7>();
  print<77>();
//---------------------------------------------------------
  const int size = 6;
  Date array[] = {
  	Date(2018,10,8),
  	Date(2018,10,5),
  	Date(2018,10,1),
  	Date(2018,10,9),
  	Date(2018,10,7),
  	Date(2018,10,2),
  };
  cout << "--unsorted:--" << endl;
  for (int i=0; i<size; ++i)
    cout << array[i] << endl;
  bubblesort<Date,size>(array);
  cout << "--sorted:--" << endl;
  for (int i=0; i<size; ++i)
    cout << array[i] << endl;
}




