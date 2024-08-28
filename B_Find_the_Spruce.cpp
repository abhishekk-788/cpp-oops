#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define mod 1000000007

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t = 1;
	cin >> t;

	while(t--)
	{
		int n, m;
		cin >> n >> m;

		vector<string> v(n);
		
        for(int i = 0; i < n; i++)
        {
            string str;
            cin >> str;

            v[i] = str;
        }

        vector<vector<int>> p(n, vector<int> (m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(v[i][j] == '*')
                {
                    int x = 0, y = 0;
                    
                    if(i - 1 >= 0 && v[i-1][j] > 0) x = p[i-1][j];
                    if(j - 1 >= 0 && v[i][j-1] > 0) y = p[i][j-1];
                    
                    int ans = min(x, y);
                    
                    int cnt = 0;
                    for(int k = j+1; k < min(j+ans+1, m); k++)
                    {
                        if(v[i][k] == '*') cnt++;
                    }

                    ans = min(ans, cnt) + 1;
                    p[i][j] = ans;
                }
                else p[i][j] = 0;
            }
        }
        
        int s = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //cout<<p[i][j]<<" ";
                s += p[i][j];
            }
            //cout<<"\n";
        }

        cout<<s<<"\n";
	}

	return 0;
}