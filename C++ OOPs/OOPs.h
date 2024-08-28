===============================
C++ Object Oriented Programming
===============================

------------------
Structs vs Classes
------------------

-> Members of a class are private by default and members of a struct are public by default.
-> When deriving a struct from a class/struct, default access-specifier for a base class/struct is public. And 
   when deriving a class, default access specifier is private.
-> Structure objects are created on the stack memory whereas class objects are created on heap memory.
-> Structure doesn't support inheritance.
-> The member variable of structure cannot be initialized directly whereas variable of class can be initialized directly.

----------------
Reference in C++
----------------

Reference variables are alternative names for an existing variable. So when we declare a variable x = 10, a 
memory is allocated for it.

Ex,
int a = 5;   // memory got allocated
int b = a;   // memory again got allocated
int &c = a;  // No memory allocated, both a and c share same memory

So, reference variables are useful for saving memory. In functions too, reference variables are used so that
memory doesn't get allocated every time whenever function is called.


------------
Constructors
------------

If constructors are explicitly defined for a class, but they are all non-default, the compiler will not implicitly 
define a default constructor, leading to a situation where the class does not have a default constructor. 

class MyClass
{
	public:
    MyClass (int y);  // declaration a non-default constructor

	private:
    int x;
};

MyClass::MyClass (int y)
{
    x = y;
}

int main()
{
    MyClass m(100);     // the non-default constructor is called
    MyClass * p;        // for pointer declarations, the compiler does not need to know about constructors
    
	p = new MyClass();  // error at compilation: no default constructor
    return 0;
}



Copy Constructor
----------------

/* Link : https://www.javatpoint.com/cpp-copy-constructor */

A copy constructor is a member function which initializes an object using another object of the same class.If 
we don't define our own copy constructor, the C++ compiler creates a default copy constructor for each class 
which does a member-wise copy between objects.

Ex, Point p2 = p1;

The compiler created copy constructor does shallow copy (Call by reference).

Whenever an object is passed to a function by a value or returned from a function by value then there will be 
a call to copy constructor. To avoid the copy constructor  call use pass by reference.

-> It is very essential to pass objects as reference. If an object is passed as value to the Copy Constructor 
   then its copy constructor would call itself(call by value), to copy the actual parameter to the formal one. 
  
   Thus an endless chain of call to the copy constructor will be initiated. This process would go on untill the 
   system run out of memory (infinite loop).
   

-> Dynamic Constructor
-> Virtual Destructor
   
   
Destructor
----------

/* Link : https://www.geeksforgeeks.org/private-destructor/ */



-------------
Static in C++
-------------

/* Link : https://www.geeksforgeeks.org/static-keyword-cpp/ */

static variable : When a variable is declared as static, space for it gets allocated for the lifetime
of the program.

A static variable inside a class should be initialized explicitly by the user using the class name and 
scope resolution operator outside the class as shown.

class GfG 
{ 
public: 
    static int i; 
      
    GfG() 
    { 
        /* body */ 
    }; 
}; 
  
int GfG::i = 1;

Class objects as static - Just like variables, objects also when declared as static have scope till the 
lifetime of program.

class GfG 
{ 
    int i = 0; 
      
    public: 
    GfG() 
    { 
        i = 0; 
        cout << "Inside Constructor\n"; 
    } 
      
    ~GfG() 
    { 
        cout << "Inside Destructor\n"; 
    } 
}; 
  
int main() 
{ 
    int x = 0; 
    if (x==0) 
    { 
        static GfG obj; 
    } 
    cout << "End of main\n"; 
} 


Output:

  Inside  Constructor
  End of main
  Inside Destructor


Just like the static data members or static variables inside the class, static member functions also does 
not depend on object of class. 

static member function are allowed to invoke using the object and the '.' operator but it is recommended 
to invoke the static members using the class name and the scope resolution operator '::'.

class GfG 
{ 
   public: 
      
    /* static member function */ 
    static void printMsg() 
    { 
        cout<<"Welcome to GfG!"; 
    } 
}; 
  
int main() 
{ 
    /* invoking a static member function */ 
    GfG::printMsg(); 
} 

