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

unordered_map<int, vector<int>> G;
int vis[100005], stk[100005];
stack<int> st;

bool dfs(int s)
{
	vis[s] = 1;
	stk[s] = 1;
	for(auto itr: G[s])
	{
		if(stk[itr] && vis[itr]) return true;
		else if(!vis[itr] && dfs(itr)) return true;
	}
	
	stk[s] = 0;
	st.push(s);
	
	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		
		G[x].pb(y);
	}
	
	int f = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) 
		{
			if(dfs(i))
			{
				f = 1;
				break;
			}
		}
	}
	
	if(f == 1)
	{
		cout << "IMPOSSIBLE";
		return;
	}
	
	vector<int> ans;
	while(!st.empty())
	{
		ans.pb(st.top());
		st.pop();
	}
	
	for(auto v: ans) cout << v << " ";
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

