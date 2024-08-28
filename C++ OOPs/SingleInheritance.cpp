#include<bits/stdc++.h>
using namespace std;

class A  
{  
	public: 
	
    int a = 4;  
    int b = 5;  
     
    int mul()  
    {  
        int c = a*b;  
        return c;  
    }     
};  
  
class B : public A  
{  
    public:  
    void display()  
    {  
        int result = mul();  
        std::cout <<"Multiplication of a and b is : "<<result<< std::endl;  
    }  
};  
int main()  
{  
   B b;  
   b.display();  
  
    return 0;  
}  
