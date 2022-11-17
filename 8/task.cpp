#include <iostream>
#include <sstream>
#include <string>


using namespace std;

//for each task, place your solutions after the //WORK HERE! comments

//to test the first task uncomment the #  define TEMPLATE_VECTOR_INTERVAL line
//and so on
#ifndef TEST_BIRO
#  define TEMPLATE_VECTOR_INTERVAL
#  define TEMPLATE_COUNT_ELEMENT
#  define MANIPULATOR_ANONYM
#  define EFFECTOR_EXCHANGE
#  define TRAITS_CAKE
#endif // TEST_BIRO



#ifdef TEMPLATE_VECTOR_INTERVAL

//WORK HERE!
template<unsigned MIN, unsigned MAX>
class IntervalVector {
	unsigned arr[MAX-MIN+1] = {0};
public:
	IntervalVector operator+=(unsigned new_element) {
		if (new_element < MIN || new_element > MAX) {
			throw new_element;
		}
		arr[new_element - MIN]++;
		return *this;
	}
	unsigned& operator[](unsigned elem) {
		if (elem < MIN || elem > MAX) {
			throw elem;
		}
		return arr[elem - MIN];
	}
	unsigned operator[](unsigned elem) const {
		if (elem < MIN || elem > MAX) {
			throw elem;
		}
		return arr[elem - MIN];
	}
	friend ostream& operator<<(ostream& os, const IntervalVector& iv) {
		for (unsigned i=MIN;i<=MAX;++i) {
			os << i << ": " << iv.arr[i-MIN] << endl;
		}
	}
	IntervalVector operator+(const IntervalVector& o) const {
		IntervalVector result;
		for (unsigned i=MIN;i<=MAX;++i) {
			result.arr[i-MIN] = arr[i-MIN] + o.arr[i-MIN];
		}
		return result;
	}
};

// ----- test -----

#ifndef TEST_BIRO
void test_vector_interval() {
  IntervalVector<5, 7> asd, asd2;
	asd += 5;
	asd += 7;
	cout << asd;
	cout << "Number of 6:" << asd[6] << endl;
	cout << "----" << endl;

	asd2 += 5;
	cout << "Number of 5:" << asd[5] << endl;

	IntervalVector<5, 7> asd_sum = asd + asd2;
	cout << "Sum of two vectors:" << endl;
	cout << asd_sum;
  
}
#endif // TEST_BIRO
#endif // TEMPLATE_VECTOR_INTERVAL 


#ifdef TEMPLATE_COUNT_ELEMENT

//WORK HERE!
template<typename T, unsigned N, typename K=T>
unsigned count_element(T arr[N], K search) {
	unsigned sum=0;
	for (unsigned i=0;i<N;++i) {
		if (arr[i]==search){
			++sum;
		}
	}
	return sum;
}
template<>
unsigned count_element<std::string,5,char>(std::string arr[5], char search) {
	unsigned sum=0;
	for (unsigned i=0;i<5;++i) {
		for (unsigned j=0;j<arr[i].length();++j) {
			if (arr[i][j]==search){
				++sum;
			}
		}
	}
	return sum;
}

// ----- test -----
#ifndef TEST_BIRO
void test_count_element() {
  int arr[5] = {1,3,5,2,3};
  cout <<"Number of 3s: "<< count_element<int, 5>(arr, 3) << endl;
    
  string arr2[5] = {"asd", "bsd", "asda", "cccc", "aaa"};
  cout <<"Number of letter a: " << count_element<string, 5, char>(arr2, 'a') << endl;
}
#endif // TEST_BIRO
#endif // TEMPLATE_COUNT_ELEMENT


#ifdef MANIPULATOR_ANONYM

//WORK HERE!

stringstream ss;
streambuf *save;

ostream& anonym(ostream& os){
	static bool on = false;
	
	if (on) {
		on = false;
		string collected(ss.str());
		os.rdbuf(save);
		
		//TODO
		for (unsigned i=0;i<collected.length();++i) {
			collected[i] = '*';
		}
		
		os << collected;
	}
	else {
		on = true;
		ss.str("");
		save = os.rdbuf();
		os.rdbuf(ss.rdbuf());
	}
	
	return os;
}

