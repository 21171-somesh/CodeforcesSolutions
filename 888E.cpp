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
set<ll> first, second;
vl arr;
ll size;
void func1(ll pos, ll sum) {
	if (pos >= size) {
		first.insert(sum % mod);
		return;
	}
	func1(pos + 1, sum);
	func1(pos + 1, (sum + arr[pos]) % mod);
}
void func2(ll pos, ll sum) {
	if (pos >= size) {
		second.insert(sum % mod);
		return;
	}
	func2(pos + 1, sum);
	func2(pos + 1, (sum + arr[pos]) % mod);
}

int main() {
	io
	cin >> n >> mod;
	arr.resize(n);
	fr(i, 0, n) cin >> arr[i];
	int mid = n / 2;
	size = mid;
	func1(0, 0);
	size = n;
	func2(mid, 0);
	ll ans = 0;
	for(auto it : first) {
		auto it1 = second.lower_bound(mod - (it) - 1);
		if (it1 == second.end()) {
			it1--;
		}
		while(it + (*it1) >= mod) {
			it1--;
		}
		ans = max(ans, it);
		ans = max(ans, *it1);
		ans = max(ans, *it1 + it);
	}
	cout << ans;
	return 0;
}
