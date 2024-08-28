#include<iostream>
using namespace std;

int main()
{
	int const i = 9;
	cout << i << "\n";
	const_cast<int&>(i) = 6;	/* cast away constness of data */
	
	int j = 6;
	
	const int *p1 = &i;			/* data is const, pointer is not */
	p1++;
	
	int* const p2 = &j;			/* pointer is const, data is not */
	(*p2)++;
	
	//const int* const p3;		/* data and pointer are both const */
	
	int const *p4 = &i;			/* data is const */
	const int *p5 = &i;			/* data is const */
	
	return 0;
}
