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

vector<vector<pii>> edges;
vi dist;
vi visited;
vi arr;

void dfs(int pos, int val) {
	visited[pos] = 1;
	dist[pos] += val;
	int temp = 0;
	for(auto it : edges[pos]) {
		if(visited[it.first] == 0) {
			dfs(it.first, it.second);
			dist[pos] += dist[it.first];
			temp++;
		}
	}
}

void dfs1(int pos) {
	visited[pos] = 1;
	int flag = 0;
	for(auto it : edges[pos]) {
		int u = it.first;
		if(visited[u] == 0) {
			flag |= dist[u];
			dfs1(u);
		}
	}
	if(flag == 0 && dist[pos] > 0) {
		arr.push_back(pos);
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
	edges.resize(n);
	visited.resize(n);
	dist.resize(n);
	int temp = n - 1;
	while(temp--) {
		int x, y, t;
		cin >> x >> y >> t;
		x--, y--, t--;
		edges[x].push_back({y, t});
		edges[y].push_back({x, t});
	}
	dfs(0, 0);
	fill(visited.begin(), visited.end(), 0);
	dfs1(0);
	cout << arr.size() << '\n';
	fr(i, 0, arr.size()) {
		cout << arr[i] + 1 << ' ' ;
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}