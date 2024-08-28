#include<bits/stdc++.h>
using namespace std;

class Dummy
{
	private:
	int a, b;
	
	const int x;
	int &y;
	
	public: 
	Dummy(int &n): x(5), y(n) {}
};

int main()
{
	int p = 6;
	Dummy d1(p);
}
