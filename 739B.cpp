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

template<typename T>
void debug(T arr) {
	for(auto it : arr) {
		cout << it << ' ';
	}
	cout << '\n';
}

int n, l;
int timer;
vl cost, dist, tin, tout, height;
vl dp;
vector<vector<pll>> edges;
vector<vi> up;

void dfs(int pos, int par, int w) {
	if(pos != par) {
		height[pos] = height[par] + 1;
	}
	dist[pos] = dist[par] + w;
	tin[pos] = ++timer;
    up[pos][0] = par;
    fr(i, 1, l + 1)
        up[pos][i] = up[up[pos][i - 1]][i - 1];
	for(auto it : edges[pos]) {
		if(par != it.first) {
			dfs(it.first, pos, it.second);
		}
	}
	tout[pos] = ++timer;
}

void dfs1(int pos, int par) {
	for(auto it : edges[pos]) {
		if(par != it.first) {
			dfs1(it.first, pos);

			dp[pos] += dp[it.first];
		}
	}
}

bool check(int pos, int par) {
	return (dist[pos] - dist[par]) <= cost[pos];
}

void func() {
	fr(i, 1, n) {
		int low = 0, high = height[i] + 1;
		int ans = -1;
		while(low <= high) {
			int mid = (low + high) / 2;
			int pos = i;
			for(int j = l + 1; j >= 0; j--) {
				if(mid & (1LL << j)) {
					pos = up[pos][j];
				}
			}
			if(check(i, pos)) {
				low = mid + 1;
				ans = pos;
			} else {
				high = mid - 1;
			}
		}
		if(ans != -1) {
			dp[up[i][0]] += 1;
			if(ans != 0) {
				dp[up[ans][0]] -= 1;
			}
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
	l = ceil(log2(n));
	dp.resize(n);
	tin.resize(n);
	tout.resize(n);
	cost.resize(n);
	dist.resize(n);
	edges.resize(n);
	height.resize(n);
	up.resize(n, vi(l + 2));
	fr(i, 0, n) {
		cin >> cost[i];
	}
	fr(i, 0, n - 1) {
		int p, w;
		cin >> p >> w;
		p--;
		edges[i + 1].push_back({p, w});
		edges[p].push_back({i + 1, w});
	}
	dfs(0, 0, 0);
	func(); 
	dfs1(0, 0);	
	debug(dp);

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}