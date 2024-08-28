#include<bits/stdc++.h>
using namespace std;

class YouTubeChannel {

	string Name;
	string OwnerName;
	int subscriberCount;
	
	public:
	
	YouTubeChannel(string Name, string ownerName, int subscriberCount = 0) 
	{
		this->Name = Name;
		this->OwnerName = ownerName;
		this->subscriberCount = subscriberCount;
	}
	
	void GetInfo()
	{
		cout << "Name: " << Name << "\n";
		cout << "OwnerName: " << OwnerName << "\n";
		cout << "Subscribers : " << subscriberCount << "\n";
	}
	
	void Subscribe() {
		subscriberCount++;
	}
	
	void Unsubscribe() {
		(subscriberCount > 0) ? subscriberCount-- : 0;
	}
};

int main()
{
	YouTubeChannel yt("xyz", "abc");
	
	yt.Subscribe();
	yt.Subscribe();
	yt.Subscribe();
	
	yt.GetInfo();
	yt.Unsubscribe();
	yt.GetInfo();
	
	return 0;
}
