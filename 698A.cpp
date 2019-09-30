//21171_somesh || asomesh999

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
//AC

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n;
	cin >> n;
	vi arr(n);
	fr(i, 0, n) {
		cin >> arr[i];
	}
	vector<vi> dp(4, vi(n));
	dp[0][0] = dp[2][0] = 0;
	dp[1][0] = (arr[0] == 1 || arr[0] == 3);
	dp[3][0] = (arr[0] == 2 || arr[0] == 3);
	fr(i, 1, n) {
		int x = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1], dp[3][i - 1]});
		dp[0][i] = x;
		dp[2][i] = x;

		int flag1 = 0, flag2 = 0;
		if(arr[i] == 1 || arr[i] == 3) flag1 = 1;
		if(arr[i] == 2 || arr[i] == 3) flag2 = 1;

		if(dp[3][i - 1] && dp[1][i - 1]) {
			if(flag1)
				dp[1][i] = dp[3][i - 1] + 1;
			if(flag2)
				dp[3][i] = dp[1][i - 1] + 1;
		} else if(dp[3][i - 1]) {
			if(flag1)
				dp[1][i] = dp[3][i - 1] + 1;
			dp[3][i] = 0;
		} else if(dp[1][i - 1]){
			if(flag2)
				dp[3][i] = dp[1][i - 1] + 1;
			dp[1][i] = 0;
		} else {
			if(flag2)
				dp[3][i] = max(1, x + 1);
			if(flag1)
				dp[1][i] = max(1, x + 1);
		}
	}
	int m = max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1], dp[3][n - 1]});
	cout << n - m;

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}