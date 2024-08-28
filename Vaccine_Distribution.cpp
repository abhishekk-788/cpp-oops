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
		int n, d;
		cin >> n >> d;

		vector<int> v(n);
		
        for (int i = 0; i < n; i++)
			cin >> v[i];

        int cnt = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] <= 9 || v[i] >= 80) cnt++;
        }

        ll x = ceil(1.0 *cnt / d);
        ll y = ceil(1.0 * (n-cnt) / d);

        cout<<x+y<<"\n";
	}

	return 0;
}