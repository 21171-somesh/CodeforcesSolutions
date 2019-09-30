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
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n;
	cin >> n;
	vi arr(n);
	fr(i, 0, n) {
		cin >> arr[i];
	}
	if(n <= 2) {
		cout << n;
		return 0;
	}
	vi dp1(n), dp2(n);
	dp1[0] = 1;
	int count = 1;
	fr(i, 1, n) {
		if(arr[i] > arr[i - 1]) {
			count++;
		} else {
			count = 1;
		}
		dp1[i] = count;
	}
	count = 1;
	dp2[n - 1] = 1;
	for(int i = n - 2; i >= 0; i--) {
		if(arr[i] < arr[i + 1]) {
			count++;
		} else {
			count = 1;
		}
		dp2[i] = count;
	}
	int maxLen = 1;
	fr(i, 0, n) {
		if(i == 0) {
			maxLen = max(dp2[i + 1] + 1, maxLen);
		}
		else if(i == n - 1) {
			maxLen = max(dp1[i - 1] + 1, maxLen);
		} else {
			int x = dp2[i + 1], y = dp1[i - 1];
			int diff = arr[i + 1] - arr[i - 1];
			if(diff > 1) {
				maxLen = max(maxLen, x + y + 1);
			}
			maxLen = max({maxLen, x + 1, y + 1});
		}
		maxLen = max(maxLen, dp1[i]);
	}
	cout << maxLen;

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}