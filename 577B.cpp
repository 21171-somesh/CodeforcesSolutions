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

int k, n;
int dp[1010][1010];
vl arr;
map<ll, int> mp;

int func(int pos, int sum, int taken) {
	if(sum == 0 && taken)
		return 1;
	if(pos >= n) {
		return 0;
	}
	if(dp[pos][sum] != -1) {
		return dp[pos][sum];
	}
	int ans = 0;
	ans |= func(pos + 1, sum, taken) | func(pos + 1, (sum + arr[pos]) % k, taken + 1);
	return dp[pos][sum] = ans;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	arr.resize(n);
	fr(i, 0, n) {
		cin >> arr[i];
	}
	if(n > 1000) {
		ll sum = 0;
		int ans = 0;
		fr(i, 0, n) {
			sum += arr[i];
			sum %= k;
			if(mp[sum] > 0) {
				ans = 1;
				break;
			}
			mp[sum]++;
		}
		if(ans) cout << "YES";
		else cout << "NO";
		return 0;
	}
	int flag = func(0, 0, 0);
	if(flag) {
		cout << "YES";
	} else {
		cout << "NO";
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}