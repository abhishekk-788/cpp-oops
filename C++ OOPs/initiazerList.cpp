#include<bits/stdc++.h>
using namespace std;

class Base
{
	int x; 
	int y;
	
	public: 
	
	Base(int a, int b) : x(a), y(b) {}
	void print()
	{
		cout<<x<<" "<<y<<"\n";
	}
};

int main()
{
	Base b(10, 20);
	b.print();
	
	return 0;
}

/*
    Constructors And Member Initializer Lists C++
    This is used to initialize data members of classes.

   Two ways are there to do this.
     1. Using {}  this is uniform initialization and should be prefered.
     2. Using ()  
     
   // Link : https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/   
   
   1) For initializing non-static const members, we require initializer list.
      Ex, const int x; 
   
   2) For initializing reference type variables, we require initializer list.
      Ex, int &x;
     
   3) For initializing one class data member in another class if first class 
      doesn't have default constructor, we need initializer list.
   
     Ex, 
     class One {
        int xx;
        public:
        	One(int x) : xx(x) {}
 	 };
 	 
 	 class Two {
 	   One a;
 	   public:
			Two(One x) : a(x) {}
     };
     
   4) For initialization of base class members, the parameterized constructor of the 
      base class can only be called using Initializer List.
    
     Ex,
     class Base {
		int x;
		
		public:
		Base(int x): x(x) {}
	 };	   
	 
	 class Child: public Base {
	   int y;
	   
	   public: 
	   Child(int a, int b) : Base(a), y(b) {}
	 };
   
*/
