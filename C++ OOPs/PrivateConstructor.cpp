/*
	Whenever we want to control destruction of objects of a class, we make the destructor private. For dynamically 
	created objects, it may happen that you pass a pointer to the object to a function and the function deletes the 
	object. If the object is referred after the function call, the reference will become dangling.
	
*/

#include<iostream>
using namespace std;

class Admin
{
	string name;
	int age;
	 
	Admin() 
	{
		this->name = "xyz";
		this->age = 20;
	}
	
	public:
	void showData()
	{
		cout << "Name : " << name << "\n";
		cout << "Age : " << age << "\n";
	}
	static Admin* getData()
	{
		Admin *ptr = new Admin();
		return ptr;
	}
};

int main()
{
	Admin *ptr;
	
	ptr = Admin::getData();
	ptr->showData();
	
	return 0;
}
