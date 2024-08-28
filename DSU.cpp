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
 
/* reserve space for map if n > 100000 */
// map< ll,ll > par, size;

ll par[100005], size[100005];

ll find_set(ll v) 
{
    if (v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void make_set(int v) 
{
    par[v] = v;
    size[v] = 1;
}

void union_set(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);

    if (a != b) 
    {
        if (size[a] < size[b]) swap(a, b);
        
        par[b] = a;
        size[a] += size[b];
    }
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
    	make_set(i);
    }

    int t;
    cin >> t;

    while(t--)
    {
    	int a, b;
	    cin >> a >> b;

	    union_set(a, b);
    }
    return 0;
}

	