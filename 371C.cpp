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

	string s;
	cin >> s;
	ll nb, ns, nc;
	cin >> nb >> ns >> nc;
	ll pb, ps, pc;
	cin >> pb >> ps >> pc;
	ll cost;
	cin >> cost;
	ll totb = 0, tots = 0, totc = 0;
	fr(i, 0, s.size()) {
		if(s[i] == 'B') {
			totb++;
		} else if(s[i] == 'C') {
			totc++;
		} else {
			tots++;
		}
	}
	auto func = [&](ll mid) {
		ll totCost = (max(0LL, mid * totb - nb) * pb + max(0LL, mid * tots - ns) * ps + max(0LL, mid * totc - nc) * pc);
		// cout << totCost << '\n';
		return cost >= totCost;

	};
	ll total = 0;
	ll high = 1e13, low = 0;
	while(low <= high) {
		ll mid = (high + low) / 2;
		if(func(mid)) {
			total = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << total;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}