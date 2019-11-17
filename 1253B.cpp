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
	int n;
	cin >> n;
	vl arr(n);
	fr(i, 0, n) cin >> arr[i];
	map<int, int> mp;
	set<int> st;
	int flag = 0;
	vector<int> ans;
	fr(i, 0, n) {
		if (arr[i] < 0) {
			auto it = st.find(-arr[i]);
			if (it == st.end()) {
				flag = 1;
				break;
			} else {
				st.erase(it);
				if (st.empty()) {
					mp.clear();
					ans.push_back(i);
				}
			}
		} else {
			if (st.find(abs(arr[i])) == st.end()) {
				if (mp.find(abs(arr[i])) == mp.end()) {
					st.insert(arr[i]);
					mp[arr[i]]++;
				} else {
					flag = 1;
					break;
				}
			} else {
				flag = 1;
				break;
			}
		}
	}
	if (!st.empty()) {
		flag = 1;
	}
	if (flag) {
		cout << -1;
		return 0;
	}
	cout << (int) ans.size() << '\n';
	int prev = 0;
	for(auto it : ans) {
		cout << it + 1 - prev << ' ';
		prev = it + 1;
	}
	return 0;
}
