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
	vl arr(n);
	vl pref(n);
	ll sum = 0;
	fr(i, 0, n) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	fr(i, 0, n) {
		sum += arr[i];
		pref[i] = sum;
	}
	vl ans(n);
	fr(i, 0, n) {
		if (i <= m - 1) {
			ans[i] = pref[i];
		} else {
			ans[i] = pref[i - 1] + arr[i] + ans[i - m];

		}
	}
	for (auto it : ans) {
		cout << it << ' ';
	}
	return 0;
}
