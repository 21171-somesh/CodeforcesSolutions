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

ll dp[2001][2001][2];
ll m, d;
string s, t;
int size;

bool check(string str) {
	ll rem = 0;
	int flag = 0;
	fr(i, 0, size) {
		if(i % 2 == 0) {
			if(str[i] - '0' == d) {
				flag = 1;
				break;
			} else {
				rem = (rem * 10 + str[i] - '0') % m;
			}
		} else {
			if(str[i] - '0' == d) {
				rem = (rem * 10 + str[i] - '0') % m;
			} else {
				flag = 1;
				break;
			}
		}
	}
	if(flag || rem) {
		return 0;
	} else {
		return 1;
	}
}

ll func(ll tight, ll pos, ll rem) {
	if(pos >= size) {
		if(rem == 0) {
			return 1;
		} else return 0;
	}
	if(dp[pos][rem][tight] != -1) {
		return dp[pos][rem][tight];
	}
	ll ans = 0;
	if(pos % 2 == 0) {
		if(tight) {
			for(int i = 0; i < s[pos] - '0'; i++) {
				if(i == d) continue;
				ans = (ans % mod + func(0, pos + 1, (rem * 10 + i) % m) % mod) % mod;
			}
			if(s[pos] - '0' != d)
			ans = (ans % mod + func(1, pos + 1, (rem * 10 + s[pos] - '0') % m) % mod) % mod;
		} else {
			for(int i = 0; i < 10; i++) {
				if(i == d) continue;
				ans = (ans % mod + func(0, pos + 1, (rem * 10 + i) % m) % mod) % mod; 
			}
		}
	} else {
		if(tight) {
			if(s[pos] - '0' < d) return 0;
			else if(s[pos] - '0' == d)	
				ans = (ans % mod + func(1, pos + 1, (rem * 10 + d) % m) % mod) % mod;
			else
				ans = (ans % mod + func(0, pos + 1, (rem * 10 + d) % m) % mod) % mod;
		} else {
			ans = (ans % mod + func(0, pos + 1, (rem * 10 + d) % m) % mod) % mod;
		}
	}
	return dp[pos][rem][tight] = ans % mod;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> m >> d;
	cin >> s >> t;
	size = s.size();
	memset(dp, -1, sizeof dp);
	ll ans1 = func(1, 0, 0);
	swap(s, t);
	memset(dp, -1, sizeof dp);
	ll ans2 = func(1, 0, 0);
	cout << (ans2 - ans1 + check(t) + mod) % mod; 

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}