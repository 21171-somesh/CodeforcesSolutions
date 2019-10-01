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

const int MAX = 2e5 + 10;
int n;
string s[2];
int visited[2][MAX];

void dfs(int x, int y, int prevX, int prevY) {
	visited[x][y] = 1;
	if (y == n) return;
	int type = (s[x][y] - '0') <= 2 ? 0 : 1;
	if (prevX == x && prevY == y - 1) {
		if(type == 0) {
			dfs(x, y + 1, x, y);
		} else {
			if (x + 1 < 2)
				dfs(x + 1, y, x, y);
			else 
				dfs(x - 1, y, x, y);
		}
	} else {
		if (type == 0) {
			return;
		} else {
			dfs(x, y + 1, x, y);
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

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s[0] >> s[1];
		memset(visited, 0, sizeof visited);
		dfs(0, 0, 0, -1);
		if(visited[1][n] == 1) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}
