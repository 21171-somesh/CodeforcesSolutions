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

vector<vi> visited;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
int n, m;
vector<pii> arr;

bool check(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m) {
		return true;
	}
	return false;
}

void dfs(int x, int y) {
	visited[x][y] = 1;
	arr.push_back({x, y});
	for(int i = 0; i < 4; i++) {
		int dx = x + X[i], dy = Y[i] + y;
		if(check(dx, dy)) {
			if(!visited[dx][dy]) {
				dfs(dx, dy);
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

	int k;
	cin >> n >> m >> k;
	visited.resize(n, vi(m));
	dfs(0, 0);
	int size = (n * m) / k;
	int j = 0;
	fr(i, 0, k - 1) {
		cout << size << ' ';
		j = i * size;
		for(; j < size + i * size; j++){
			cout << arr[j].first + 1 << ' ' << arr[j].second + 1 << ' ';
		}

		cout << '\n';
	}
	cout << m * n - j << ' ';
	fr(i, j, arr.size()) {
		cout << arr[i].first + 1 << ' ' << arr[i].second + 1 << ' ';
	} 

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}