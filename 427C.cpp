//21171_somesh || asomesh999
//ACC

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

int n, m;
vector<vl> scc;
vl cost, visited, arr;
vector<vi> edges, rev;
stack<int> st;

void dfs(int u) {
	visited[u] = 1;
	for (auto it : edges[u]) {
		if (visited[it] == 0) {
			dfs(it);
		}
	}
	st.push(u);
}

void getSCC(int u) {
	visited[u] = 1;
	arr.push_back(u);
	for (auto it : rev[u]) {
		if (visited[it] == 0) {
			getSCC(it);
		}
	}
}

int main()
{
	io
	cin >> n;
	rev.resize(n);
	cost.resize(n);
	edges.resize(n);
	visited.resize(n);
	fr(i, 0, n) {
		cin >> cost[i];
	}
	cin >> m;
	fr(i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[u].push_back(v);
		rev[v].push_back(u);
	}
	fr(i, 0, n) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}
	fill(visited.begin(), visited.end(), 0);
	while(!st.empty()) {
		int u = st.top();
		st.pop();
		if (visited[u] == 0) {
			arr.clear();
			getSCC(u);
			scc.push_back(arr);
		}
	}
	ll ans = 1;
	ll sum = 0;
	fr(i, 0, scc.size()) {
		sort(scc[i].begin(), scc[i].end(), [&] (ll a, ll b) {
			return cost[a] < cost[b];
		});
		ll count = 1;
		sum += cost[scc[i][0]];
		fr(j, 1, scc[i].size()) {
			if (cost[scc[i][j]] == cost[scc[i][0]]) {
				count++;
			}
		}
		ans = (ans * count) % mod;
	}
	cout << sum << ' ' << ans << '\n';

	return 0;
}
