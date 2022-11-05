// Traits technique
#include <iostream>
#include <string>
using namespace std;

// Foodstuff
class Water {
public:
  string name() {return "water";}
};

class Milk {
public:
  string name() {return "milk";}
};

class Honey {
public:
  string name() {return "honey";}
};

class Cookie {
public:
  string name() {return "cookie";}
};

// Guests
class Bear {
public:
  string name() {return "Winnie-the-Pooh";}
};

class Boy {
public:
  string name() {return "Christopher Robin";}
};

// Primary traits template
template<class Guest>
class GuestTraits;

// Specialised traits
template<>
class GuestTraits<Bear> {
public:
  typedef Water drink_type;
  typedef Honey food_type;
};

template<>
class GuestTraits<Boy> {
public:
  typedef Milk drink_type;
  typedef Cookie food_type;
};

// Restaurant
template<class Guest, class traits = GuestTraits<Guest>>
class Restaurant {
  typedef typename traits::drink_type drink_type;
  typedef typename traits::food_type food_type;
  Guest guest;
  drink_type drink;
  food_type food;
public:
  Restaurant(const Guest &g) : guest(g) {}
  void regale() {
    cout << "We regale " << guest.name() << " with "
         << drink.name() << " and "
         << food.name() << endl;
  }
};

// Main program
int main() {
    Boy cr;
    Restaurant<Boy> r1(cr);
    r1.regale();

    Bear wtp;
    Restaurant<Bear> r2(wtp);
    r2.regale();

    return 0;
}

/*
We regale Christopher Robin with milk and cookie
We regale Winnie-the-Pooh with water and honey
*/
