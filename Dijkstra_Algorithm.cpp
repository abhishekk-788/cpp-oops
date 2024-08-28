#include<bits/stdc++.h>
using namespace std;

int dijsktra(int n, int src, int dest, vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(n+1, INT_MAX);
    set<pair<int, int>> s;
    
    dist[src] = 0;
    s. insert({0, src});
    
    while(!s.empty())
    {
        auto p = *(s.begin());
        
        int curr = p.second;
        int curr_dist = p.first;
        
        s.erase(s.begin());
        
        for(auto i : adj[curr])
        {
            if(curr_dist + i.second < dist[i.first]) 
            {
                int d = i.first;
                auto f = s.find({dist[d], d});
                
                if(f != s.end()) s.erase(f);
                
                dist[d] = curr_dist + i.second;
                s.insert({dist[d], d});    
            }
        }
    }
    return dist[dest]; 
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

	vector<vector<pair<int, int>>> adj(n+1);

	int x, y, w;
	for(int i = 0; i < e; i++)
	{
		cin>> x >> y >> w;
		
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	
	int q;
	cin >> q;

	while(q--)
	{
		int src, dest; 
		cin >> src >> dest;
		
		cout<<dijsktra(n, src, dest, adj)<<"\n";
	}

	return 0;
}