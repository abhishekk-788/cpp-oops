#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 1000000007

#define pb push_back
#define F first
#define S second
#define precise(x) cout << fixed << setprecision(7) << x << "\n";

typedef vector<ll> vi;
typedef pair<ll, ll> pi;

ll GCD(ll a, ll b) return b == 0 ? a : GCD(b, a % b); 

vi input;
int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t = 1;
	cin >> t;

	for (int z = 1; z <= t; z++)
	{
		cout<<"Case "<<z<<": ";
		
		ll n;
		cin >> n;

		input.resize(n);

		for (int i = 0; i < n; i++)
		{
			cin >> input[i];
		}

		int ans = 0;
		//printf("Case #%d: %d", z, ans);
		
		cout<<ans<<"\n";
	}

	return 0;
}