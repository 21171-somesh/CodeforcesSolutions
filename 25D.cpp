/******************************************
*******************************************
*******************************************
	PREPARED BY - SOMESH AWASTHI 
	CHANDIGARH UNIVERSITY
*******************************************
*******************************************
*******************************************/
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
long int mod = 1000000007;

vi parent, Rank;
vector<pii> not_req;
vector<vi> par;
int find(int x) {
	return (parent[x] == x) ? x : find(parent[x]);
}
void unionR(int x, int y) {
	int u = find(x);
	int v = find(y);
	if(u == v) {
		not_req.push_back({x, y});
	} else {
		if(Rank[u] == Rank[v]) {
			parent[u] = v;
			Rank[v]++;
		}
		else if(Rank[u] > Rank[v]) {
			parent[v] = u;
		} else {
			parent[u] = v;
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
	par.resize(n);
	parent.resize(n);
	Rank.resize(n, 0);
	iota(parent.begin(), parent.end(), 0);
	int m = n - 1;
	while(m--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		unionR(x, y);
	}
	fr(i, 0, n) {
		int x = find(i);
		par[x].push_back(i);
	}
	int maxPar = 0, index = 0;
	fr(i, 0, n) {
		if(maxPar < par[i].size()) {
			maxPar = par[i].size();
			index = i;
		}
	}
	vector<pair<pii, pii>> ans;
	int j = 0;
	fr(i, 0, n) {
		if(i != index) {
			if(par[i].size() > 0) {
				ans.push_back({not_req[j++], {index, i}});
			}
		}
	}
	cout << ans.size() << '\n';
	fr(i, 0, ans.size()) {
		cout << ans[i].first.first+1 << ' ' << ans[i].first.second+1 << ' ' << ans[i].second.first+1 << ' ' << ans[i].second.second+1 << '\n';
	}

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}