Static member functions are allowed to access only the static data members or other static member functions, 
they can not access the non-static data members or member functions of the class.


---------------
Friend Function
---------------

/* Link : https://www.javatpoint.com/cpp-friend-function */

If a function is defined as a friend function in C++, then the protected and private data of a class can 
be accessed using the function.

The function is not in the scope of the class to which it has been declared as a friend.
-> It cannot be called using the object as it is not in the scope of that class.
-> It can be invoked like a normal function without using the object.
-> It cannot access the member names directly and has to use an object name and dot membership operator with the member name.
-> It can be declared either in the private or the public part.


-----------------
Virtual Functions
-----------------

/* Link : https://www.javatpoint.com/cpp-virtual-function */

A virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class.

When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for 
that object and execute the derived class’s version of the function.

-> Virtual functions cannot be static.
-> A virtual function can be a friend function of another class.
-> Virtual functions should be accessed using pointer or reference of base class type to achieve run time polymorphism.
-> The prototype of virtual functions should be the same in the base as well as derived class.
-> They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to over-
   ride (or re-define the virtual function), in that case, the base class version of the function is used.
   
class Base {
public:
    virtual void print()
    {
        cout << "print base class" << endl;
    }
 
    void show()
    {
        cout << "show base class" << endl;
    }
};
 
class Derived : public Base {
public:
    void print()
    {
        cout << "print derived class" << endl;
    }
 
    void show()
    {
        cout << "show derived class" << endl;
    }
};
 
int main()
{
    Base* bptr;
    Derived d;
    
	bptr = &d;
 
    // virtual function, binded at runtime
    bptr->print();
 
    // Non-virtual function, binded at compile time
    bptr->show();
}

Output 
------
	
print derived class
show base class


----------
Interfaces
----------

/* Link : https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/ */

Abstraction can be achieved by two ways: Abstract class and Interface. Abstract class and interface both can have abstract 
methods which are necessary for abstraction.

-> C++ interfaces are implemented using abstract classes and a class is made abstract by declaring at least one of its functions 
   as pure virtual function.
   
   	#include<iostream> 
   	using namespace std; 
  
   	class Test 
	{ 
		int x; 
		public: 
    	virtual void show() = 0; 
    	int getX() { return x; } 
	}; 
  
	int main(void) 
	{ 
    	Test t; 	// Error, since Test is now a abstract class
    	return 0; 
	}
	
-> If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.

	#include<iostream> 
	using namespace std; 
	
	class Base 
	{ 
	public: 
	    virtual void show() = 0; 
	}; 
	  
	class Derived : public Base { }; 
	  
	int main(void) 
	{ 
	  Derived d;  // Error
	  return 0; 
	}	 
	

-----------
Inheritance
-----------

-> When the base class is privately inherited by the derived class, public members of the base class becomes the private 
   members of the derived class. Therefore, the public members of the base class are not accessible by the objects of the 
   derived class only by the member functions of the derived class.

-> When the base class is publicly inherited by the derived class, public members of the base class also become the public 
   members of the derived class. Therefore, the public members of the base class are accessible by the objects of the deri-
   ved class as well as by the member functions of the base class.
   
-> The member which is declared as protected will be accessible to all the member functions within the class as well as the 
   class immediately derived from it.
   
------------------------------------------------------------------    
| BASE CLASS | DERIVED CLASS     DERIVED CLASS    DERIVED CLASS  |
------------------------------------------------------------------
|            | Public MODE       Private MODE     Protected MODE |
------------------------------------------------------------------
| Private	 |  Not Inherited     Not Inherited    Not Inherited |
| Protected	 |	Protected         Private          Protected     |
| Public	 |	Public            Private          Protected     |
------------------------------------------------------------------


Ambiquity Resolution in Inheritance
-----------------------------------

-> Ambiguity can be occurred in using the multiple inheritance when a function with the same name occurs in more than one 
   base class.

