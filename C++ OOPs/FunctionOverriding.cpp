/* Polymorphism */

/* Polymorphism  ---> Compile Time (Function Overloading, Operator Overloading)
				 ---> RunTime Time (Function Overriding)
				 
	
	Virtual Functions : There is a necessity to use the single pointer to refer to all the objects of the different classes. 
	So, we create the pointer to the base class that refers to all the derived objects. But, when base class pointer contains 
	the address of the derived class object, always executes the base class function. This issue can only be resolved by using 
	the 'virtual' function.
*/

#include<bits/stdc++.h>
using namespace std;

class Base
{
	public:
	virtual void fun()
	{
		cout << "Base\n";
	}
};

class Derived : public Base
{
	public:
	void fun()
	{
		cout << "Derived\n";
	}
};

int main()
{
	Base b, *p;
	Derived d;
	
	p = &b;
	p->fun();
	
	p = &d;
	p->fun();
	
	return 0;
}
