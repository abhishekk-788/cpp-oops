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

/* ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); } */

/* Graph

map<ll, vector<ll>> G;

void dfs(int s, int p)
{
	for(auto *itr = G[s].begin(); itr != G[s].end(); itr++)
	{
		if(*itr != p)
		{
			dfs(*itr, s);
		}
	}
}

vector<int> bfs(int s, bool vis[], int N)
{
    queue<int> q;
	vector<int> res;

    q.push(s);
	res.push_back(s);
	
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        
        if(vis[t] == false)
        {
            res.push_back(t);
            for(auto i = G[t].begin(); i != G[t].end(); i++)
            {
                q.push(*i);
            }
            vis[t] = true;
        }
    }
	return res;
}


vi Topological(int n)
{
	vi degree(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (auto itr = G[i].begin(); itr != G[i].end(); itr++)
		{
			degree[*itr]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++)
	{
		if (cnt[i] == 0)
			q.push(i);
	}

	vi r(n);
	ll k = 0;
	while (!q.empty())
	{
		ll p = q.front();
		q.pop();
		r[k++] = p;

		for (auto itr = G[p].begin(); itr != G[p].end(); itr++)
		{
			degree[*itr]--;
			if (degre[*itr] == 0)
				q.push(*itr);
		}
	}
	return r;
}

void Graph()
{
	ll n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		ll x, y;
		cin >> x >> y;

		Graph[x].PB(y);
		Graph[y].PB(x);
	}
}
*/

vi input;

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	ll t;
	t = 1;
	cin >> t;

	for (int z = 1; z <= t; z++)
	{
		ll n;
		cin >> n;

		input.resize(n);

		for (int i = 0; i < n; i++)
		{
			cin >> input[i];
		}

		int ans = ;
		printf("Case #%d: %d", z, ans);
	}
	return 0;
}
