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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	string s, t;
	cin >> s >> t;
	if(t.size() > s.size()) {
		cout << s;
		return 0;
	}
	int zero = 0, one = 0;
	fr(i, 0, s.size()) {
		if(s[i] == '1')	one++;
		else zero++;
	}
	vi len = prefix_function(t);
	// cout << len << '\n';
	int i = 0;
	fr(j, 0, t.size()) {
		if(i == s.size()) break;
		if(t[j] == '0') {
			if(zero > 0) {
				cout << 0;
				zero--;
			} else {
				cout << 1;
				one--;
			}
		} else {
			if(one > 0) {
				cout << 1;
				one--;
			} else {
				cout << 0;
				zero--;
			}
		}
		i++;
	}
	while(s.size() > i) {
		fr(j, len[len.size() - 1], t.size()) {
			if(i == s.size()) break;
			if(t[j] == '0') {
				if(zero > 0) {
					cout << 0;
					zero--;
				} else {
					cout << 1;
					one--;
				}
			} else {
				if(one > 0) {
					cout << 1;
					one--;
				} else {
					cout << 0;
					zero--;
				}
			}
			i++;
		}
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}