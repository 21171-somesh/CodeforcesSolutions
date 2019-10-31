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
int n;
vi A, B, C;
int dp[3010][2];

int rec(int pos, int type) {
	if (pos >= n) {
		return 0;
	} 
	int &ans = dp[pos][type];
	if (ans != -1) {
		return dp[pos][type];
	}
	if (pos == 0) {
		ans = max(rec(pos + 1, 0) + B[pos], rec(pos + 1, 1) + A[pos]);
	} else if (pos == n - 1) {
		if (type) 
			ans = rec(pos + 1, 1) + B[pos];
		else
			ans = rec(pos + 1, 1) + A[pos];
	} else if (type == 0) {
		ans = max(rec(pos + 1, 0) + B[pos], rec(pos + 1, 1) + A[pos]);
	} else {
		ans = max(rec(pos + 1, 1) + B[pos], rec(pos + 1, 0) + C[pos]);
	}
	return ans;
}

int main()
{
	io
	cin >> n;
	A.resize(n), B.resize(n), C.resize(n);
	fr(i, 0, n) cin >> A[i];
	fr(i, 0, n) cin >> B[i];
	fr(i, 0, n) cin >> C[i];
	if (n == 1) {
		cout << A[0];
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0);
	return 0;
}
