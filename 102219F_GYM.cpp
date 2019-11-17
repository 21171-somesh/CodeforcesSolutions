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
map<pii, int> mp;

int dp[2000][(1 << 10)];
int e, n;

bool check(ll pos, ll val, ll i) {
	ll newPos = pos - e + i;
	return (newPos >= 0 && newPos < n && (val & (1 << i)) == 0 && mp.find({pos, newPos}) == mp.end());
}

ll func(ll pos, ll val) {
	if(pos == n) {
		return 1;
	}
	if(dp[pos][val] != -1) {
		return dp[pos][val];
	}
	ll ans = 0;
	fr(i, 0, 2 * e + 1) {
		if(check(pos, val, i)) {
			ans = (ans + func(pos + 1, ((val | (1LL << i)) >> 1))) % mod;
		}
	}
	return dp[pos][val] = ans;
}

int main()
{
	io
	ll k;
	cin >> n >> e >> k;
	fr(i, 0, k) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		mp[{u, v}] = 1;
	}
	memset(dp, -1, sizeof dp);
	ll ans = func(0, 0); 
	cout << ans;
	return 0;
}
