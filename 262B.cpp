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
	int count[26] = {0};
	fr(i, 0, s.size()) {
		count[s[i] - 'a']++;
	}
	int c = 0;
	fr(i, 0, 26) {
		if(count[i] % 2 != 0) {
			c++;
		}
	}
	c = max(0, c - 1);
	if(c % 2 == 0) {
		cout << "First";
	} else {
		cout << "Second";
	}

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}