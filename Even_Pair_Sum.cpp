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
		ll a, b;
        cin >> a >> b;

        ll xe = a/2;
        ll xo = (a+1)/2;

        ll ye = b/2;
        ll yo = (b+1)/2;

        ll ans = (xe*ye) + (xo*yo);
        cout<<ans<<"\n";
	}

	return 0;
}