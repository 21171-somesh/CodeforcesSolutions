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

	int n, k;
	cin >> n >> k;
	vi arr(n);
	fr(i, 0, n) {
		cin >> arr[i];
	}
	unordered_map<int, int> mp;
	vi brr;
	fr(i, 0, n) {
		if(mp.find(arr[i]) == mp.end()) {
			mp[arr[i]]++;
			brr.push_back(arr[i]);
			if(brr.size() > k) {
				mp.erase(mp.find(brr[brr.size() - k - 1]));
			}
		}
	}
	cout << min((int) brr.size(), k) << '\n';
	reverse(brr.begin(), brr.end());
	for(int i = 0; i < min((int) brr.size(), k); i++) {
		cout << brr[i] << ' ';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}