class A  
{  
    public:  
    void display()  
    {  
        std::cout << "Class A" << std::endl;  
    }  
};  
class B  
{  
    public:  
    void display()  
    {  
        std::cout << "Class B" << std::endl;  
    }  
};  
class C : public A, public B  
{  
    void view()  
    {  
        display();  
    }  
};  
int main()  
{  
    C c;  
    c.display();  
    return 0;  
}  

-> The above issue can be resolved by using the class resolution operator with the function.

class C : public A, public B  
{  
    void view()  
    {  
        A :: display();         // Calling the display() function of class A.  
        B :: display();         // Calling the display() function of class B.  
  
    }  
};  


Multiple Inheritance
--------------------

/* Link : https://www.geeksforgeeks.org/multiple-inheritance-in-c/ */


Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.

class A 
{ 
public: 
  A()  { cout << "A's constructor called" << endl; } 
}; 
  
class B 
{ 
public: 
  B()  { cout << "B's constructor called" << endl; } 
}; 
  
class C: public B, public A  // Note the order 
{ 
public: 
  C()  { cout << "C's constructor called" << endl; } 
}; 
  
int main() 
{ 
    C c; 
    return 0; 
} 

Diamond Problem
---------------

-> The diamond problem occurs when two superclasses of a class have a common base class.

   class A {
		void display()
		{
			//some code
		}
	}
	 
	class B : public A{

	}
	 
	class C : public A{
		
	}
	 
	class D : public B, public C{
		
	}
	
	int main()
	{
		D d;
		d.display(); 	/* Ambiguous */
	}

-> In the above code class B has one instance of A class and class C also has one instance of 
   A class, so whenever we call display(), ambiguity occurs.

-> Since B and C both inherit from class A, two copies of class A are there in class D. This 
   kind of inheritance without virtual causes wastage of space and ambiguities. Virtual base 
   classes are used to save space and avoid ambiguities in such cases.
   

------------
Polymorphism
------------

/* Link : https://www.javatpoint.com/cpp-polymorphism */

/*
					Polymorphism
					/ 		\
			Compile Time    Run Time
				  /  \		   \
	Fn Overloading   Operator 	Virtual Functions
				   Overloading

*/

-> Compile time polymorphism: The overloaded functions are invoked by matching the type and number 
   of arguments. This information is available at the compile time and, therefore, compiler selects 
   the appropriate function at the compile time. It is achieved by function overloading and operator 
   overloading which is also known as static binding or early binding.
   
-> Run time polymorphism: Run time polymorphism is achieved when the object's method is invoked at 
   the run time instead of compile time. It is achieved by method overriding which is also known as 
   dynamic binding or late binding.
   
-> When you refer to a derived class object using a pointer or a reference to the base class, you can
   call a virtual function for that object and execute the derived class's version of the function.

-> Virtual functions ensure that the correct function is called for an object, regardless of the type 
   of reference (or pointer) used for function call.
   
 
 Function Overloading
 --------------------
 
 /* https://www.geeksforgeeks.org/function-overloading-in-c/  */
   

 Function Overriding
 -------------------

-> If derived class defines same function as defined in its base class, it is known as function over-
   riding in C++. It is used to achieve runtime polymorphism.
   
   class Animal 
   {  
		public:  
		void eat()
		{    
			cout<<"Eating...";    
		}      
	};   
	class Dog: public Animal    
	{    
		public:  
		void eat()    
		{    
			cout<<"Eating bread...";    
		}    
	};  
	
	int main() 
	{  
		Dog d = Dog();    
		d.eat();  
		return 0;  
	}  
	
	
---------------------------------
Abstraction and Virtual Functions
---------------------------------

/*  Link : https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/  */

In C++, abstraction can be implemented using classes (getters and setters) as well as header files. It can 
also be achieved using access specifier too.


class implementAbstraction 
{ 
    private: 
        int a, b; 
  
    public: 
      
        void set(int x, int y) 
        { 
            a = x; 
            b = y; 
        } 
          
        void display() 
        { 
            cout<<"a = " <<a << endl; 
            cout<<"b = " << b << endl; 
        } 
}; 
  
int main()  
{ 
    implementAbstraction obj; 
    obj.set(10, 20); 
    obj.display(); 
    return 0; 
} 