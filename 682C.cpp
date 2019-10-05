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
vl arr;
vector<vector<pll>> edges;
vl countChild, dist, minDist;
int anss = 0;

ll dfs(int pos, int prev, ll dis, ll minVal) {
	ll ans = 0;
	dist[pos] = dis;
	minVal = min(minVal, dis);
	minDist[pos] = minVal;
	for (auto it : edges[pos]) {
		if (it.first != prev) {
			ans += dfs(it.first, pos, dis + it.second, minVal) + 1;
		}
	}
	return countChild[pos] = ans;
} 

void dfs1(int pos, int prev) {
	if (dist[pos] - minDist[pos] > arr[pos]) {
		anss += countChild[pos] + 1;
		return;
	}
	for(auto it : edges[pos]) {
		if (it.first != prev) {
			dfs1(it.first, pos);
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

	cin >> n;
	arr.resize(n);
	dist.resize(n);
	edges.resize(n);
	minDist.resize(n);
	countChild.resize(n);
	fr(i, 0, n) {
		cin >> arr[i];
	}
	fr(i, 0, n - 1) {
		ll u, w;
		cin >> u >> w;
		u--;
		edges[u].push_back({i + 1, w});
		edges[i + 1].push_back({u, w});
	}
	dfs(0, 0, 0, 0);
	dfs1(0, 0);
	cout << anss;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}
