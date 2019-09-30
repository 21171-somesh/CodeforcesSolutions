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
const int MAXN = 5000005;

int spf[MAXN], arr[MAXN]; 

void sieve() {
	spf[1] = 1;
	for (int i=2; i<MAXN; i++)
		spf[i] = i;
	for (int i=4; i<MAXN; i+=2) 
		spf[i] = 2;
	for (int i=3; i*i<MAXN; i++) {
		if (spf[i] == i) {
			for (int j=i*i; j<MAXN; j+=i)
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
}
int getFactorization(int x) {
	int count = 0;
	while (x > 1) {
		count++;
		x = x / spf[x];
	}
	return count;
} 

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	memset(spf, 0, sizeof spf);
	sieve();
	int sum = 0;
	fr(i, 0, MAXN) {
		int temp = getFactorization(i);
		sum += temp;
		arr[i] = sum;
	}
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		cout << arr[l] - arr[r] << '\n';

	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}