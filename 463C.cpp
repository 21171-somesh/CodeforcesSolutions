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
int n;
vector<vl> mat;
vector<vl> dp1, dp2;

ll getSum1(int i, int j) {
	ll sum = 0;
	int minNum = min(n - i - 1, n - j - 1);	
	return dp1[i + minNum][j + minNum];
}

ll getSum2(int i, int j) {
	ll sum = 0;
	int minNum = min(n - i - 1, j);
	return dp2[i + minNum][j - minNum];
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> n;
	mat.resize(n, vl(n));
	dp1.resize(n, vl(n));
	dp2.resize(n, vl(n));
	fr(i, 0, n) {
		fr(j, 0, n) {
			cin >> mat[i][j];
			if(i - 1 >= 0 && j - 1 >= 0) {
				dp1[i][j] = dp1[i - 1][j - 1];
			}
			if(i - 1 >= 0 && j + 1 < n) {
				dp2[i][j] = dp2[i - 1][j + 1];
			}
			dp1[i][j] += mat[i][j];
			dp2[i][j] += mat[i][j];
		}
	}
	ll odd = -1, even = -1;
	pii a1, a2;
	fr(i, 0, n) {
		fr(j, 0, n) {
			ll sum = getSum1(i, j);
			ll sum2 = getSum2(i, j);
			if((i + j) % 2 == 0) {
				if(even < sum + sum2 - mat[i][j]) {
					even = sum + sum2 - mat[i][j];
					a1 = {i + 1, j + 1};
				}
			} else {
				if(odd < sum + sum2 - mat[i][j]) {
					odd = sum + sum2 - mat[i][j];
					a2 = {i + 1, j + 1};
				}
			}
		}
	}
	cout << even + odd << '\n';
	cout << a1.first << ' ' << a1.second << ' ' << a2.first << ' ' << a2.second << '\n';

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}