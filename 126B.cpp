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
 
vi z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
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
	int n = s.size();
	vi z = z_function(s);
	int maxEle = 0;
	unordered_map<int, int> m;
	set<int> st;
	for(int i = n - 1, j = 1; i >= 0 && j <= n; i--, j++) {
		if(z[i] == j) {
			m[z[i]]++;
			st.insert(z[i] - 1);
		} else if(z[i] < j) {
			st.insert(z[i]);
		}
	}
	for(auto it : m) {
		if(st.lower_bound(it.first) != st.end()) {
			maxEle = max(maxEle, it.first);
		}
	}
	if(maxEle) {
		fr(i, 0, maxEle) {
			cout << s[i];
		}
	} else {
		cout << "Just a legend";
	}
 
	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}