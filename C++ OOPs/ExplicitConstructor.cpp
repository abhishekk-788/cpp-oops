#include<bits/stdc++.h>
using namespace std;

class Base {
	int var;
	
	public:
	Base() 
	{
		/* Default Constructor */
	}
	explicit Base(int var)
	{
		/* Parameterised Constructor */
		this->var = var;
	}
	
	void print()
	{
		cout << var << "\n";
 	}
};

void fun(Base b)
{
	b.print();
}

int main()
{
	Base b1(10);
	Base b2 = 20;  // error
	
	fun(b2);
	fun(30);       // error
	
	return 0;
}
