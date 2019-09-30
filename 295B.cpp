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
	vector<vl> mat(n, vl(n));
	fr(i, 0, n) fr(j, 0, n) {
		cin >> mat[i][j];
	}
	vl arr(n), ans(n);
	vi taken(n);
	fr(i, 0, n) {
		cin >> arr[i];
		arr[i]--;
	}
	fr(i, 0, n) {
		int ele = arr[n - i - 1];
		taken[ele] = 1;
		ll temp = 0;
		fr(j, 0, n) fr(k, 0, n) {
			mat[j][k] = min(mat[j][k], mat[j][ele] + mat[ele][k]);
			if(taken[j] && taken[k]) {
				temp += mat[j][k];
			}
		}
		ans[n - i - 1] = temp;
	}
	fr(i, 0, n) {
		cout << ans[i] << ' ';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}