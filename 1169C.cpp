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
	int n, m;
	cin >> n >> m;
	vi arr(n);
	fr(i, 0, n) cin >> arr[i];
	auto func = [&] (int x) {
		int prev = 0, flag = 0;
		for(int i = 0; i < n; i++) {
			if (prev > arr[i]) {
				if (((prev - arr[i] + m) % m) > x) {
					flag = 1;
					break;
				}
			} else {
				if ((prev - arr[i] + m) % m > x) {
					prev = arr[i];
				}
			}
		}
		if (flag) return false;
		else return true;
	};
	int low = 0, high = m - 1, ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (func(mid)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
