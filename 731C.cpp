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

vi cost, parent, Rank;

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

	int n, m, k;
	cin >> n >> m >> k;
	cost.resize(n);
	Rank.resize(n);
	parent.resize(n);
	iota(parent.begin(), parent.end(), 0);
	fr(i, 0, n) {
		cin >> cost[i];
	}
	while(m--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		unionR(u, v);
	}
	map<int, vi> mp;
	fr(i, 0, n) {
		int x = find(i);
		parent[i] = x;
		mp[x].push_back(i);
	}
	map<int, int> mp1;
	ll sum = 0;
	for(auto it : mp) {
		mp1.clear();
		for(auto it1 : it.second) {
			mp1[cost[it1]]++;
		}
		int maxEle = 0;
		for(auto it1 : mp1) {
			
			maxEle = max(maxEle, it1.second);
		}
		sum += it.second.size() - maxEle;
	}
	cout << sum;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}