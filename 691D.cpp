/******************************************
*******************************************
*******************************************
	PREPARED BY - SOMESH AWASTHI 
	CHANDIGARH UNIVERSITY
*******************************************
*******************************************
*******************************************/

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

vector<vi> edges;
vi arr;
vi parent;
vi Rank;
set<int, greater<int>> *s;
int find(int x) {
	if(parent[x] == x) return x;
	return find(parent[x]);
}
void unionR(int x, int y) {
	int u = find(x);
	int v = find(y);
	if(Rank[u] == Rank[v]) {
		parent[u] = v;
		Rank[v]++;
	} else if(Rank[u] > Rank[v]) {
		parent[v] = u;
	} else {
		parent[u] = v;
	}
}
void joinR(int n) {
	fr(i, 0, n) {
		int x = find(i);
		s[x].insert(i);
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
	s = new set<int, greater<int>> [n];
	arr.resize(n), edges.resize(n), parent.resize(n), Rank.resize(n, 0);
	iota(parent.begin(), parent.end(), 0);
	fr(i, 0, n) cin >> arr[i];
	while(m--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		edges[arr[x] - 1].push_back(arr[y] - 1);
		edges[arr[y] - 1].push_back(arr[x] - 1);
		unionR(arr[x] - 1, arr[y] - 1);
	}
	joinR(n);
	fr(i, 0, n) {
		int x = find(arr[i] - 1);
		int y = *s[x].begin();
		s[x].erase(s[x].begin());
		cout << y + 1 << ' ';
	}

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}