/******************************************
*******************************************
*******************************************
	PREPARED BY - SOMESH AWASTHI 
	CHANDIGARH UNIVERSITY
*******************************************
*******************************************
*******************************************/
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
class graph{
	int size;
public:
	vector<vi> mat;
	graph(int n){
		size = n;
		mat.resize(n, vi(n));
	}
	void addEdge(){
		fr(i, 0, size) {
			fr(j, 0, size) {
				cin >> mat[i][j];
			}
		}
	}
	void addDist(int u, int v, int d) {
		mat[u][v] = min(mat[u][v], d);
		mat[v][u] = min(mat[v][u], d);
		fr(i, 0, size) {
			fr(j, 0, size) {
				mat[i][j] = min({mat[i][j], mat[i][u] + mat[u][v] + mat[v][j], mat[i][v] + mat[v][u] + mat[u][j]});
			}
		}
	}
	void sum() {
		ll sum = 0;
		fr(i, 0, size) {
			fr(j, 0, size) {
				sum += mat[i][j];
				// cout << mat[i][j] << ' ';
			}
			// cout << '\n';
		}
		cout << sum / 2 << ' ';
	}
};

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n;
	cin >> n;
	graph g(n);
	g.addEdge();
	int m;
	cin >> m;
	while(m--) {
		int u, v, d;
		cin >> u >> v >> d;
		g.addDist(u - 1, v - 1, d);
		g.sum();
	}

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}