// 0206exception.cpp -- exception handling

#include <iostream>
using namespace std;

const int NULL_ERROR   = 0; // division by zero error
const int TOO_LOW_ERROR   = 1; // Definition of 'Too low number' error
const int TOO_HIGH_ERROR  = 2; // Definition of 'Too high number' error

// throw error if 'i' is smaller than 0 or greater than 10, otherwise '10/i' is calculated and stored in 'i'.
void compute1(int i) {
  if (i==0) throw NULL_ERROR;
  if (i<0) throw TOO_LOW_ERROR;
  if (i>10) throw TOO_HIGH_ERROR;
  i=10/i;
  cout << "Result: " << i << endl;
}

void test1(int i) {
  try {
    compute1(i);
  }
  // catch the exception if previously (in the body of try) an exception was thrown (only catches exception object with int type)
  catch (int ex) {
    cout << "Exception: (" << ex << ") ";
    // print out an error message depending on the exception
    if (ex==NULL_ERROR) cout << "Value is zero.";
    if (ex==TOO_LOW_ERROR) cout << "Value too low.";
    if (ex==TOO_HIGH_ERROR) cout << "Value too high.";
    cout << endl;
  }
  // catches all other exceptions
  catch (...) {
    cout << "Unhandled exception." << endl;
  }
}

// define new exception classes
class cNULL_ERROR {};
class cTOO_LOW_ERROR {};
class cTOO_HIGH_ERROR {};

// similar to Compute1
void compute2(int i) {
  if (i==0) throw cNULL_ERROR();
  if (i<0) throw cTOO_LOW_ERROR();
  if (i>10) throw cTOO_HIGH_ERROR();
  i=10/i;
  cout << "Result: " << i << endl;
}

// similar to Compute2
void test2(int i) {
  try {
    compute2(i);
  }
  catch (cNULL_ERROR) {
    cout << "Exception: " << "Value is zero." << endl;
  }
  catch (cTOO_LOW_ERROR) {
    cout << "Exception: " << "Value too low." << endl;
  }
  catch (cTOO_HIGH_ERROR) {
    cout << "Exception: " << "Value too high." << endl;
  }
  catch (...) {
    cout << "Unhandled exception." << endl;
  }
}

int main(int argc, char *argv[]) {
  cout << "Test1" << endl;
  test1(1);
  test1(-1);
  test1(11);
  test1(0);
  cout << endl;

  cout << "Test2" << endl;
  test2(1);
  test2(-1);
  test2(11);
  test2(0);
  cout << endl;

  return 0;
}

/*
Test1
Result: 10
Exception: (1) Value too low.
Exception: (2) Value too high.
Exception: (0) Value is zero.

Test2
Result: 10
Exception: Value too low.
Exception: Value too high.
Exception: Value is zero.
*/
