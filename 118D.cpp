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
long int mod=100000000;

int dp[110][110][12][2];
int n1, n2, k1, k2;

int func(int first, int second, int prev, int consec) {
	if(first + second >= n1 + n2) {
		return 1;
	}
	if(dp[first][second][consec][prev] != -1) {
		return dp[first][second][consec][prev];
	}
	int ans = 0;
	if(prev == 0) {
		if(first < n1 && consec < k1)
			ans = (ans + func(first + 1, second, prev, consec + 1)) % mod;
		if(second < n2)
			ans = (ans + func(first, second + 1, 1, 1)) % mod;
	} else {
		if(second < n2 && consec < k2)
			ans = (ans + func(first, second + 1, prev, consec + 1)) % mod;
		if(first < n1)
			ans = (ans + func(first + 1, second, 0, 1)) % mod;
	}
	return dp[first][second][consec][prev] = ans % mod;
}
 
int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp, -1, sizeof dp);
	cout << func(0, 0, 0, 0);

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}