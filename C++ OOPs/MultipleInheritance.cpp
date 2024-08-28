#include<bits/stdc++.h>
using namespace std;

class A
{
	public:
	A() {
		cout << "A class\n";
	};
	
	void X() {
		cout << "X fn of A class\n";	 
	}
};

class B
{
	public:
	B() {
		cout << "B class\n";
	};
	
	void X() {
		cout << "X fn of B class\n";	 
	}
};

class C: public A, public B
{
	public:
	C(): A(), B() { cout << "C class\n"; }
};

int main()
{
	C c;
	c.A::X();
	
	A a = c;
	a.X();
	
	static_cast<B>(c).X();
	
	return 0;
}
