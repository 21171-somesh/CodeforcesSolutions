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
	int n = s.size();
	vector<pair<char, int>> arr;
	int num = 1;
	fr(i, 1, n) {
		if(i == 1) {
			if(s[i - 1] == s[i]) {
				num = 2;
			} else {
				num = 1;
				arr.push_back({s[0], 1});
			}
			continue;
		}
		if(s[i] == s[i - 1]) {
			num++;
		} else {
			if(num >= 2) {
				if(arr.size() == 0) {
					arr.push_back({s[i - 1], 2});
				} else if(arr.back().second == 2) {
					arr.push_back({s[i - 1], 1});
				} else {
					arr.push_back({s[i - 1], 2});
				}
			} else {
				arr.push_back({s[i - 1], 1});
			}
			num = 1;
		}
	}
	if(num == 1) {
		arr.push_back({s[n - 1], 1});
	} else if(num >= 2) {
		if(arr.size() == 0) {
			arr.push_back({s[n - 1], 2});
		} else if(arr.back().second == 2) {
			arr.push_back({s[n - 1], 1});
		} else {
			arr.push_back({s[n - 1], 2});
		}
	}
	string t;
	fr(i, 0, arr.size()) {
		fr(j, 0, arr[i].second) {
			t.push_back(arr[i].first);
		}
	}
	cout << t;
 
	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}