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

ll n;
bool func(ll x) {
	string s;
	while(x) {
		if(x & 1) {
			s.push_back('1');
		} else {
			s.push_back('0');
		}
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	ll ans = stol(s);
	return (ans <= n);
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> n;
	ll x = 1;
	while(func(x)) {
		x++;
	}
	cout << x - 1;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}