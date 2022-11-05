// 0202fonok.cpp -- inheritance
#include <iostream>
#include <string>

using namespace std;

//Employee class
class Employee {
  string name; //field storing the name of the employee.
  string address; //field storing the address of the employee.
  int    salary;
public:
  //default konstruktor
  Employee() : name(""),address(""),salary(0){}

  //destruktor
  ~Employee() {
    name = "";
    address = "";
  }

  void set_personal_info(string n, string a, int s) {
    name    = n;
    address = a;
    salary  = s;
  }
  string getName()    {return name;}    // returns the name of the employee
  string getAddress() {return address;} // returns the address of the employee
  int    getSalary()  {return salary;}  // returns the salary of the employee
};

//Leader class. A Leader is an Employee, but has a post.
class Leader : public Employee {
private:
  string  post; //stores the post of a leader
public:
  //default constructor
  Leader() : post("") {}

  //destructor
  ~Leader() {
      post = "";
  }

  void set_personal_info(string n, string a, int s, string p) {
    Employee::set_personal_info(n,a,s); //name, date, salary fields are set by using set_personal_info of the base class
    post = p;
  }
  string getPost() {return post;} //returns the post of the leader
};

int main(int argc, char *argv[]) {
  //create a new employee object on the heap
  Employee *emp = new Employee();
  emp->set_personal_info("David Foo","Szeged",150000);
  cout << "Employee: " << emp->getName() << " " << emp->getAddress() << " " << emp->getSalary() << endl;

  //create a new leader object on the heap
  Leader *leader = new Leader();
  leader->set_personal_info("Stephen Bar","Szeged",250000,"Leader");
  cout << "Leader: " << leader->getName() << " " << leader->getAddress() << " " << leader->getSalary() <<" " << leader->getPost() << endl;

  Employee *gio = new Employee();
  Employee gio2;
  gio2.set_personal_info("gioxo","",789);
  gio -> set_personal_info("gio", "calu", 122);
 
    cout << "Employee: " << gio2.getName() << " " << gio -> getAddress() << " " << gio -> getSalary() << endl;


  delete emp;
  delete leader;

  return 0;
}

/*
Employee:   David Foo   Szeged  150000
Leader:     Stephen Bar Szeged  250000  Leader
*/
