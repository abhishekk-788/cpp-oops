#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, c, d = 0, e = 0;
	cin >> n >> m;
 
	vector<vector<int>>arr(n,vector<int>(m));
    for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
	
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            c = arr[i][j] % 2;
            if(c == 0)
            {
                e++;
            }
            else d++;
        }
    }
    
	cout<<"even"<<e<<"\n odd"<<d;
    return 0;
}
