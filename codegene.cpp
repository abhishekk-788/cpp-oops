#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int F()
{
	sort(busStops.begin(), busStops.end());
	
	int n = busStops.size(), answer = 0;
	for(int i = 0; i < n-1; i++)
	{
		if(busStops[i][1] > busStops[i][0])
		{
			answer += busStops[i][1] - busStops[i][0];
			if(busStops[i+1][0] <= busStops[i][1]) busStops[i+1][0] = busStops[i][1];
		}
	}
	if(busStops[n-1][1] > busStops[n-1][0])
	{
		answer += busStops[n-1][1] - busStops[n-1][0];
	}
	return answer;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
    {
        int n;
		cin >> n;
		
		if(n > 26)
		{
			cout << "0\n";
		}
		else
		{
			long long res = 1;
		    for (long long i = 26; i > 26 - n; i--)
		    {
		        res = (res * i) % mod;
		    }
		    cout << res << "\n";
		}
	}
    return 0;
}

