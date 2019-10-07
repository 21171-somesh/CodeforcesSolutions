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
	vi ans(s.size());
	ans[0] = 1;
	int length = 1;
	vector<char> search(s.size());
	search[0] = s[0];
	fr(i, 1, s.size()) {
		auto pos = lower_bound(search.begin(), search.begin() + length, s[i]) - search.begin();
		search[pos] = s[i];
		length = pos + 1;
		ans[i] = length;
	}
	fr(i, 0, s.size()) {
		int a = ans[i] - 1;
		if(a == 0) {
			cout << "Mike\n";
		} else {
			cout << "Ann\n";
		}
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}