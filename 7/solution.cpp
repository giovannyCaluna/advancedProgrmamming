#include <iostream>
using namespace std;
/* Implement a template(s), which determines at compile time if a number is a prime.
  (prime<N>::val == true <=> for all M [2..N/2]: N % M != 0)*/

template<int N, int M = N/2>
struct prime {
	static const bool val = (N % M != 0) ? prime<N,M-1>::val : false;
	//static const bool val = (N % M != 0) && prime<N,M-1>::val;  //alternative
};
template<int N>
struct prime<N,1> {
	static const bool val = true;
};
template<>
struct prime<1> {
	static const bool val = false;
};
template<>
struct prime<0> {
	static const bool val = false;
};

// Write a template metaprogram, that calculates the n-th Fibonacci number
//In mathematics, the Fibonacci numbers, commonly denoted Fn , form a sequence,
//the Fibonacci sequence, in which each number is the sum of the two preceding ones. 
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
template<int N>
struct fib {
	static const int val = fib<N-1>::val + fib<N-2>::val;
};
template<>
struct fib<1> {
	static const int val = 1;
};
template<>
struct fib<0> {
	static const int val = 0;
};

int main() {
  cout << fib<0>::val << endl;  // 0
  cout << fib<1>::val << endl;  // 1
  cout << fib<2>::val << endl;  // 1
  cout << fib<3>::val << endl;  // 2
  cout << fib<4>::val << endl;  // 3
  cout << fib<5>::val << endl;  // 5
  cout << fib<6>::val << endl;  // 8
  cout << fib<7>::val << endl;  // 13
  cout << fib<8>::val << endl;  // 21
  cout << fib<9>::val << endl;  // 34


  cout << "prime(0) == " << prime<0>::val << endl;  // 0
  cout << "prime(1) == " << prime<1>::val << endl;  // 0
  cout << "prime(2) == " << prime<2>::val << endl;  // 1
  cout << "prime(3) == " << prime<3>::val << endl;  // 1
  cout << "prime(4) == " << prime<4>::val << endl;  // 0
  cout << "prime(5) == " << prime<5>::val << endl;  // 1
  cout << "prime(6) == " << prime<6>::val << endl;  // 0
  cout << "prime(7) == " << prime<7>::val << endl;  // 1
  cout << "prime(8) == " << prime<8>::val << endl;  // 0
  cout << "prime(9) == " << prime<9>::val << endl;  // 0
  cout << "prime(10) == " << prime<10>::val << endl;  // 0
  cout << "prime(11) == " << prime<11>::val << endl;  // 1
  cout << "prime(12) == " << prime<12>::val << endl;  // 0
  cout << "prime(13) == " << prime<13>::val << endl;  // 1

  return 0;
}
