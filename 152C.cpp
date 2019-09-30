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

	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat(n, vector<char>(m));
	unordered_map<char, int> mp[m];
	fr(i, 0, n) {
		fr(j, 0, m) {
			cin >> mat[i][j];
			mp[j][mat[i][j]]++;
		}
	}
	ll ans = 1;
	fr(i, 0, m) {
		ans = (ans * mp[i].size()) % mod; 
	}
	cout << ans;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}