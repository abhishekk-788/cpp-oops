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

/* Disjoint Set DataStructure */
ll par[100005], size[100005];

void make_set() 
{
	for(int i = 0; i < 100000; i++)
	{
    	par[i] = i;
    	size[i] = 1;
    }
}

ll find_set(ll v) 
{
    if (v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_set(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);

    if (a != b) 
    {
        if (size[a] < size[b]) swap(a, b);
        
        par[b] = a;
        size[a]++;
    }
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
        int n, m;
        cin >> n >> m;

        vector<pair<int, pair<int, int>>> Graph;
        for(int i = 0; i < m; i++)
        {
        	int x, y, w;
        	cin >> x >> y >> w;

        	Graph.push_back({w, {x, y}});
        }

        int mst_weight = 0, mst_edges = 0, i = 0;
        make_set();

        sort(Graph.begin(), Graph.end());

        while(mst_edges < n-1 && i < m)
        {
        	int x = Graph[i].second.first;
        	int y = Graph[i].second.second;
        	int w = Graph[i].first;


        	if(find_set(x) != find_set(y))
        	{
        		union_set(x, y);

        		mst_weight += w;
        		mst_edges++;
        	}
        	i++;
        }
        cout<<mst_weight<<"\n";
    }
    return 0;
}