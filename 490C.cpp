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

string s;

void print(ll pos) {
	fr(i, 0, pos) {
		cout << s[i];
	}
	cout << '\n';
	fr(i, pos, s.size()) {
		cout << s[i];
	}
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> s;
	ll n = s.size();
	ll a, b;
	cin >> a >> b;
	mod = b;
	string sa = to_string(a), sb = to_string(b);
	vl rem(n), suff(n);
	if(sa.size() + sb.size() > n) {
		cout << "NO";
		return 0;
	}
	ll r = 0;
	fr(i, 0, n) {
		r = (r * 10 + s[i] - '0') % a;
		rem[i] = r;
	}
	r = 0;
	ll ten = 1;
	for(ll i = n - 1; i >= 0; i--) {
		r = ((s[i] - '0') * ten + r) % b;
		suff[i] = r;
		ten = (ten * 10) % b;
	}
	fr(i, 1, n) {
		if((rem[i - 1] == suff[i] && rem[i - 1] == 0) && s[i] != '0') {
			cout << "YES\n";
			print(i);
			return 0;
		}
	}
	cout << "NO";

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}