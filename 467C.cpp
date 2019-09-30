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
vl arr, pref;
ll dp[5010][5010];

ll func(int pos, int count) {
	if(pos >= n || count == k) {
		return 0;
	}
	if((k - count) * m > (n - pos)) {
		return INT_MIN;
	}
	if(dp[pos][count] != -1) {
		return dp[pos][count];
	}
	return dp[pos][count] = max(func(pos + 1, count), 
		func(pos + m, count + 1) + pref[pos + m - 1] - ((pos - 1 >= 0) ? pref[pos - 1] : 0));
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	arr.resize(n);
	pref.resize(n);
	ll sum = 0;
	fr(i, 0, n) {
		cin >> arr[i], sum += arr[i];
		pref[i] = sum;
	}
	cout << func(0, 0);

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}