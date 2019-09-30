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

	int n, p;
	cin >> n >> p;
	p--;
	if(p >= n / 2) {
		p = n - p - 1;
	}
	string s;
	cin >> s;
	int maxPos = 0;
	int pos = -1;
	ll sum = 0;
	fr(i, 0, n / 2) {
		if(s[i] != s[n - i - 1]) {
			maxPos = max((ll)maxPos, i);
			if(pos == -1) {
				pos = i;
			}
			ll temp = abs(s[n - i - 1] - s[i]);
			ll temp1 = s[i] - 'a' + 1LL + abs(s[n - i - 1] - 'z');
			ll temp2 = abs(s[i] - 'z') + 1LL + abs(s[n - i - 1] - 'a');
			temp = min({temp, temp1, temp2});
			sum += temp;
		}
	}
	if(pos == -1) {
		cout << 0;
		return 0;
	}
	ll temp = (max(maxPos, p) - p) * 2 + (p - pos);
	ll temp2 = (p - min(pos, p)) * 2 + (maxPos - p);
	sum += min(temp, temp2);
	cout << sum;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}