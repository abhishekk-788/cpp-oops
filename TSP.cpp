#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

/* Travelling Salesman Problem
   dp[i, S] = min(dist[i][j1] + dp[i, S-{j1}],
				  dist[i][j2] + dp[i, S-{j2}],
				  dist[i][j3] + dp[i, S-{j3}],
				  ...........................,
				  dist[i][jn] + dp[i, S-{jn}]
			 );

  Time Complexity : O(2^N * N) */

int tsp(vector<vector<int>> &dist, vector<vector<int>> &dp, int visited, int mask, int pos, int n)
{
	if(mask == visited) {
		return dist[pos][0];
	}

	if(dp[mask][pos] != -1) {
		return dp[mask][pos];
	}

	int res = INT_MAX;
	for(int city = 0; city < n; city++)
	{
		if((mask & (1 << city)) == 0)
		{
			int ans = dist[pos][city] + tsp(dist, dp, visited, mask|(1 << city), city, n);
			res = min(res, ans);
		}
	}

	dp[mask][pos] = res;
	return dp[mask][pos] = res;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    vector<vector<int>> dist(num_nodes, vector<int> (num_nodes, 0));
    for(int i = 0; i < num_nodes; i++)
    {
        for(int j = 0; j < num_nodes; j++)
        {
            cin >> dist[i][j];
        }
    }

    int visited = (1 << num_nodes) - 1;
    vector<vector<int>> dp(1 << num_nodes, vector<int> (num_nodes, -1));

    cout<< tsp(dist, dp, visited, 1, 0, num_nodes) << "\n";
    return 0;
}