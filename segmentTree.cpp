#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
ll a[200005], seg[4 * 200005];
 
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
    
    seg[index] = max(seg[2*index+1], seg[2*index+2]);
}
 
ll queryAndUpdate(ll index, ll l, ll r, ll val)
{
    if(l > r) return -1;
    if(l == r && seg[index] >= val)
    {
        seg[index] -= val;
        return l;
    }
 
    ll m = l + (r-l)/2;
    
    if(seg[2*index + 1] >= val)
    {
        ll x = queryAndUpdate(2*index + 1, l, m, val);
 
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
        return x;
    }
    else
    {
        ll x = queryAndUpdate(2*index + 2, m+1, r, val);
 
        seg[index] = max(seg[2*index+1], seg[2*index+2]);
        return x;
    }
}
 
int32_t main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif
 
    ios::sync_with_stdio(0), cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    build(0, 0, n-1);
        
    for(int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;

        if(x > seg[0])
        {
            cout<<"0 ";
            continue;
        }
 
        ll d = queryAndUpdate(0, 0, n-1, x);
        cout<<d+1<<" ";  
        
    }
    
    return 0;
}