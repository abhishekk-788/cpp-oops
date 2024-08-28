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

int maxN;

int lca[200001][20];
int level[200001];

int LCA(int a, int b)
{
    if(level[b] < level[a]) swap(a, b);
    int d = level[b] - level[a];
    
    while(d > 0)
    {
        int i = log2(d);
        b = lca[b][i];
        d = d - (1 << i);
    }
    
    if(a == b) return a;
    for(int i = maxN-1; i >= 0; i--)
    {
        if(lca[a][i] != -1 && lca[a][i] != lca[b][i])
        {
            a = lca[a][i], b = lca[b][i]; 
        }
    }
    return lca[a][0];
}

void dfs(int root, int root_level, int root_parent)
{
    level[root] = root_level;
    lca[root][0] = root_parent;

    for(int i = 1; i <= maxN; i++)
    {
        if(lca[root][i-1] != -1) {
            lca[root][i] = lca[lca[root][i-1]][i-1];
        }
        else lca[root][i] = -1; 
    }
    
    for(int child : G[root])
    {
        if(child != root_parent)
        {
            dfs(child, root_level + 1, root) ;
        }
    }
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    int n;
    cin >> n;
    
    maxN = log2(n);
    
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        
        G[x].push_back(y);
        G[y].push_back(x);
    }

    memset(lca, -1, sizeof(lca));
    dfs(1, 1, -1);
    
    int query;
    cin >> query;
    
    while(query--)
    {
        int x, y;
        cin >> x >> y;
        
        cout<<LCA(x, y)<<"\n";
    }
    
    return 0;
}