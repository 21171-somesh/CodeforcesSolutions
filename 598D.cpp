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

int n, m, k;
vector<vector<char>> mat;
vector<vector<pii>> parent;
vector<vi> ans, visited;
int globalAns = 0;

int X[] = {0, 0, -1, 1};
int Y[] = {1, -1, 0, 0};

bool check(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == '.');
}

bool check2(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == '*');
}

pii find(int x, int y) {
	if(parent[x][y] == pii(x, y)) return pii(x, y);
	return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
}

void unionR(pii a, pii b) {
	a = find(a.first, a.second), b = find(b.first, b.second);
	if(a != b) {
		if(a.first > b.first) {
			parent[b.first][b.second] = a;
		} else if(a.first < b.first) {
			parent[a.first][a.second] = b;
		} else {
			if(a.second > b.second) {
				parent[a.first][a.second] = b;
			} else {
				parent[b.first][b.second] = a;
			}
		}
	}
}

void dfs(int x, int y, int kk) {
	visited[x][y] = kk;
	fr(i, 0, 4) {
		int dx = x + X[i], dy = y + Y[i];
		if(check(dx, dy) && visited[dx][dy] != kk) {
			dfs(dx, dy, kk);
 		} else if(check2(dx, dy)) {
 			globalAns++;
 			// arr[dx][dy] = kk;
 		}
	}
}

int count(int kk, int x, int y) {
	pii a = find(x, y);
	globalAns = 0;
	if(ans[a.first][a.second] != -1) {
		return ans[a.first][a.second];
	}
	dfs(a.first, a.second, kk);
	ans[a.first][a.second] = globalAns;
	return globalAns;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m >> k;
	// arr.resize(n, vi(m));
	ans.resize(n, vi(m, -1));
	mat.resize(n, vector<char> (m));
	visited.resize(n, vi(m, 0));
	parent.resize(n, vector<pii>(m));
	fr(i, 0, n) {
		fr(j, 0, m) {
			cin >> mat[i][j];
			parent[i][j] = {i, j};
		}
	}
	fr(i, 0, n) {
		fr(j, 0, m) {
			if(mat[i][j] == '*') continue;
			fr(k, 0, 4) {
				int dx = i + X[k], dy = j + Y[k];
				if(check(dx, dy)) {
					unionR(pii(i, j), pii(dx, dy));
				}
			}
		}
	}
	fr(i, 0, k) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int ans = count(i + 1, u, v);
		cout << ans << '\n';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}