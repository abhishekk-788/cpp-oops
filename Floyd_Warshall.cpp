#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ull unsigned long long
#define ld long double
 
#define f first
#define s second
#define pb push_back
#define mod 1000000007
#define inf 1000000000000
 
#define precise(x) cout << fixed << setprecision(7) << x << "\n";
 
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

ll dist[505][505];

void bellman_ford(ll n)
{
	for(ll k = 1; k <= n; k++)
	{
    	for(ll i = 1; i <= n; i++)
		{
        	for(ll j = 1; j <= n; j++)
			{
            	if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                	dist[i][j] = dist[i][k] + dist[k][j];
                }
	        }
	    }
	}	
} 
 
void solve()
{
	for(ll i = 0; i < 505; i++)
	{
	    for(ll j = 0; j < 505; j++)
	    {
	    	dist[i][i] = 0;
	        dist[i][j] = inf;
	    }
	}
    
	ll n, m, q;
    cin >> n >> m >> q;
    
    for(ll i = 0; i < m; i++)
    {
    	ll x, y, z;
    	cin >> x >> y >> z;
    	
    	dist[x][y] = min(dist[x][y], z);
    	dist[y][x] = min(dist[y][x], z);
	}
	
	bellman_ford(n);
	
	while(q--)
	{
		ll x, y;
		cin >> x >> y;
		
		ll ans = (dist[x][y] >= inf) ? -1: dist[x][y];
		cout << ans << "\n";
	}
}
 
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ios::sync_with_stdio(0), cin.tie(0);
 
    ll t = 1, z = 1;
    //cin >> t;
 
    while(z <= t) 
    {
        //cout<<"Case #"<< z <<": ";
        solve();
        z++;
    }
    return 0;
}
