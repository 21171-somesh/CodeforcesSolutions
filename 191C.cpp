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

int n, l;
vector<vi> edges;
int timer;
vector<int> tin, tout, dist;
vector<vi> up;
map<pii, int> mp;

int dfsSum(int pos, int par) {
	int ans = 0;
	for(auto it : edges[pos]) {
		if (it != par) {
			ans += dfsSum(it, pos);
		}
	}
	ans += dist[pos];
	if (pos != 0) {
		mp[{pos, par}] = ans;
		mp[{par, pos}] = ans;
	}
	return dist[pos] = ans;
}

void dfs(int v, int p) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (int u : edges[v]) {
		if (u != p)
			dfs(u, v);
	}
	tout[v] = ++timer;
}
bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}
void preprocess(int root) {
	tin.resize(n);
	tout.resize(n);
	dist.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.resize(n, vi(l + 1));
	dfs(root, root);
}

int main()
{
	io
	cin >> n;
	edges.resize(n);
	vector<pii> edgeList(n - 1);
	fr(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edgeList[i] = {u, v};
		edges[u].push_back(v);
		edges[v].push_back(u);
	} 
	preprocess(0);
	int k;
	cin >> k;
	while (k--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int lc = lca(u, v);
		dist[lc] -= 2;
		dist[u]++;
		dist[v]++;			
	}
	dfsSum(0, 0);
	for(auto it : edgeList) {
		cout << mp[it] << ' ';
	}
	return 0;
}
