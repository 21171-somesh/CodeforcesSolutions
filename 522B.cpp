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
	vector<pair<ll, pll>> arr(n);
	ll sum = 0;
	fr(i, 0, n) {
		cin >> arr[i].second.first >> arr[i].second.second;
		sum += arr[i].second.first;
		arr[i].first = i;
	}
	sort(arr.begin(), arr.end(), [&](pair<ll, pll> a, pair<ll, pll> b) {
		return a.second.second > b.second.second;
	});
	vector<ll> ans(n);
	ll maxVal = arr[0].second.second;
	fr(i, 0, n) {
		ll tempSum = sum - arr[i].second.first;
		ll tempMaxVal = maxVal;
		if (i == 0) {
			tempMaxVal = arr[1].second.second;
		}
		ans[arr[i].first] = tempSum * tempMaxVal;
	}
	for(auto it : ans) {
		cout << it << ' ';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}
