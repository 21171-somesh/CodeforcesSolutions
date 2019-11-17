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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin >> n;
		vi arr(n), brr(n);
		fr(i, 0, n) cin >> arr[i];
		fr(i, 0, n) cin >> brr[i];
		int flag = 0;
		vi crr(n);
		int pos1 = -1;
		fr(i, 0, n) {
			crr[i] = brr[i] - arr[i];
			if (crr[i] > 0) {
				if (pos1 == -1) {
					pos1 = i;
				}
			}
			if (crr[i] < 0) flag = 1;
		}
		int pos2 = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (crr[i] > 0) {
				pos2 = i;
				break;
			}
		}
		if (pos1 != -1) {
			int ele = crr[pos1];
			fr(i, pos1 + 1, pos2 + 1) {
				if (ele != crr[i]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
 	}
	return 0;
}
