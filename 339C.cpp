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

ll m;
vi brr;
ll dp[1010][20][20];

int rec(ll k, ll diff, ll prev) {
	if(k == m) {
		return dp[k][diff][prev] = 1;
	}
	if(dp[k][diff][prev] != -1) {
		return dp[k][diff][prev];
	}
	ll ans = 0;
	fr(i, 0, brr.size()) {
		if(brr[i] > diff && brr[i] != prev) {
			ans |= rec(k + 1, brr[i] - diff, brr[i]);
		}
	}
	return dp[k][diff][prev] = ans;
}

void print(ll k, ll diff, ll prev) {
	if(k == m) {
		return;
	}
	fr(i, 0, brr.size()) {
		if(brr[i] > diff && prev != brr[i] && rec(k + 1, brr[i] - diff, brr[i])) {
			cout << brr[i] << ' ';
			print(k + 1, brr[i] - diff, brr[i]);
			return;
		}
	} 
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	string s;
	cin >> s;
	fr(i, 0, s.size()) {
		if(s[i] == '1') {
			brr.push_back(i + 1);
		}
	}
	cin >> m;
	fr(i, 0, 1010) {
		fr(j, 0, 20) {
			fr(k, 0, 20) {
				dp[i][j][k] = -1;
			}
		}
	}
	int flag = rec(0, 0, 0);
	if(flag != 1) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	print(0, 0, 0);

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}