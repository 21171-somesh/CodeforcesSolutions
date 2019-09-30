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

int dp[100011][2];
int k;

ll func(int pos, int prev) {
	if(pos <= 0) {
		return 0;
	}
	if(dp[pos][prev] != -1) {
		return dp[pos][prev];
	}
	ll ans = 0;
	ans = (ans + func(pos - 1, 0) + 1) % mod;
	if(pos - k >= 0)
		ans = (ans + func(pos - k, 1) + 1) % mod;
	return dp[pos][prev] = ans % mod;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int T;
	cin >> T >> k;
	memset(dp, -1, sizeof dp);
	func(100010, 0);
	while(T--)
	{	
		int a, b;
		cin >> a >> b;
		cout << (func(b, 0) - func(a - 1, 0) + mod) % mod << "\n";
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}