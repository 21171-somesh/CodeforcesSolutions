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
vi arr;
ll dp[110][110][110][3];

ll recurse(int pos, int prev, int even, int odd) {
	if (pos >= n) {
		return 0;
	}
	ll &ans = dp[pos][even][odd][prev];
	if (ans != -1) return ans;
	ans = INT_MAX;
	if (arr[pos] == 0) {
		if (odd) {
			int add = (prev == 1) ? 1 : 0;
			ans = min(ans, recurse(pos + 1, 2, even, odd - 1) + add); 
		} 
		if (even) {
			int add = (prev == 2) ? 1 : 0;
			ans = min(ans, recurse(pos + 1, 1, even - 1, odd) + add);
		}
	} else {
		int add = 0;
		if (prev == 1) {
			add = (arr[pos] % 2 == 0) ? 0 : 1;
		} else if (prev == 2) {
			add = (arr[pos] % 2) ? 0 : 1;
		}
		ans = min(ans, recurse(pos + 1, (arr[pos] % 2) + 1, even, odd) + add);
	}
	return ans;
}

int main()
{
	io
	cin >> n;
	arr.resize(n);
	int even = 0, odd = 0;
	fr(i, 0, n) {
		cin >> arr[i];
		if (arr[i] == 0) continue;
		if (arr[i] % 2 == 0) even++;
		else odd++;
	}
	even = n / 2 - even;
	odd = (n + 1) / 2 - odd;
	memset(dp, -1, sizeof dp);
	cout << recurse(0, 0, even, odd);
	return 0;
}
