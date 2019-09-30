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

class graph{
	int size;
public:
	vector<vl> dist;
	graph(){
		size = 26;
		dist.resize(26, vl (26, INT_MAX));
		fr(i, 0, 26) {
			dist[i][i] = 0;

		}
	}
	void addEdge(int u, int v, int a){
		dist[u][v] = min(dist[u][v], (ll)a);
	}
	void floydWarshall();
};

void graph::floydWarshall() {
	fr(k, 0, size) {
		fr(i, 0, size) {
			fr(j, 0, size) {
				dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
			}
		}
	}
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	string s, t;
	cin >> s >> t;
	graph g;
	int n;
	cin >> n;
	while(n--) {
		char x, y;
		int a;
		cin >> x >> y >> a;
		g.addEdge(x - 'a', y - 'a', a);
	}
	g.floydWarshall();
	if(s.size() != t.size()) {
		cout << -1;
		return 0;
	}
	int count = 0;
	fr(i, 0, s.size()) {
		if(s[i] != t[i]) {
			ll m = INT_MAX;
			ll index = 0;
			fr(j, 0, 26) {
				ll a = g.dist[s[i] - 'a'][j];
				ll b = g.dist[t[i] - 'a'][j];
				// cout << a << " "  << b << " " << char(j + 'a') << '\n'; 
				if(a >= INT_MAX || b >= INT_MAX) continue; 
				if(a + b < m) {
					index = j;
					m = a + b;
				}
			}
			if(m >= INT_MAX) {
				cout << -1;
				return 0;
			}
			s[i] = index + 'a', t[i] = index + 'a';	
			// if(m == g.dist[s[i] - 'a'][t[i] - 'a']) s[i] = t[i];
			count += m;
		}
	}
	cout << count << '\n' << s;
 
	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}