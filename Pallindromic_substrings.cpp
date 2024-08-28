#include <bits/stdc++.h>
using namespace std;

void F(string s, int x, int y, set<string> &st)
{
    while(x >= 0 && y < s.length() && s[x] == s[y])
    {
        st.insert(s.substr(x, y - x + 1));

        x--;
        y++;
    }
}
void countSubstrings(string s) 
{
    set<string> st;
    
    for(int i = 0; i < s.length(); i++)
    {
        F(s, i, i, st);
        F(s, i, i+1, st);
    }

    for(auto &i : st)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    
    cout<<st.size()<<"\n";
}

int main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin >> s;
        
        if(s.length() == 0) cout<<"0\n";
        else if(s.length() == 1) cout<<"1\n";
        
        else
        {
            countSubstrings(s);
        }
    }
    return 0;
}