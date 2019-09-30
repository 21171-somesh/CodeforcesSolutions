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

	int n, m, k;
	cin >> n >> m >> k;
	vi arr(m);
	fr(i, 0, m) {
		cin >> arr[i];
	}
	int b;
	cin >> b;
	int count = 0;
	fr(i, 0, m) {
		int x = (b ^ arr[i]);
		int pop = __builtin_popcount(x);
		if(pop <= k) {
			count++;
		}
	}
	cout << count;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}