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

map<string, int> mp;
vector<vi> edges(500);
vi visited(500);

string convert(string s) {
	fr(i, 0, s.size()) {
		s[i] = tolower(s[i]);
	}
	return s;
}

int dfs(int pos) {
	visited[pos] = 1;
	int ans = 0;
	for(auto it : edges[pos]) {
		if(visited[it] == 0)
			ans = max(ans, dfs(it) + 1);
	}
	return ans;
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
	int pos = 0;
	fr(i, 0, n) {
		string u, t, v;
		cin >> u >> t >> v;
		u = convert(u);
		v = convert(v);
		int pos1 = 0, pos2 = 0;
		if(mp.find(u) != mp.end()) {
			pos1 = mp[u];
		} else {
			mp[u] = pos;
			pos1 = pos++;
		}
		if(mp.find(v) != mp.end()) {
			pos2 = mp[v];
		} else {
			mp[v] = pos;
			pos2 = pos++;
		}
		edges[pos2].push_back(pos1);
	}
	pos = mp["polycarp"];
	int dist = dfs(pos);
	cout << dist + 1;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}