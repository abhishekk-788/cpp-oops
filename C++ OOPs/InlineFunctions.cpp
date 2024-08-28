/* Inline Functions */
 
/*
	If a function is inline, the compiler places a copy of the code of that function at each 
	point where the function is called at compile time.
	
	Syntax : inline return-type function-name(parameters) {
				// function code
			}
			
	Normally, a function call transfers the control from the calling program to the called function. 
	This process of jumping to the function, saving registers, passing a value to the argument, and 
	returning the value to the calling function takes extra time and memory.
	
	An inline function is a function that is expanded inline when it is invoked, thus saving time. 
	The compiler replaces the function call with the corresponding function code, which reduces the 
	overhead of function calls.
	
	
	When an inline function is called, the compiler replaces all the calling statements with the func-
	tion definition at run-time. Every time an inline function is called, the compiler generates a copy 
	of the function’s code, in place, to avoid the function call.
	
	Advantages of using inline functions
	------------------------------------
	
	Inline functions speed up your program by avoiding the overhead associated with function calls.
	Inline functions save the overhead of pushing and popping variables on the stack during function calls.
	Inline functions save the overhead of the return call from a function.
	
*/
#include<iostream>
using namespace std;

inline int sum(int a, int b)
{
	return (a + b);
}
int main()
{
	cout << sum(4, 5) << "\n";
	return 0;
}
