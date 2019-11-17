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
int n, m;
vector<vi> edges;
vi Rank, parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void unionR(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        Rank[a] += Rank[b];
    }
}

int main()
{
	io
	cin >> n >> m;
	edges.resize(n);
	Rank.resize(n, 1), parent.resize(n);
	iota(parent.begin(), parent.end(), 0);
	fr(i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		unionR(u, v);
	}
	fr(i, 0, n) {
		sort(edges[i].begin(), edges[i].end());
	}
	int pos = 1;
	int ans = 0;
	fr(i, 0, n) {
		if (edges[i].size() == 0) continue;
		fr(j, max((ll)pos, i + 1LL), edges[i][edges[i].size() - 1]) {
			int u = find(i);
			int v = find(j);
			if (u != v) {
				ans++;
				unionR(u, v);
			}
		}
		pos = max(pos, edges[i][edges[i].size() - 1] + 1);
	}
	cout << ans;
	return 0;
}
