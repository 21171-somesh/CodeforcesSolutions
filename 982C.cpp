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

vector<vi> edges;
vi Rank, parent, visited, dist;
map<int, int> size;
int a = 0;

int find(int x) {
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unionR(int u, int v) {
	u = find(u);
	v = find(v);
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

void dfs(int pos) {
	visited[pos] = 1;
	for(auto it : edges[pos]) {
		if(visited[it] == 0) {
			dfs(it);
			dist[pos] += dist[it];
		}
	}
	dist[pos]++;
}

void dfs1(int pos) {
	visited[pos] = 1;
	if(parent[pos] != pos) {
		a += (dist[pos] % 2 == 0) ? 1 : 0;
	}
	for(auto it : edges[pos]) {
		if(visited[it] == 0) {
			dfs1(it);
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

	int n;
	cin >> n;
	Rank.resize(n);
	dist.resize(n);
	edges.resize(n);
	parent.resize(n);
	visited.resize(n);
	iota(parent.begin(), parent.end(), 0);
	fr(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		unionR(u, v);
	}
	if(n % 2 != 0) {
		cout << -1;
		return 0;
	}
	fr(i, 0, n) {
		parent[i] = find(i);
		size[parent[i]]++;
	}
	ll ans = 0;
	for(auto it : size) {
		dfs(it.first);
		fill(visited.begin(), visited.end(), 0);
		dfs1(it.first);
	}
	cout << a << '\n';

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}