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

int main()
{
	io
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin >> n;
		vl arr(n);
		fr(i, 0, n) {
			cin >> arr[i];
		}
		auto func = [&] (ll x) {
			map<int, int> mp;
			for(int i = 0; i < n; i++) {
				if (i >= x) {
					mp[arr[i - x]]--;
				}
				mp[arr[i]]++;
				if (mp[arr[i]] > 1) {
					return true;
				}
			}
			return false;
		};
		ll ans = -1;
		ll low = 2, high = n;
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (func(mid)) {
				ans = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