// ----- test -----
#ifndef TEST_BIRO
void test_anonym() {
  cout << anonym << "Simon  Doyle is the murderer. " << anonym << "It was investigated by Hercule Poirot." << endl;
  cout << anonym;
  cout << "his last known location: the Nile" << anonym << endl;
}
#endif // TEST_BIRO
#endif // MANIPULATOR_ANONYM


#ifdef EFFECTOR_EXCHANGE

//WORK HERE!
class Exchange {
	unsigned money;
	string currency;
	const static unsigned rate = 425;
public:
	Exchange(unsigned money, const string& currency) : money(money), currency(currency) {
	}
	friend ostream& operator<<(ostream& os, const Exchange& ex) {
		if (ex.currency == "EUR") {
			os << Exchange::rate * ex.money << "HUF";
		}
		else if (ex.currency == "HUF") {
			os << ex.money / Exchange::rate << "EUR";
		}
		else {
			os << "ERROR";
		}
		return os;
	}
};


// ---------- Test ---------
#ifndef TEST_BIRO
void test_exchange() {
  cout << "Convert 100 EUR to HUF: " << Exchange(100, "EUR") << endl;
  cout << "Convert 800 HUF to EUR: " << Exchange(800, "HUF") << endl;
}
#endif // TEST_BIRO
#endif // EFFECTOR_EXCHANGE


#ifdef TRAITS_CAKE

using namespace std;

// Ingerdients
class Sugar {
public:
  unsigned energy() const {
    return 100;
  }
};

class BrownSugar {
public:
  unsigned energy() const {
    return 50;
  }
};

// Portion size
class FullPortion {
public:
  double size() const {
    return 1.0;
  }
};

class HalfPortion {
public:
  double size() const {
    return 0.5;
  }
};

//Persons
class Normal{
    string name;
public:
  Normal(const string& name):name(name){
  }
  string get_name() const{
      return name;
  }
};

class Dietary{
    string name;
public:
  Dietary(const string& name):name(name){   
  }
  string get_name() const{
      return name;
  }
};

template<typename P>
class PersonTraits;

template<>
class PersonTraits<Normal> {
public:
	typedef Sugar sugar_type;
	typedef FullPortion portion_size;
};
template<>
class PersonTraits<Dietary> {
public:
	typedef BrownSugar sugar_type;
	typedef HalfPortion portion_size;
};

template<typename Person, typename Traits = PersonTraits<Person>>
class PersonalizedCake {
	typedef typename Traits::sugar_type sugar_type;
	typedef typename Traits::portion_size portion_size;
	Person person;
	sugar_type sugar;
	portion_size portion;
public:
	PersonalizedCake(Person person) : person(person) {
	}
	friend ostream& operator<<(ostream& os, const PersonalizedCake& pc){
		os << pc.person.get_name();
		return os;
	}
	double calorie_intake() const {
		return sugar.energy() * portion.size();
	}
	template<typename P2, typename T2>
	bool operator>(const PersonalizedCake<P2,T2> o) const {
		return calorie_intake() > o.calorie_intake();
	}
};

//WORK HERE!

// ----- test -----

#ifndef TEST_BIRO
void test_cake() {
  Normal nn("Piglet");
  PersonalizedCake<Normal> cake_normal(nn);
  cout << "Normal cake calory intake: "<< cake_normal.calorie_intake() << endl;

  Dietary dd("Winnie the Pooh");
  PersonalizedCake<Dietary> cake_dietary(dd);
  cout << "Dietary cake calory intake: "<< cake_dietary.calorie_intake() << endl;

  if(cake_normal > cake_dietary){
   cout << "His cake has more calories: " << cake_normal << endl;
  }
}
#endif // TEST_BIRO
#endif // TRAITS_CAKE 

#ifndef TEST_BIRO
int main() {

#ifdef TEMPLATE_VECTOR_INTERVAL
  test_vector_interval();
#endif //TEMPLATE_VECTOR_INTERVAL

#ifdef TEMPLATE_COUNT_ELEMENT
  test_count_element();
#endif //TEMPLATE_COUNT_ELEMENT

#ifdef MANIPULATOR_ANONYM
  test_anonym();
#endif //MANIPULATOR_ANONYM

#ifdef EFFECTOR_EXCHANGE
  test_exchange();
#endif //EFFECTOR_EXCHANGE

#ifdef TRAITS_CAKE
  test_cake();
#endif //TRAITS_CAKE

return 0;
}
#endif // TEST_BIRO

