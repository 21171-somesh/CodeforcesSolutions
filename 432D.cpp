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

vector<ll> z_function(string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	string s;
	cin >> s;
	ll n = (ll)s.size();
	vl arr = z_function(s);
	vi pos;
	fr(i, 0, n) {
		if(arr[n - i - 1] == i + 1) {
			pos.push_back(i + 1);
		}
	}
	map<int, int> mp;
	fr(i, 0, n) {
		mp[arr[i]]++;
	}
	int ans = pos.size() + 1;
	cout << ans << '\n';
	vector<pii> ar;
	for(auto it : mp) {
		ar.push_back({it.first, it.second});
	}
	for(int i = ar.size() - 1; i > 0; i--) {
		ar[i - 1].second += ar[i].second;
		mp[ar[i - 1].first] = ar[i - 1].second;
	}
	fr(i, 0, pos.size()) {
		cout << pos[i] << ' ' << mp[pos[i]] + 1 << '\n';
	}
	cout << s.size() << ' ' << 1 << '\n';

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}