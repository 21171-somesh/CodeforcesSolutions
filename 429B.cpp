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
ll n, m;
vector<vl> mat;
ll dp1[1010][1010], dp2[1010][1010], dp3[1010][1010], dp4[1010][1010];

void preprocess() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp1[i][j] = mat[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
		}
	}
	for (int j = m; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			dp2[i][j] = mat[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			dp3[i][j] = mat[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			dp4[i][j] = mat[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);
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
	mat.resize(n + 1, vl(m + 1));
	fr(i, 1, n + 1) {
		fr(j, 1, m + 1) {
			cin >> mat[i][j];
		}
	}
	preprocess();
	ll maxAns = 0;
	fr(i, 2, n) {
		fr(j, 2, m) {
			ll temp = 0;
			temp = dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1];
			maxAns = max(maxAns, temp);
			temp = 0;
			temp = dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j];
			maxAns = max(maxAns, temp);
		}
	}
	cout << maxAns;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}