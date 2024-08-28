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
	//cin >> t;

	while(t--)
	{
		int d1, v1, d2, v2, k;
        cin >> d1 >> v1 >> d2 >> v2 >> k;
        
        int s = 0, i = 1;
        while(s < k)
        {
            if(i >= d1) s += v1;
            if(i >= d2) s += v2;

            i++;
        }

        cout<<i-1<<"\n";
	}

	return 0;
}