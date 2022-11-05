// Traits : code pages
#include <iostream>
#include <string>
using namespace std;

// Charsets
class Hun {
public:
  string list() {return "aábcdeéfghiíjklmnoóöõpqrstuúüûvwxyz";}
};

class Eng {
public:
  string list() {return "abcdefghijklmnopqrstuvwxyz";}
};

// Date formats
class YMD {
public:
  string format() {return "YMD";}
};

class DMY {
public:
  string format() {return "DMY";}
};

// Code pages
class CP852 {
public:
  string name() {return "Hungarian";}
};

class CP437 {
public:
  string name() {return "English";}
};

// Languages
template<class> class LangTraits;

template<> class LangTraits <CP852> {
public:
  typedef Hun charset_type;
  typedef YMD date_type;
};

template<> class LangTraits <CP437> {
public:
  typedef Eng charset_type;
  typedef DMY date_type;
};

// String
template<class Lang, class Traits=LangTraits<Lang>>
class String {
  typedef typename Traits::charset_type charset_type;
  typedef typename Traits::date_type date_type;
  Lang lang;
  string text;
  charset_type charset;
  date_type date;
public:
  String(string t) : text(t) {}
  void info() {
    cout << "Text: " << text << endl
         << "Code page: " << lang.name() << endl
         << "Charset: " << charset.list() << endl
         << "Date format: " << date.format() << endl << endl;
  }

  bool operator<(String<Lang> s) {
    int i=0;
    int t1=text.length();
    int t2=s.text.length();
    int min = t1<t2 ? t1 : t2;

    while (text[i]==s.text[i] && i<min) i++;
    if (i==min) return t1<t2;

    int l=charset.list().length();
    int l1=l;
    int l2=l;
    for (int j=0; j<l; j++)
      if (text[i]==charset.list()[j]) {
        l1=j;
        break;
      }
    for (int j=0; j<l; j++)
      if (s.text[i]==charset.list()[j]) {
        l2=j;
        break;
      }
    return l1<l2;
  }
  
  friend ostream& operator<<(ostream &os, const String<Lang> &s){
    return os << s.text;
  }
};

int main() {
  String<CP852> st1("épület");
  //String<CP437> st1("épület");
  st1.info();

  String<CP852> st2("házikó");
  //String<CP437> st2("házikó");
  st2.info();

  cout << "Smaller: ";
  if (st1<st2)
    cout << st1;
  else
    cout << st2;
  cout << endl;
  return 0;
}

/*
Text: épület
Code page: Hungarian
Charset: aábcdeéfghiíjklmnoóöõpqrstuúüûvwxyz
Date format: YMD

Text: házikó
Code page: Hungarian
Charset: aábcdeéfghiíjklmnoóöõpqrstuúüûvwxyz
Date format: YMD

Smaller: épület
*/
