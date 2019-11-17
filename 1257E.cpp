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

unordered_map<int, int> mp1, mp2, mp3;
int dp[200010][3];
int n;
int recurse(int pos, int part) {
	if (pos >= n + 1) {
		return 0;
	}
	int &ans = dp[pos][part];
	if (ans != -1) return ans;
	ans = (2e9) + 20; 
	if (part == 0) {
		if (mp1.find(pos) != mp1.end()) {
			ans = min(ans, recurse(pos + 1, part));
		} else {
			ans = min(ans, 1 + recurse(pos + 1, part));
		}
		ans = min(ans, recurse(pos, part + 1));
	} else if (part == 1) {
		if (mp2.find(pos) != mp2.end()) {
			ans = min(ans, recurse(pos + 1, part));
		} else {
			ans = min(ans, 1 + recurse(pos + 1, part));
		}
		ans = min(ans, recurse(pos, part + 1));
	} else {
		if (mp3.find(pos) != mp3.end()) {
			ans = min(ans, recurse(pos + 1, part));
		} else {
			ans = min(ans, 1 + recurse(pos + 1, part));
		}
	}
	return ans;
}

int main()
{
	io
	ll k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	n = k1 + k2 + k3;
	int x;
	fr(i, 0, k1) {
		cin >> x;
		mp1[x]++;
	}
	fr(i, 0, k2) {
		cin >> x;
		mp2[x]++;
	}
	fr(i, 0, k3) {
		cin >> x;
		mp3[x]++;
	}
	memset(dp, -1, sizeof dp);
	cout << min({recurse(1, 0), recurse(1, 1), recurse(1, 2)});
	return 0;
}
