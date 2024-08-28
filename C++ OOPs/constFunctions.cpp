#include<iostream>
using namespace std;

class Dog 
{
	int age;
	string name;
	
	public: 
	Dog() 
	{
		age = 3; 
		name = "dummmy"; 
	}
	
	/* const parameters */
	void setAge(const int &a) {
		cout << "const Parameter\n";
		age = a; 
	}
	void setAge(int &a) {
		cout << "non-const Parameter\n";
		age = a; 
	}
	
	/* const return value */
	const string& getName() {
		return name;
	}
	
	/* Cannot change any member variable and cannot call a non-const function*/
	void printDogName() const {			
		cout << name << " const" << endl;	
	}
	
	void printDogName() {			
		cout << name << " non-const" << endl;	
	}
};

int main()
{
	Dog d;
	const Dog d1;
	
	const int i = 9;
	d.setAge(i);
	
	int j = 9;
	d.setAge(j);
	
	const string& str = d.getName();
	cout << str << "\n";
	
	d.printDogName();
	d1.printDogName();
	
	return 0;
}
