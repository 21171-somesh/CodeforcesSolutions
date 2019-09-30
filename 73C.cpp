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
string s;
ll dp[110][110][27];
map<pair<int, int>, int> mp;
ll func(int pos, int change, int prev) {
	if(pos >= s.size()) return 0;
	if(dp[pos][change][prev] != INT_MIN) {
		return dp[pos][change][prev];
	}
	ll ans = -1e8;
	if(change < k) {
		fr(i, 0, 26) {
			if(s[pos] - 'a' != i) {
				ans = max(ans, func(pos + 1, change + 1, i + 1) + mp[{prev, i + 1}]);
			}
		}
	}
	ans = max(ans, func(pos + 1, change, s[pos] - 'a' + 1) + mp[{prev, s[pos] - 'a' + 1}]) ;
	return dp[pos][change][prev] = ans;
} 

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> s;
	cin >> k >> n;
	fr(i, 0, 110) {
		fr(j, 0, 110) {
			fr(kk, 0, 27) {
				dp[i][j][kk] = INT_MIN;
			}
		}
	}
	fr(i, 0, n) {
		char x, y;
		int cost;
		cin >> x >> y >> cost;
		mp[{x - 'a' + 1, y - 'a' + 1}] = cost;
	}
	cout << func(0, 0, 0);

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
} 