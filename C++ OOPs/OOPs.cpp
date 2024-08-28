#include<bits/stdc++.h>
using namespace std;

class Person
{
	public: 
	
	int age;
	string name;

	static int count2;
	 
    Person()    
    {    
        cout<<"Default Constructor Invoked"<<endl;   
		count2++; 
    } 
};

int Person::count2 = 0;
int main()
{ 	
	Person p1;
	Person *p2 = new Person();
	
	cout<<p1->count2<<"\n";
	return 0;
}
