/* Operator Overloading */

#include<bits/stdc++.h>
using namespace std;

class Point
{
	int x;
	int y;
	
	public:
	Point(int x = 0, int y = 0): x(x), y(y) {}
	Point operator + (const Point &rhs) 
	{
		Point p;
		p.x = x + rhs.x;
		p.y = y + rhs.y;
		return p;
	}
	Point operator - (const Point &rhs) 
	{
		Point p;
		p.x = x - rhs.x;
		p.y = y - rhs.y;
		return p;
	}
	Point operator - () {
		return Point(-x, -y);
	}
	void Print()
	{
		cout << "x: " << x << " y: " << y << endl;
	}
};

int main()
{
	Point p1(1,2), p2(3, 4);
	Point p3 = p1+p2;
	Point p4 = p2-p1;
	
	p3.Print();
	p4.Print();
	
	Point p5 = -p1;  /* Unary Operator */
	p5.Print();
	
	return 0;
}

