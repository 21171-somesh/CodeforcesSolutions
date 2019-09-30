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

	int n;
	cin >> n;
	vi arr(n);
	unordered_map<int, int> mp1;
	fr(i, 0, n) {
		cin >> arr[i];
		mp1[arr[i]]++;
	}
	if(n == 1) {
		cout << -1;
		return 0;
	}
	if(mp1.size() == 1) {
		cout << "1\n";
		cout << mp1.begin()->first;
		return 0;
	}
	sort(arr.begin(), arr.end());
	vi diff(n - 1);
	map<int, int> mp;
	fr(i, 1, n) {
		diff[i - 1] = arr[i] - arr[i - 1];
		mp[diff[i - 1]]++;
	}
	vi ans;
	if(mp.size() == 1) {
		if(n == 2) {
			if((arr[1] - arr[0]) % 2 == 0 && (arr[1] - arr[0]) > 1) {
				ans.push_back(arr[0] + (arr[1] - arr[0]) / 2);
			}
		}
		ans.push_back(arr[0] - diff[0]);
		ans.push_back(arr[n - 1] + diff[0]);
	} else if(mp.size() == 2) {
		int diff1 = mp.begin()->first;
		int diff2 = mp.rbegin()->first;
		if(diff1 == 0 || (mp.rbegin()->second != 1) || 2 * diff1 != diff2) {
			cout << 0;
			return 0;
		}
		fr(i, 1, n) {
			if(arr[i] - arr[i - 1] == diff2) {
				ans.push_back(arr[i - 1] + (arr[i] - arr[i - 1]) / 2);
			}
		}
	} else {
		cout << 0;
		return 0;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	fr(i, 0, ans.size()) {
		cout << ans[i] << ' ';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}