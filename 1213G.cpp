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

int n;
ll answer = 0;
vector<pair<ll, pll>> edges;
vl Rank, parent;

int find(int x) {
	if(parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void unionR(int u, int v) {
	u = find(u), v = find(v);
	if(u == v) return;
	if(Rank[u] > Rank[v]) {
		swap(u, v);
	}
	parent[u] = v;
	answer -= (Rank[u] * (Rank[u] - 1)) / 2;
	answer -= (Rank[v] * (Rank[v] - 1)) / 2;
	Rank[v] += Rank[u];
	answer += (Rank[v] * (Rank[v] - 1)) / 2;
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
	Rank.resize(n, 1);
	parent.resize(n);
	edges.resize(n - 1);
	iota(parent.begin(), parent.end(), 0);
	fr(i, 0, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edges[i] = {w, {u, v}};
	}
	sort(edges.begin(), edges.end());
	vector<pll> queries(m);
	vector<ll> ans(m);
	fr(i, 0, m) {
		queries[i].first = i;
		cin >> queries[i].second;
	}
	sort(queries.begin(), queries.end(), [&](pii a, pii b) {
		return a.second < b.second;
	});
	ll ele = 0, pos = 0;
	fr(i, 0, m) {
		ll newEle = queries[i].second;
		if(newEle > ele) {
			while(pos < n - 1 && edges[pos].first <= newEle) {
				unionR(edges[pos].second.first, edges[pos].second.second);
				// cout << pos << ' ' << edges[pos].second.first << ' ' << edges[pos].second.second << ' ';
				pos++;
			}
			// cout << answer << '\n';
			ele = newEle;
			ans[queries[i].first] = answer;
		} else {
			ans[queries[i].first] = answer;
		}
	}
	fr(i, 0, m) {
		cout << ans[i] << ' ';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}