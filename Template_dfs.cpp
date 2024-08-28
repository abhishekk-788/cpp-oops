#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double

#define pb push_back
#define mod 1000000007
#define precise(x) cout << fixed << setprecision(7) << x << "\n";
 
map<int, vector<int>> mp;
 
ld ans = 0.0;
 
void dfs(int u, int v, ld p, int cnt)
{
	int child = 0;
	for (auto i = mp[u].begin(); i != mp[u].end(); i++)
	{
		if (*i != v)
			child++;
	}
 
	for (auto i = mp[u].begin(); i != mp[u].end(); i++)
	{
		if (*i != v)
			dfs(*i, u, p / child, cnt + 1);
	}
 
	if (child == 0)
		ans += p * cnt;
}
 
int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0);
 
	ll n;
	cin >> n;
 
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
 
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
 
	dfs(1, 1, 1.0, 0);
	precise(ans);
 
	return 0;
}