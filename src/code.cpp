#include <iostream>
using namespace std;

void unchanger(string n)									//pass by reference vs value
{
	n+= "modified";
}

void changer(string& n)
{
	n+= "modified";
}

int addition (int a, int b)									//method as arguement
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

int operation (int x, int y, int (*functocall)(int,int))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}

int incrementer(int i = 0)									//default values
{
	return ++i;
}

template <class SomeType>									//template method
SomeType sum (SomeType a, SomeType b)
{
  return a+b;
}

template <class T>											//template classes
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}


namespace name1												//namespaces
{
	string nameString = "name1";
	int nameTest()
	{
		return 23;
	}
}

namespace name2
{
	string nameString = "name2";
	int nameTest()
	{
		return 46;
	}
}

struct Currency												//structs and operator overloads
{
	string country;
	double usdConversion;
};

struct Product
{
	Currency c;
	double price;
	string name;

	Product operator+(const Product& p)
	{
		Product combo;
		combo.name = this->name + " and " + p.name;
		combo.price = this->price + p.price;
		return combo;
	}

	double usdPrice()
	{
		return price * c.usdConversion;
	}
};

int main()
{
	cout << "Hello World!" << endl << endl;					//syntax

	getchar();

	char a = 'a';											//pointers
	char* b = &a;
	char** c = &b;

	cout << (int)c << endl << (int)b << endl << a << endl << endl;

	getchar();

	int m,n;												//pointer to function
	int (*minus)(int,int) = subtraction;
	m = operation (7, 5, addition);
	n = operation (20, m, minus);
	cout << n << endl << endl;

	getchar();

	string x = "foo";										//pass by reference
	unchanger(x);
	cout << x << endl;
	changer(x);
	cout << x << endl << endl;

	getchar();

	cout << incrementer(2) << endl; 						//default values
	cout << incrementer() << endl << endl;

	getchar();

	cout << sum<int>(2, 3) << endl;							//template methods
	cout << sum<double>(2.8742845, 3.4398562398754) << endl;
	cout << sum<char>('a', 'b') << endl;
	cout << sum<string>("foo", "bar") << endl << endl;

	getchar();

	mypair <int> myobject (100, 75);						//template class
	cout << myobject.getmax()<< endl << endl;

 	getchar();

	cout << name1 :: nameString << endl;					//namespaces
	cout << name2 :: nameString << endl;
	cout << name1 :: nameTest() << endl;
	cout << name2 :: nameTest() << endl << endl;

	getchar();

	Currency rupee;											//structs
	rupee.country = "India";
	rupee.usdConversion = 0.0156042;

	Product shirt;
	shirt.name = "shirt";
	shirt.price = 1000;
	shirt.c = rupee;

	cout << shirt.price << endl;
	cout << shirt.usdPrice() << endl << endl;

	getchar();

	Product pants;											//operator overload
	pants.name = "pants";
	pants.price = 1500;
	pants.c = rupee;

	Product combo = shirt + pants;
	cout << combo.name << endl << combo.price << endl << endl;


}





