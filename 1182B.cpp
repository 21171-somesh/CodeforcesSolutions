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

int n, m;
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};
vector<vector<char>> mat;

bool check(int x, int y) {
	return (x < n && x >= 0 && y >= 0 && y < m && mat[x][y] == '*');
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> n >> m;
	mat.resize(n, vector<char> (m));
	fr(i, 0, n) {
		fr(j, 0, m) {
			cin >> mat[i][j];
		}
	}
	int posi = 0, posj = 0, count = 0;
	fr(i, 1, n - 1) {
		fr(j, 1, m - 1) {
			if(mat[i][j] == '*' && mat[i - 1][j] == '*' && mat[i][j - 1] == '*' && mat[i + 1][j] == '*' && mat[i][j + 1] == '*') {
				count++;
				posi = i;
				posj = j;
			} 
		}
	}
	if(count != 1) {
		cout << "NO";
		return 0;
	}
	vector<vi> visited(n, vi(m));
	visited[posi][posj] = 1;
	fr(i, 0, 4) {
		int dx = X[i], dy = Y[i];
		int x = posi + dx, y = posj + dy;
		while(check(x, y)) {
			visited[x][y] = 1;
			x += dx, y += dy;
		}
	}
	fr(i, 0, n) {
		fr(j, 0, m) {
			if(mat[i][j] == '*' && visited[i][j] == 0) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}