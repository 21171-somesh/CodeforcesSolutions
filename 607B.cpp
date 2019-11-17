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
int dp[510][510];

int rec(int left, int right) {
	if (left == right) {
		return 1;
	}
	if (left > right) {
		return 0;
	}
	int &ans = dp[left][right];
	if (ans != -1) return ans;
	ans = (1e9 + 10);
	for (int i = right; i > left; i--) {
		if (arr[left] == arr[i]) {
			if (left + 1 == i)
				ans = min(ans, rec(left + 2, right) + 1);
			else
				ans = min(ans, rec(left + 1, i - 1) + rec(i + 1, right));
		}
	}
	ans = min(ans, rec(left + 1, right) + 1);
	return ans;
}

int main()
{
	io
	cin >> n;
	arr.resize(n);
	fr(i, 0, n) cin >> arr[i];
	memset(dp, -1, sizeof dp);
	cout << rec(0, n - 1);
	return 0;
}
