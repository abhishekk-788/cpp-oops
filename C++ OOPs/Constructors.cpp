#include<iostream>
using namespace std;

class Test
{
	public:
	
	Test();
	Test(int);
	Test(Test&);
	~Test();
};

Test::Test()
{
	cout<<"Default Constructor\n";
}
Test::Test(int i)
{
	cout<<"Parameterized Constructor\n";
}
Test::Test(Test &t)
{
	cout<<"Copy Constructor\n";
}
Test::~Test()
{
	cout<<"Destructor\n";
}
void fun1(Test t)
{
	cout<<"Function fun\n";
}
void fun2(Test &t)
{
	cout<<"Function fun\n";
}
int main()
{
	Test t1;
	fun1(t1); // Call by value, copy constructor will be called to copy object to formal argument
	Test t2;
	fun2(t2); // Call by reference, no copy of object is happening
	return 0;
}
