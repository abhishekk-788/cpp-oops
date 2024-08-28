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

void solve()
{
	int n;
	cin >> n;
	
	vector<int> arr(n);
	unordered_map<int, int> mp;
	
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		mp[arr[i]]++;
	}
	
	vector<vector<int>> mat;
	mat.pb(arr);
	
	int k = 1;
	while(1)
	{
		for(int i = 0; i < n; i++)
		{
			arr[i] = mp[arr[i]];
//			cout << arr[i] << " ";
		}
		mp.clear();
		for(int i = 0; i < n; i++)
		{
			mp[arr[i]]++;
		}
		
		mat.pb(arr);
		
		int f = 0, sz = mat.size();
		for(int i = 0; i < n; i++)
		{
			if(mat[sz-1][i] != mat[sz-2][i]) 
			{
				f = 1;
				break;
			}
		}
		
		if(f == 0) 
		{
			mat.pop_back();
			break;	
		}
		k++;
	}
	
	int q;
	cin >> q;
	
//	cout << q << "\n";
//	cout << mat.size() << "\n";

//	for(int i = 0; i < mat.size(); i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//			cout << mat[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		
//		cout << x << " " << y << " " << k << "\n";
		
		if(y > k)
		{
			cout << mat[k-1][x-1] << "\n";
		}
		else cout << mat[y][x-1] << "\n";
	}
}


int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    ll t = 1, z = 1;
    cin >> t;

    while(z <= t)
    {
        //cout<<"Case #"<< z <<": ";
        solve();
        z++;
    }
    return 0;
}


