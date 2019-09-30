/******************************************
*******************************************
*******************************************
	PREPARED BY - SOMESH AWASTHI 
	CHANDIGARH UNIVERSITY
*******************************************
*******************************************
*******************************************/

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
	// #ifdef SOMU
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// #endif
	int n;
	cin >> n;
	vl arr(n);
	int count = 0, zero = 0;
	fr(i, 0, n) {
		cin >> arr[i];
		if(arr[i] < 0) count++;
		if(arr[i] == 0) zero++;
	}
	int temp = 0, temp1 = 0;
	int minEle = INT_MAX;
	fr(i, 0, n) {
		if(arr[i] < 0) {
			temp++;
		} else if(arr[i] == 0) {
			temp1++;
		}
		minEle = min(int(i) + 1 + count - 2 * temp - temp1, minEle);
	}
	cout << minEle + zero;
	return 0;
}