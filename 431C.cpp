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

vector<vector<vl>> dp(110, vector<vl>(110, vl(2, -1)));

ll d;
ll func(ll w, ll k, int done = 0) {
	if(w == 0) {
		if(done == 1)
			return 1;
		else
			return 0;
	}
	if(dp[w][k][done] != -1) {
		return dp[w][k][done];
	}
	ll ways = 0;
	fr(i, 1, k + 1) {
		if(i <= w) {
			if(i >= d)
				ways = (ways + func(w - i, k, 1)) % mod;
			else
				ways = (ways + func(w - i, k, done)) % mod;
		}
	}
	return dp[w][k][done] = (ways % mod);
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n, k;
	cin >> n >> k >> d;
	ll ways = 0;
	ways = func(n, k);
	cout << ways;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}