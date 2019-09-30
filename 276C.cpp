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

	int n, q;
	cin >> n >> q;
	vl arr(n);
	fr(i, 0, n) {
		cin >> arr[i];
	}
	vl brr(n);
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--, r;
		brr[l] += 1;
		if(r < n) {
			brr[r] -= 1;
		}
	}
	fr(i, 1, n) {
		brr[i] += brr[i - 1];
	}
	sort(arr.rbegin(), arr.rend());
	sort(brr.rbegin(), brr.rend());
	ll sum = 0;
	fr(i, 0, n) {
		if(brr[i] > 0) {
			sum += arr[i] * brr[i];
		}
	}
	cout << sum;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}