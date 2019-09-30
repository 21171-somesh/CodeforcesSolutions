/******************************************
*******************************************
*******************************************
	PREPARED BY - SOMESH AWASTHI 
	CHANDIGARH UNIVERSITY
*******************************************
*******************************************
*******************************************/
//AC

#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i=a;i<b;i++)
#define io ios::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
long int mod=1000000007;

const int MAX = 27;

vi parent(MAX), Rank(MAX, 0);

int find(int x) {
	return (parent[x] == x) ? x : find(parent[x]);
}

void unionR(int x, int y ) {
	int u = find(x);
	int v = find(y);
	if(Rank[u] == Rank[v]) {
		parent[u] = v;
		Rank[v]++;
	} else if(Rank[u] < Rank[v]) {
		parent[u] = v;
	} else {
		parent[v] = u;
	}
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n;
	cin >> n;
	string s, t;;
	cin >> s >> t;
	iota(parent.begin(), parent.end(), 0);
	vector<pair<char, char>> ans;
	fr(i, 0, n) {
		if(s[i] != t[i]) {
			int u = find(s[i] - 'a');
			int v = find(t[i] - 'a');
			if(u != v) {
				unionR(u, v);
				ans.push_back({s[i], t[i]});
			}	
		}
	}
	cout << ans.size() << '\n';
	fr(i, 0, ans.size()) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	} 

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}