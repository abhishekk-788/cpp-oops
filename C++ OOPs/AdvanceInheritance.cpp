#include<bits/stdc++.h>
using namespace std;

class B 
{
	public:
	void f_pub() { cout << "f_pub is called.\n"; }
	
	protected:
	void f_prot() { cout << "f_prot is called.\n"; }
		
	private:
	void f_priv() { cout << "f_priv is called.\n"; }
};

class D_priv : private B
{
	public:
	void f() 
	{
		f_pub();      /* Ok, D_priv's private fn */
		f_prot();     /* Ok, D_priv's private fn */
		f_priv();     /* Error, B's is private */
	}
};

class D_prot : protected B
{
	public:
	void f() 
	{
		f_pub();      /* Ok, D_prot's protected fn */
		f_prot();     /* Ok, D_prot's protected fn */
		f_priv();     /* Error, B's is private */
	}
};

class D_pub : public B
{
	public:
	void f() 
	{
		f_pub();      /* Ok, D_pub's public fn */
		f_prot();     /* Ok, D_pub's protected fn */
		f_priv();     /* Error, B's is private */
	}
};


int main()
{
	D_pub D1;       
	D1.f_pub();      /* Ok, f_pub() is D_pub's public fn */
	
	D_prot D2;
	D2.f_pub();      /* Error, f_pub() is D_prot's protected fn */
}
