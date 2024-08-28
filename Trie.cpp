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

int32_t main()
{
    #ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    #endif

    ios::sync_with_stdio(0), cin.tie(0);

    ll t = 1;

    while(t--)
    {
        Trie *root = getNode();
        
        insert("abc", root);
        insert("abcde", root);

        cout<<search("abcde", root)<<"\n";

    }
    return 0;
}

