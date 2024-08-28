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

		vector<int> v(n+1);
		
        for (int i = 1; i <= n; i++)
        {
            v[i] = i;
        }

        for(int i = 1; i <= n; i=i+2)
        {
            v[i] = -v[i];
            k--;

            if(k == 0) break;
        }

        if(k != 0)
        {
            int x = (n % 2 == 1) ? (n-1) : n;
            for(int i = x; i >= 0; i = i-2)
            {
                v[i] = -v[i];
                k--;

                if(k == 0) break;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
	}

	return 0;
}