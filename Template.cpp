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



/* Segment Tree Data Structure */
ll a[100005], seg[4 * 100005];
 
void build(ll index, ll l, ll r)
{
    if(l == r)
    {
        seg[index] = a[r];
        return;
    }
    
    ll m = l + (r - l)/2;
    
    build(2*index+1, l, m);
    build(2*index+2, m+1, r);
    
    seg[index] = seg[2*index+1] + seg[2*index+2];
}
 
void update(ll index, ll low, ll high, ll node, ll val)
{
	if (low > node || high < node) return;
    
    seg[index] += val;
    
    if(low != high)
    {
    	ll mid = low + (high - low) / 2;
        
        update(2*index+1, low, mid, node, val);
        update(2*index+2, mid+1, high, node, val);
    }
 
}
 
ll query(ll index, ll l, ll r, ll qs, ll qe)
{
    if(qs > r || qe < l) return 0;
    if(l >= qs && r <= qe) return seg[index];
 
    ll m = l + (r-l)/2;
    
    ll x = query(2*index+1, l, m, qs, qe);
    ll y = query(2*index+2, m+1, r, qs, qe);
    
    return x+y;
}



/* Trie Data Structure */
typedef struct TrieNode
{
	bool endOfWord;
	struct TrieNode* child[26];
}Trie;

Trie *getNode()
{
	Trie *node = new Trie;
	node->endOfWord = false;

	for(int i = 0; i < 26; i++) {
		node->child[i] = NULL;
	}

	return node;
}
void insert(string s, Trie* root)
{
	Trie* temp = root;
	for(int i = 0; i < s.size(); i++)
	{
		int x = s[i] - 'a';
		if(temp->child[x] == NULL) {
			temp->child[x] = getNode();
		}
		
		temp = temp->child[x];
	}
	temp->endOfWord = true;
}

bool search(string s, Trie* root)
{
	Trie* temp = root;
	for(int i = 0; i < s.size(); i++)
	{
		int x = s[i] - 'a';
		if(temp -> child[x]) {
			temp = temp->child[x];
		}
		
		else return false;
	}
	return (temp != NULL && temp->endOfWord);
}


/* BFS Algo */

bool bfs()
{
	queue<int> q;
	dist[1] = 1;
	vis[1] = 1;
	q.push(1);
	
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		if(node == n) return true;
		
		for(int u : ar[node])
		if(vis[u] == false)
		{
			dist[u] = dist[node] + 1;
			vis[u] = true;
			par[u] = node;
			q.push(u);
		}
	}
	
	return false;
}



/* Dijsktra Algorithm */

/* 1) Using Set */

unordered_map<ll, vector<pair<ll, ll>>> adj;

void dijsktra(ll n, ll src)
{
    vector<ll> dist(n+1, LLONG_MAX);
    set<pair<ll, ll>> s;
    
    dist[src] = 0;
    s. insert({0, src});
    
    while(!s.empty())
    {
        auto p = *(s.begin());
        
        ll curr = p.second;
        ll curr_dist = p.first;
        
        s.erase(s.begin());
        
        for(auto i : adj[curr])
        {
            if(curr_dist + i.second < dist[i.first]) 
            {
                ll d = i.first;
                auto f = s.find({dist[d], d});
                
                if(f != s.end()) s.erase(f);
                
                dist[d] = curr_dist + i.second;
                s.insert({dist[d], d});    
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
    	cout << dist[i] << " ";
	}
}


/* 2) Using Priority_queue */

unordered_map<ll, vector<pair<ll, ll>>> adj;
void dijsktra(ll n, ll src)
{
    vector<ll> dist(n+1, LLONG_MAX), vis(n+1, false);
    priority_queue<pii, vpii, greater<pii>> q;
    
    dist[src] = 0;
    q.push({0, src});
    
    while(!q.empty())
    {
        auto p = q.top();
        
        ll u = p.second;
        q.pop();
        
        if(vis[u]) continue;
        vis[u] = 1;
        
        for(auto i : adj[u])
        {
        	ll v = i.first;
        	ll w = i.second;
            
			if(dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v}); 
            }
        }
    }
    for(ll i = 1; i <= n; i++)
    {
    	cout << dist[i] << " ";
	}
}

/* Floyd Warshall */

for(int k = 1; k <= n; k++)
{
    for(int i = 1; i <= n; i++)
	{
        for(int j = 1; j <= n; j++)
		{
            dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
        }
    }
}


/* Prim's Algorithm */

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



/*Kruskal's Algorithm */

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

vector<pair<int, pair<int, int>>> Graph;

Kruskals_Algo()
{
    int n, m;
    cin >> n >> m;

    
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



/* Lowest Common Ancestor (LCA) */
vector<int> G[200001];

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


/* GCD */

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm (ll a, ll b)
{
    return (a*b)/gcd(a,b);
}




/* Binary Exponentiation */

int binaryExponentiation(int x, int n)
{
	int result = 1;
	while(n > 0)
	{
    		if(n % 2 == 1) {
        			result = (result * x) % M;
			}
    		x = (x * x) % M ;
    		n = n / 2;
 	}
	return result;
}



/* Extended Euclid's Algorithm */

int x, y, GCD;
void extended_euclid (int a, int b)
{
	if(b == 0) {
		x = 1; y = 0; GCD = a;
		return;
	}
	
	extended_euclid (b, a % b);
	
	int cx = y;
	int cy = x - floor(a/b) * y;
	y = cy; x = cx;
	return;
}



/* Prime Factorisation */
int arr[1000001];
void sieve()
{
	int N = 1000000;
	for(int i = 1; i <= N; i++) arr[i] = i;
	
	for(int i = 2; (i*i) <= N; i++) 
	{
		if(arr[i] == i)	
		{
			for(int j = i*i; j <= N; j=j+i) {
				if(arr[j] == j) arr[j] = i;
			}
		}
	}
}




/* Prime Sieve */
  
bool isPrime[100005]
void sieve() 
{
    int N = 100005;
    
   	isPrime[0] = true;
    isPrime[1] = true;
    
    for(ll i = 2; i*i <= N; i++)
  	{
      	if(isPrime[i] == false) 
		{
            for(ll j = i*i; j <= N; j = j+i) {
       			isPrime[j] = true;
            }
        }
    }
}


/* Min Heap */
priority_queue < ll, vector<ll>, greater<ll> > mnheap;



/* Segmented Sieve */

int segmented_sieve(long long a, long long b)
{
	sieve();
	bool *vis = new bool[b-a+1];

	memset(vis, 1, sizeof(vis));
	for(long long i = 2; i*i <= b; i++) 
	{
		for(long long j = a; j <= b; j++) 
		{
			if(p[i]) {
				if(j == i) continue;
				if(j % i == 0) vis[j - a] = 0;
			}
		}
	}	
	
	int cnt = 0;
	for(long long i = a; i <= b; i++) {
		cnt += vis[i-a];
	}
	return cnt;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    ll t = 1;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        v.resize(n);

    }
    return 0;
}
