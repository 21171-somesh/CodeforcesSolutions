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

ll dp[200010];
int n;
vector<pii> arr, anss;

bool check(int pos) {
	return (pos < n && pos >= 0);
}

ll rec(int pos) {
	if (pos >= n) {
		return 0;
	}
	ll &ans = dp[pos];
	if (ans != -1) return ans;
	ans = INT_MAX;
	fr(i, 2, 5) {
		if (check(pos + i)) {
			ans = min(ans, rec(pos + i + 1) + arr[pos + i].first - arr[pos].first);
		}
	}
	return ans;
}

int num = 0;

void trace(int pos) {
	if (pos >= n) {
		return;
	}
	if (pos + 2 >= n) {
		return;
	}
	ll ans = dp[pos];
	anss[pos].second = num++;
	fr(i, 3, 6) {
		if (check(pos + i)) {
			if (dp[pos + i] + arr[pos + i - 1].first - arr[pos].first == ans) {
				trace(pos + i);
				return;
			}
		}
	}
	return;
}

int main()
{
	io
	cin >> n;
	arr.resize(n);
	anss.resize(n);
	fr(i, 0, n) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());
	memset(dp, -1, sizeof dp);
	ll ans = rec(0);
	trace(0); 
	anss[n - 1].second = 0;
	fr(i, 0, n - 1) {
		anss[i].second = anss[i + 1].second;
	}
	anss[n - 1].second = num;
	for(int i = n - 2; i >= 0; i--) {
		if (anss[i].second == 0) {
			anss[i].second = anss[i + 1].second;
		}
	}
	fr(i, 0, n) {
		anss[i].first = arr[i].second;
	}
	sort(anss.begin(), anss.end());
	cout << ans << ' ' << num << '\n';
	for(auto it : anss) {
		cout << it.second << ' ';
	}
	return 0;
}
