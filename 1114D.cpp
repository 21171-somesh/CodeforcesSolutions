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
vi arr, brr;
int dp[5010][5010];
int size;

int rec(int left, int right) {
	if (left == right) {
		return 0;
	}
	int &ans = dp[left][right];
	if (ans != -1) {
		return ans;
	}
	ans = INT_MAX;
	if (brr[left] == brr[right]) {
		ans = rec(left + 1, right - 1) + 1;
	}
	ans = min({ans, rec(left + 1, right) + 1, rec(left, right - 1) + 1});
	return ans;
}

int main()
{
	io
	cin >> n;
	arr.resize(n);
	fr(i, 0, n) cin >> arr[i];
	brr.push_back(arr[0]);
	fr(i, 1, n) {
		if (arr[i] != arr[i - 1]) {
			brr.push_back(arr[i]);
		}
	}
	size = (int) brr.size();
	memset(dp, -1, sizeof dp);
	cout << rec(0, size - 1);
	return 0;
}
