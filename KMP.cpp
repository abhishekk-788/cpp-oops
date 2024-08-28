#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

vi v;

int32_t main()
{
	#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	#endif

    ios::sync_with_stdio(0), cin.tie(0);
    
    int m, n;
	string text, pattern;
	
	cin >> m >> n;
	vector<int> arr(n); 
	
	cin>>text;
	cin>>pattern;
	
	int index = 0, i = 1, j = 0;
	while(i < pattern.length())
	{
	    if(pattern[i] == pattern[index])
	    {
	        arr[i] = index + 1;
	        index++;
	        
	        i++;
	    }
	    else
	    {
	        if(index!=0)
	        {
	            index = arr[index-1];
	        }
	        else
	        {
	            arr[i] = 0;
	            i++;
	        }
	    }
	}
	i = 0, j = 0;
	while(i < text.length() && j < pattern.length())
	{
	    if(text[i] == pattern[j])
	    {
	        i++;
	        j++;
	    }
	    else
	    {
	        if(j!=0){
	            j = arr[j-1];
	        }
	        else i++;
	    }
	}
	if(j == pattern.length()){
	    cout<<"YES"<<endl;
	}
	else
	{
	    cout<<"NO"<<endl;
	}
	return 0;
}