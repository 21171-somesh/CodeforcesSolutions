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
	vector<pii> point(n);
	fr(i, 0, n) {
		cin >> point[i].first >> point[i].second;
	}
	sort(point.begin(), point.end(), [&](pii a, pii b) {
		return (abs(a.first) + abs(a.second)) < (abs(b.first) + abs(b.second));
	});
	vector<pair<int, pair<int, char>>> ans;
	fr(i, 0, n) {
		int x = point[i].first, y = point[i].second;
		if(x > 0) {
			ans.push_back({1, {x, 'R'}});
		} else if(x < 0) {
			ans.push_back({1, {-x, 'L'}});
		}
		if(y > 0) {
			ans.push_back({1, {y, 'U'}});
		} else if(y < 0) {
			ans.push_back({1, {-y, 'D'}});
		}
		x = -x, y = -y;
		ans.push_back({2, {0, 'a'}});
		if(x > 0) {
			ans.push_back({1, {x, 'R'}});
		} else if(x < 0) {
			ans.push_back({1, {-x, 'L'}});
		}
		if(y > 0) {
			ans.push_back({1, {y, 'U'}});
		} else if(y < 0) {
			ans.push_back({1, {-y, 'D'}});
		}
		ans.push_back({3, {0, 'a'}});
	} 
	cout << ans.size() << '\n';
	fr(i, 0, ans.size()) {
		if(ans[i].first == 1) {
			cout << ans[i].first << ' ' << ans[i].second.first  << ' ' << ans[i].second.second << '\n';
		} else {
			cout << ans[i].first << '\n';
		}
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}