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

const int MAX = 300010;

int n;
vector<vi> edges(MAX);
vi indeg(MAX), visited(MAX);
vector<pii> dist(MAX, {INT_MAX, INT_MAX}); 
map<string, int> mp;
vector<string> str;
string convert (string s) {
	fr(i, 0, s.size()) {
		s[i] = tolower(s[i]);
	}
	return s;
}

pii calc(string s) {
	int r = 0;
	for (auto it : s) {
		if (it == 'r') {
			r++;
		}
	}
	return {r, (int) s.size()};
}

pii minVal(pii a, pii b) {
	if (a.first < b.first) 
		return a;
	else if (b.first < a.first)
		return b;
	else {
		if (a.second < b.second)
			return a;
		else
			return b;
	}
}

void dfs(int pos, int par) {
	visited[pos] = 1;
	dist[pos] = dist[par];
	for(auto it : edges[pos]) {
		if(visited[it] == 0) {
			dfs(it, par);
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
	str.resize(n);
	int pos = 0;
	fr(i, 0, n) {
		cin >> str[i];
		str[i] = convert(str[i]);
		if (mp.find(str[i]) == mp.end()) {
			dist[pos] = calc(str[i]);
			mp[str[i]] = pos++;
		}
	}
	int m;
	cin >> m;
	vector<pair<string, string>> query(m);
	fr(i, 0, m) {
		int pos1 = 0, pos2 = 0;
		string s, t;
		cin >> s >> t;
		s = convert(s);
		t = convert(t);
		if (mp.find(s) == mp.end()) {
			dist[pos] = calc(s);
			pos1 = pos;
			mp[s] = pos++;
		} else {
			pos1 = mp[s];
		}
		if (mp.find(t) == mp.end()) {
			dist[pos] = calc(t);
			pos2 = pos;
			mp[t] = pos++;
		} else {
			pos2 = mp[t];
		}
		edges[pos2].push_back(pos1);
	}
	vi order(pos);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		return (dist[a].first == dist[b].first) ? dist[a].second < dist[b].second : dist[a].first < dist[b].first;
	});
	fr(i, 0, pos) {
		if(visited[order[i]] == 0) {
			dfs(order[i], order[i]);
		}
	}
	ll rSum = 0, lSum = 0;
	for(auto it : str) {
		int u = mp[it];
		rSum += dist[u].first;
		lSum += dist[u].second;
	}
	cout << rSum << ' ' << lSum;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}