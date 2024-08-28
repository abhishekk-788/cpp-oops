// Pure Virtual Function
//
// SYNTAX: virtual returntype functionname(parameters...) = 0;
//
// NOTES:
// 0. If some class can have only signature of function but not the body then we use pure virtual functions.
// 1. Sometimes in Base class we know the function name but not the definition of the function, so we want Derived classes to provide the definition of the function.
// 2. We can actually give body of pure virtual function.
// 3. If you have pure virtual function in your class, it means that class is an Abstract class and you can't create an object of that class. (But pointers and Reference can be created)
//
// USE CASE:
// 1. Used to create abstract classes, which helps in creating interfaces (APIs)

#include<bits/stdc++.h>
using namespace std;

class Animal {
public:
	virtual void move() = 0;
};

class Cow: public Animal {
public:
	void move() {
		cout<<"Walk and Run\n";
	}
};

class Snake: public Animal{
public:
	void hello(){
		cout << "Hello\n";
	}
};

int main() {
	Snake c = new Snake();
	c.hello();
	return 0;
}
