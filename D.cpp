#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define f first
#define s second
#define pb push_back
#define mod 1000000007
#define inf LLONG_MAX

#define precise(x) cout << fixed << setprecision(7) << x << "\n";

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

unordered_map<int, vi> G;
bool vis[100005];

vector<int> vec;

bool dfs(int s)
{
	vis[s] = 1;
	if(G[s].size() == 0) return true;
	
	bool f = true;
	if(s == 1) f = false;
	
	for(auto u: G[s])
	{
		if(!vis[u])
		{
			f = f & dfs(u);
		}
	}
	
	if(f == true)
	{
		vec.push_back(G[s].size());
	}
	return false;
}
void solve()
{
	memset(vis, 0, sizeof(vis));
	
	G.clear();
	vec.clear();
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		
		G[x].pb(y);
		G[y].pb(x);
	}
	
	
	dfs(1);
	sort(vec.begin(), vec.end(), greater<int> ());
	
	int i = 0, j = 0;
	while(j < vec.size())
	{
		int x = vec[j];
		if(j + x < vec.size());
		{
			i++;
			j++;	
		}	
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
    cin >> t;

    while(z <= t)
    {
        //cout<<"Case #"<< z <<": ";
        solve();
        z++;
    }
    return 0;
}

