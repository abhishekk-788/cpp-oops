#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a = 5;
	int b = a;
	
	b = 10;
	cout<<a<<" "<<b<<"\n";
	
	int &c = a;
	c = 10;
	cout<<a<<" "<<c<<"\n";
	
	return 0;
}
