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
typedef long double ld;
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
	ld weight;
	cin >> weight;
	cout << fixed;
	cout << setprecision(8);
	vl arr(n), brr(n);
	fr(i, 0, n) {
		cin >> arr[i];
	}
	fr(i, 0, n) {
		cin >> brr[i];
	}
	auto func = [&](ld x) {
		ld temp = weight + x;
		int flag = 0;
		fr(i, 0, n) {
			ld use = temp / brr[i];
			if(i != 0) {
				if(x >= use) {
					x -= use;
					temp = weight + x;
				} else {
					flag = 1;
					break;
				}
			}
			use = temp / arr[i];
			if(x >= use) {
				x -= use;
				temp = weight + x;
			} else {
				flag = 1;
				break;
			}
		}
		ld use = temp / brr[0];
		if(use > x) {
			flag = 1;
		}
		return !flag;
	};
	ld low = 0, high = 10e9 + 1;
	ld ans = -1;
	while(low <= high) {
		ld mid = (low + high) / 2;
		if(func(mid)) {
			high = mid - 0.0000001;
			ans = mid;
		} else {
			low = mid + 0.0000001;
		}
	}
	cout << ans;

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}