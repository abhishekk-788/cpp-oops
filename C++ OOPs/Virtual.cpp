// 1. Why to use virtual function?
//   a. To achieve dynamic polymorphism. Which is the ability to call Derived class function using Base class pointer or reference.


// 2. How to use virtual function?
//   a. By declaring function as virtual in Base class and overriding that function in Derived class.
//      (Function signature should be same in Base and Dervied class)
//   b. Declaring a function as virtual in Base class is enough, Derived class function need not to be declared virtual.
//   c. Virtual functions should be accessed using pointer(*) or reference(&) of Base class type to achieve run time polymorphism.


// ADITIONAL NOTES:
// 1. Virtual functions cannot be static and also cannot be a friend function of another class.
// 2. A class can have virtual destructor but can't have virtual constructor.
// 3. There are two types of virtual functions in C++.
//   a. Virtual Function
//   b. Pure Virtual Function

#include<bits/stdc++.h>
using namespace std;

class Base {
public: 
	virtual void func() {
		cout<<"Base class\n";
	}
};

class Derived : public Base {
public: 
	void func() {
		cout<<"Derived class\n";
	}
};

int main()
{
	Base *b = new Derived();
	b->func();
}
