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

/* C(n, k) = n! / (k! * (n-k)!) */

ll F[1000001];
void factorial()
{
	F[0] = F[1] = 1;
	for(int i = 2; i <= 1000000; i++)
	{
		F[i] = (F[i-1] * 1LL * i) % mod;
	}
}

ll power(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n % 2) res = (res * 1LL * a) % mod;

		n /= 2;
		a = (a * 1LL * a) % mod;
	}
	return res;
}

ll nCr(ll n, ll k)
{
	if(k > n || n < 0 || k < 0) return 0LL;
	
	ll res = F[n] % mod;
	
	res = (res * 1LL * power(F[k], mod-2)) % mod;
	res = (res * 1LL * power(F[n-k], mod-2)) % mod;

	return res;
}
void solve()
{
	factorial();

    ll n, k;
    cin >> n >> k;

    cout << nCr(n-1, k-1) << "\n";
}


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    ll t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}