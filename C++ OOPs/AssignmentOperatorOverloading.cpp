/* Assignment Operator Overloading */

#include<bits/stdc++.h>
using namespace std;

class Test
{
	int *x;
	
	public: 
	Test(int val = 0): x(new int(val)) {}
	
	void setX(int val) {
		*x = val;
	}
	
	void print() {
		cout << "OUTPUT: " << *x << endl;
	}
	
	~Test() { delete x; }
	
	Test &operator = (const Test &rhs) {
		if(this != &rhs) *x = *rhs.x;
		return *this;
	}
};
int main()
{
	Test t1(10);
	Test t2, t3;
	
	t2 = t1;		/* Both pointers are pointing to same address */
	t1.setX(20);
	
	t1.print();		// 20
	t2.print();     // 10
	
	(t2 = t1) = t3;
	
	t1.print();
	t2.print();
	t3.print();
	
	return 0;
}
