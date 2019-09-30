//21171_somesh || asomesh999
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

vi parent, Rank;

int find(int x) {
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unionR(int u, int v) {
	u = find(u), v = find(v);
	if(u != v) {
		if(Rank[u] > Rank[v]) {
			parent[v] = u;
		} else if(Rank[u] < Rank[v]) {
			parent[u] = v;
		} else {
			parent[u] = v;
			Rank[v]++;
		}
	}
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n, m;
	cin >> n >> m;
	int sum = 0;
	parent.resize(m);
	Rank.resize(n);
	iota(parent.begin(), parent.end(), 0);
	int ans = 0;
	unordered_map<int, int> mp, mp1;
	fr(i, 0, n) {
		int k;
		cin >> k;
		if(k == 0) {
			ans++;
			continue;
		}
		int u;
		cin >> u;
		u--;
		mp[u]++;
		k -= 1;
		while(k--) {
			int v;
			cin >> v;
			v--;
			mp[v]++;
			unionR(u, v);
		}
	}
	for(auto it : mp) {
		int x = find(it.first);
		mp1[x]++;
	}
	if(mp1.size() > 0) {
		ans += mp1.size() - 1;
	}
	cout << ans;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}