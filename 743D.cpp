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

ll n;
vector<vl> edges;
vl cost, dp, maxDp;
ll sum = LONG_MIN;

ll dfs(int pos, int par) {
	dp[pos] = cost[pos];
	for(auto it : edges[pos]) {
		if(it != par) {
			dp[pos] += dfs(it, pos);
			maxDp[pos] = max(maxDp[pos], maxDp[it]);
		}
	}
	maxDp[pos] = max(maxDp[pos], dp[pos]);
	return dp[pos];
}

void dfsUtil(int pos, int par) {
	ll a = LONG_MIN, b = LONG_MIN;
	for(auto it : edges[pos]) {
		if(it != par) {
			dfsUtil(it, pos);
			ll temp = maxDp[it];
			if(temp > a) swap(a, temp);
			if(temp > b) swap(b, temp);
		}
	}
	if(a != LONG_MIN && b != LONG_MIN) {
		sum = max(sum, a + b);
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
	dp.resize(n);
	cost.resize(n);
	maxDp.resize(n, INT_MIN);
	edges.resize(n);
	fr(i, 0, n) {
		cin >> cost[i];
	}
	fr(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, -1);
	dfsUtil(0, -1);
	if(sum == LONG_MIN) {
		cout << "Impossible";
		return 0;
	}
	cout << sum;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}