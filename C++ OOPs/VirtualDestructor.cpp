/* 
	Deleting a derived class object using a pointer of base class type that has a non-virtual 
	destructor results in undefined behavior.
	
	Making base class destructor virtual guarantees that the object of derived class is destructed 
	properly, i.e., both base class and derived class destructors are called.
	
	When something is created using dynamic memory allocation, it is programmer’s responsibility 
	to delete it. So compiler doesn’t bother.
	
*/

#include<iostream>
using namespace std;

class Base
{
	public:
	virtual void fun()
	{
		cout << "Base fun\n";
	}
	Base()
	{
		cout << "Base Constructor\n";
	}
	virtual ~Base()
	{
		cout << "Base Destructor\n";
	}
};

class Derived: public Base
{
	public: 
	virtual void fun()
	{
		cout << "Derived fun\n";
	}
	Derived()
	{
		cout << "Derived Constructor\n";
	}
	~Derived()
	{
		cout << "Derived Destructor\n";
	}
};

int main()
{
	Base *b1 = new Base();
	Base *b2 = new Derived();
	
	delete b1;
	delete b2;
	
	return 0;
}
