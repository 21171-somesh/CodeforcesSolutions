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

vector<vector<char>> mat;
vector<vector<pii>> parent;
vector<vi> Rank;
int n, m;
int X[] = {0, 0, -1, 1};
int Y[] = {1, -1, 0, 0};

bool check(int x, int y) {
	return (x < n && x >= 0 && y < m && y >= 0 && mat[x][y] == '.');
}

pii find(int x, int y) {
	if(parent[x][y] == pii(x, y)) return {x, y};
	return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
}

void unionR(int x, int y, int u, int v) {
	pii a = find(x, y);
	pii b = find(u, v);
	x = a.first, y = a.second, u = b.first, v = b.second;
	if(pii(u, v) != pii(x, y)) {
		if(Rank[x][y] > Rank[u][v]) {
			parent[u][v] = {x, y};
		} else if(Rank[x][y] < Rank[u][v]) {
			parent[x][y] = {u, v};
		} else {
			parent[x][y] = {u, v};
			Rank[u][v]++;
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

	cin >> n >> m;
	mat.resize(n, vector<char>(m));
	parent.resize(n, vector<pii>(m));
	Rank.resize(n, vector<int>(m));
	fr(i, 0, n) {
		fr(j, 0, m) {
			cin >> mat[i][j];
			parent[i][j] = {i, j};
			Rank[i][j] = 0;
		}
	}
	fr(i, 0, n) {
		fr(j, 0, m) {
			if(mat[i][j] == '*') {
				continue;
			}
			fr(k, 0, 4) {
				int dx = X[k] + i, dy = Y[k] + j;
				if(check(dx, dy)) {
					// cout << dx << ' ' << dy << ' ' << i << ' ' << j << '\n';
					unionR(dx, dy, i, j);
				}
			}
		}
	}
	map<pii, int> mp, mp1;
	fr(i, 0, n) {
		fr(j, 0, m) {
			pii a = find(i, j);
			mp[a]++;
		}
	}
	fr(i, 0, n) {
		fr(j, 0, m) {
			ll sum = 1;
			if(mat[i][j] == '.') {
				cout << ".";
				continue;
			}
			mp1.clear();
			fr(k, 0, 4) {
				int dx = X[k] + i, dy = Y[k] + j;
				if(check(dx, dy)) {
					pii a = find(dx, dy);
					if(mp1.find(a) == mp1.end()) {
						mp1[a]++;
					}
				}
			}
			for(auto it : mp1) {
				sum += mp[it.first];
			}
			cout << sum % 10;
		} 
		cout << '\n';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}