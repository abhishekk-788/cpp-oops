#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define mod 1000000007

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--)
	{
		int n, k;
		cin >> n >> k;

        while(1)
        {
            if(n == 0) break;
            cout<<"a";
            n--;
            if(n == 0) break;
            cout<<"b";
            n--;
            if(n == 0) break;
            cout<<"c";
            n--;
        }
        cout<<"\n";
	}

	return 0;
}