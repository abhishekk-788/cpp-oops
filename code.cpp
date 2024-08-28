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
	
}

int minLines(vector<vector<int> > fc, int x1, int y1)
{
	map<float, int> mp;
	
	int n = fc.size();
	for(int i = 0; i < n; i++)
	{
		int x2 = fc[i][0];
		int y2 = fc[i][1];
		
		float f = ((y2-y1) * 1.0) / ((x2-x1) * 1.0);
		mp[f]++;
	}
	
	int answer = mp.size();
	
	return answer;
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

