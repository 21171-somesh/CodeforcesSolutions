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

ll n;
ll dp[300010][3];
vector<pll> arr(300010);

ll rec(ll pos, ll prev) {
	if (pos >= n) {
		return 0;
	}
	ll &ans = dp[pos][prev];
	if (ans != -1) return dp[pos][prev];
	ll val = arr[pos - 1].first + prev;
	ans = (2e18);
	if (val != arr[pos].first) {
		ans = min(ans, rec(pos + 1, 0));
	}
	if (val != arr[pos].first + 1) {
		ans = min(ans, rec(pos + 1, 1) + arr[pos].second);
	}
	if (val != arr[pos].first + 2) {
		ans = min(ans, rec(pos + 1, 2) + 2 * arr[pos].second);
	}
	return ans;
}

int main() {
	io
	int T;
	cin>>T;
	while(T--) {
		cin >> n;
		fr(i, 0, n) {
			cin >> arr[i].first >> arr[i].second;
		}
		memset(dp, -1, sizeof (ll) * 3 * n);
		cout << min({rec(1, 0), rec(1, 1) + arr[0].second, rec(1, 2) + 2 * arr[0].second}) << '\n';
	}
	return 0;
}
