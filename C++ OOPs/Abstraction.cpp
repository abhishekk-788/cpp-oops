#include<bits/stdc++.h>
using namespace std;

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

struct Student 
{
	int age;
	string name;
};
  
int main()  
{ 
    implementAbstraction *obj = new implementAbstraction(); 
    obj->set(10, 20); 
    obj->display(); 
    return 0; 
} 
