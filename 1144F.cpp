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

vector<pii> edg;
vector<vi> edges, edges1;
vi visited;
map<pii, int> mp;
int flag = 0;

void dfs(int pos, int val) {
	visited[pos] = 1;
	val += 1;
	for(auto it : edges[pos]) {
		if(mp.find({pos, it}) == mp.end() && mp.find({it, pos}) == mp.end()) {
			if(val % 2 == 0) {
				edges1[it].push_back(pos);
				mp[{it, pos}] = 1;
			}
			else {
				edges1[pos].push_back(it);
				mp[{pos, it}] = 1;
			}
		}
		if(visited[it] == 0)
			dfs(it, val);
	}
}

void func(int pos) {
	queue<int> q;
	for(auto it : edges1[pos]) {
		q.push(it);
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(edges1[u].size()) {
			flag = 1;
			break;
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

	int n, m;
	cin >> n >> m;
	edges.resize(n);
	edges1.resize(n);
	visited.resize(n);
	edg.resize(m);
	fr(i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edg[i] = {u, v};
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, 0);
	string s;
	flag = 0;
	fr(i, 0, n) {
		if(flag) break;
		func(i);
	}
	if(flag) cout << "NO";
	else {
		fr(i, 0, m) {
			pii a = edg[i];
			if(mp.find(a) != mp.end()) {
				s.push_back('0');
			} else {
				s.push_back('1');
			}
		}
		cout << "YES\n";
		cout << s;
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}