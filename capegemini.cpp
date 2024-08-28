#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin >> n; 
	
	vector<int> vec(n);
	for(int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	
	double s = 0.0;
	unordered_map<int, int> mp;
	
	int mode = 0, ans = 0;
	for(int i = 0; i < n; i++)
	{
		s += vec[i];
		mp[vec[i]]++;
		
		if(mp[vec[i]] > ans)
		{
			ans = mp[vec[i]];
			mode = vec[i];
		}
		if(mp[vec[i]] == ans)
		{
			ans = mp[vec[i]];
			mode = min(mode, vec[i]);
		}
	}
	
	double md;
	if(n % 2 == 1)
	{
		md = vec[n/2];
	}
	else 
	{
		md = vec[n/2] + vec[n/2 + 1];	
	}
	
	cout << fixed;
    cout << setprecision(6) << s;
    cout << setprecision(6) << md;
    cout << mode;
	
	
	return 0;
}
