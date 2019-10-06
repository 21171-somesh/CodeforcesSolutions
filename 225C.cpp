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

int n, m, x, y;
vector<vector<char>> mat;
vi req;

int dp[1001][1001][2];

int func(int pos, int cons, int prev) {
	if (pos >= m) {
		if (cons >= x && cons <= y) 
			return 0;
		else 
			return int(1e9);
	}
	int &ans = dp[pos][cons][prev];
	if (ans != -1) return ans;
	int plus = (prev == 0) ? req[pos] : (n - req[pos]);
	int invert = (prev != 0) ? req[pos] : (n - req[pos]);
	if (cons == 0) {
		ans = min(func(pos + 1, 1, 0) + plus, func(pos + 1, 1, 1) + invert);
	} else if (cons < x) {
		ans = func(pos + 1, cons + 1, prev) + plus;
	} else if (cons >= x && cons < y) {
		ans = min(func(pos + 1, cons + 1, prev) + plus, func(pos + 1, 1, prev ^ 1) + invert);
	} else {
		ans = func(pos + 1, 1, prev ^ 1) + invert;
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

	cin >> n >> m >> x >> y;
	req.resize(m);
	mat.resize(n, vector<char>(m));
	fr(i, 0, n) fr(j, 0, m) {
		cin >> mat[i][j];
	}
	int temp = 0;
	fr(i, 0, m) {
		temp = 0;
		fr(j, 0, n) {
			if (mat[j][i] == '.') {
				temp++;
			}
		}
		req[i] = temp;
	}
	memset(dp, -1, sizeof dp);
	cout << func(0, 0, 0);

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}