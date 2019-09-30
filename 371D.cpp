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
vi arr;
vi brr;
set<int> s;

void pour(int pos, int litre) {
	auto it = s.lower_bound(pos);
	vi remove;
	while(litre && it != s.end()) {
		int u = *it;
		int rem = arr[u] - brr[u];
		if(rem > litre) {
			brr[u] += litre;
			litre = 0;
		} else {
			brr[u] = arr[u];
			litre -= rem;
			it++;
			remove.push_back(u);
		}
	}
	for(auto it : remove) {
		s.erase(s.find(it));
	}
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n;
	cin >> n;
	arr.resize(n);
	brr.resize(n);
	fr(i, 0, n) {
		cin >> arr[i];
		s.insert(i);
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		if(x == 1) {
			int a, b;
			cin >> a >> b;
			pour(a - 1, b);
		} else {
			int a;
			cin >> a;
			cout << brr[a - 1] << '\n';
		}
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}