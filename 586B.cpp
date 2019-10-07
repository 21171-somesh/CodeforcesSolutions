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
	fr(i, 0, n) {
		fr(j, 0, n) {
			cin >> mat[i][j];
		}
	}
	ll two = mat[1][0] * mat[2][1];
	two /= mat[0][2];
	two = sqrt(two);
	vl arr(n);
	fr(i, 0, n) {
		if(i != 1) {
			arr[i] = mat[i][1] / two;
		} else {
			arr[i] = two;
		}
	}
	fr(i, 0, n) {
		cout << arr[i] << ' ';
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}