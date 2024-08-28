/* Polymorphism */

/* Polymorphism  ---> Compile Time (Function Overloading, Operator Overloading)
				 ---> RunTime Time (Function Overriding)
				 
	
	Virtual Functions : There is a necessity to use the single pointer to refer to all the objects of the different classes. 
	So, we create the pointer to the base class that refers to all the derived objects. But, when base class pointer contains 
	the address of the derived class object, always executes the base class function. This issue can only be resolved by using 
	the 'virtual' function.
*/

#include<bits/stdc++.h>
using namespace std;

class YouTubeChannel {

	string Name;
	int subscriberCount;
	
	protected:
	string OwnerName;
	
	
	public:
	YouTubeChannel(string Name, string ownerName) 
	{
		this->Name = Name;
		this->OwnerName = ownerName;
		this->subscriberCount = 0;
	}
	
	void GetInfo()
	{
		cout << "Name: " << Name << "\n";
		cout << "OwnerName: " << OwnerName << "\n";
		cout << "Subscribers : " << subscriberCount << "\n\n";
	}
	
	void Subscribe() {
		subscriberCount++;
	}
	
	void Unsubscribe() {
		(subscriberCount > 0) ? subscriberCount-- : 0;
	}
};

class CookingYouTubeChannel: public YouTubeChannel 
{
	public: 
	CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {}
	
	void Practice()
	{
		cout << OwnerName << "Recipes" << "\n";
	}
};

class SingersYouTubeChannel: public YouTubeChannel 
{
	public: 
	SingersYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {}
	void Practice() {
		cout << OwnerName << "Music Albums" << "\n";
	}
};

int main()
{
	CookingYouTubeChannel cookingytc("Amy's Kitchen", "Amy");
	SingersYouTubeChannel singersytc("Ganna", "John");
	
	cookingytc.Subscribe();
	cookingytc.Subscribe();
	cookingytc.Subscribe();
	
	singersytc.Subscribe();
	
	YouTubeChannel *yt1;
	yt1 = &cookingytc;
	yt1->GetInfo();
	
	yt1 = &singersytc;
	yt1->GetInfo();
	
	return 0;
}
