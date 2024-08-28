#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define F first
#define S second
#define PB push_back
#define mod 1000000007

typedef pair<ll, ll> pi;

vector<vector<pi>> Graph; 
void prims(ll s, int n)
{
	priority_queue<pi, vector<pi>, greater<pi>> q;
 	q.push({0, s});

 	vector<bool> vis(n+1, false);
 	int mn_cost = 0;
 	
 	while(!q.empty()) 
	{
	    pi item = q.top();
	    
	    q.pop();

	    ll cost = item.F;
	    ll node = item.S;

	    if(vis[node] == false)
	    {
	    	mn_cost += cost;
	    	vis[node] = true;

	    	for(auto &itr : Graph[node])
	    	{
	    		if(vis[itr.F] == false)
	    		{
	    		    item = {itr.S, itr.F};
	    			q.push(item);
	    		}
	    	}
	    }
	}
	cout<<mn_cost<<"\n";
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    int n, e;
    cin >> n >> e;

    Graph.resize(n+1);

    for(int i = 0; i < e; i++)
    {
		int s, d, w;
		cin >> s >> d >> w;

		Graph[s].PB({d, w});
		Graph[d].PB({s, w});
	}

	prims(1, n);
    
    return 0;
}