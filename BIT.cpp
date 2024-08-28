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

vi bit, v;

ll lsb(ll index)
{
	return (index & (-index));
}

ll get_sum(ll x)
{
	ll sum = 0;
	while(x != 0)
	{
		sum += bit[x];
		x -= lsb(x);
	}
	return sum;
}

void update_BIT(ll node_idx, ll n, ll val)
{
	while(node_idx <= n)
	{
		bit[node_idx] += val;
		node_idx += lsb(node_idx);
	}
}

void create_BIT(vector<ll> &p, ll n)
{
	for(int i = 1; i <= n; i++)
	{
		bit[i] = 0;
	}

	for(int i = 1; i <= n; i++)
	{
		update_BIT(i, n, p[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		cout<<bit[i]<<" ";
	}
	cout<<"\n";
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    ll t = 1;

    while(t--)
    {
        ll n;
        cin >> n;

        v.resize(n+1);
        bit.resize(n+1);

        for(int i = 1; i <= n; i++)
        {
        	cin >> v[i];
        }

        create_BIT(v, n);

        int q;
        cin >> q;

        while(q--)
        {
        	int x, y;
        	cin >> x >> y;

        	cout<<get_sum(y) - get_sum(x-1)<<"\n";
        }

    }
    return 0;
}