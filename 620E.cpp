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

int size = 0;
int n, timer = 0;
vector<vl> edges;
vl visited, vis, cost;
vl segTree(5000000), lazy(5000000);

void push(int s, int e, int pos) {
	if(lazy[pos] != 0) {
		segTree[pos] = (1ll << lazy[pos]);
		if(s != e) {
			lazy[pos * 2] = lazy[pos];
			lazy[pos * 2 + 1] = lazy[pos];
		}
		lazy[pos] = 0;
	}
}

void dfs(int pos) {
	visited[pos] = 1;
	vis.push_back(pos);
	for(auto it : edges[pos]) {
		if(visited[it] == 0) {
			dfs(it);
		}
	}
	vis.push_back(pos);
}

void init(int l, int r, int pos) {
	if(l == r) {
		segTree[pos] = (1LL << cost[vis[l]]);
		return;
	}
	int mid = (l + r) / 2;
	init(l, mid, pos * 2);
	init(mid + 1, r, pos * 2 + 1);
	segTree[pos] = (segTree[pos * 2] | segTree[pos * 2 + 1]);
}

void update(int start, int end, int l, int r, int pos, int val) {
	push(start, end, pos);
	if(start > r || end < l || r < l) {
		return;
	}
	if(start >= l && end <= r) {
		segTree[pos] = (1LL << val);
		if(start != end) {
			lazy[pos * 2] = val;
			lazy[pos * 2 + 1] = val;
		}
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, l, r, pos * 2, val);
	update(mid + 1, end, l, r, pos * 2 + 1, val);
	segTree[pos] = (segTree[pos * 2] | segTree[pos * 2 + 1]);
}

ll query(int start, int end, int l, int r, int pos) {
	push(start, end, pos);
	if(start > r || end < l || r < l) {
		return 0;
	}
	if(start >= l && end <= r) {
		return segTree[pos];
	}
	int mid = (start + end) / 2;
	return query(start, mid, l, r, pos * 2) | query(mid + 1, end, l, r, pos * 2 + 1);
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int m;
	cin >> n >> m;
	cost.resize(n);
	edges.resize(n);
	visited.resize(n);
	fr(i, 0, n) {
		cin >> cost[i];
	}
	int temp = n - 1;
	while(temp--) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[v].push_back(u);
		edges[u].push_back(v);
	}
	dfs(0);
	size = vis.size();
	vector<pii> range(n, {-1, -1});
	fr(i, 0, size) {
		if(range[vis[i]].first == -1) range[vis[i]].first = i;
		else range[vis[i]].second = i;
	}
	init(0, size - 1, 1);
	while(m--) {
		int x;
		cin >> x;
		if(x == 1) {
			int u, v;
			cin >> u >> v;
			u--;
			update(0, size - 1, range[u].first, range[u].second, 1, v);
		} else {
			int y;
			cin >> y;
			y--;
			ll ans = __builtin_popcountll(query(0, size - 1, range[y].first, range[y].second, 1));
			cout << ans << '\n';
		}
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}