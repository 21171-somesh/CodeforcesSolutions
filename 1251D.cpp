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
		ll n, s;
		cin >> n >> s;
		vector<pii> arr(n);
		fr(i, 0, n) {
			cin >> arr[i].first >> arr[i].second;
		}
		auto func = [&] (ll x) {
			ll total = 0;
			ll count = 0;
			vector<int> brr;
			fr(i, 0, n) {
				if (arr[i].second < x) {
					total += arr[i].first;
				} else if (arr[i].first >= x) {
					total += arr[i].first;
					count++;
				} else {
					brr.push_back(arr[i].first);
				}
			}
			sort(brr.begin(), brr.end());
			int rem = max(0LL, (n + 1) / 2 - count);
			if (rem > brr.size()) {
				return false;
			}
			total += (rem) * x;
			for(int i = 0; i < brr.size() - rem; i++) {
				total += brr[i];
			}
			return (total <= s);
		};
		ll low = 0, high = 1e12;
		ll ans = -1;
		while (low <= high) {
			ll mid = (low + high) / 2;
			if (func(mid)) {
				ans = mid;
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
