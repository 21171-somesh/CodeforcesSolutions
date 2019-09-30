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
	vector<pii> arr(n);
	fr(i, 0, n) {
		cin >> arr[i].first >> arr[i].second;
	}
	int count = 1, prev = arr[0].first;
	fr(i, 1, n) {
		if(arr[i].first - arr[i].second > prev) {
			prev = arr[i].first;
			count++;
		} else if(i < n - 1) {
			if(arr[i].first + arr[i].second < arr[i + 1].first) {
				count++;
				prev = arr[i].first + arr[i].second;
			} else {
				prev = arr[i].first;
			}
		} else {
			count++;
		}
	}
	cout << count;

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}