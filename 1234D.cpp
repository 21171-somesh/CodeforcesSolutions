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

string s;
int n;
const int ARR = 100010;
const int MAX = 4 * ARR + 2;

vector<vl> segTree(26, vl(MAX, 0));

ll query(ll l, ll r, ll start, ll end, ll pos, ll type){
	if(start > r || end < l){
		return 0;
	}
	if(start >= l && end <= r){
		return segTree[type][pos];
	}
	else{
		ll mid = (start + end) / 2;
		return query(l, r, start, mid, pos * 2, type) + query(l, r, mid + 1, end, pos * 2 + 1, type);
	}
}

void init(ll l, ll  r, ll pos, ll type){
	if(l == r) {
		segTree[type][pos] = (s[l] - 'a' == type);
		return;
	}
	ll mid = (l + r) >> 1;
	init(l , mid , pos << 1, type);
	init(mid + 1 , r , (pos << 1) | 1, type);
	segTree[type][pos] = segTree[type][pos << 1] + segTree[type][(pos << 1) | 1];
}

void update(ll pos, ll l, ll r, ll start, ll end, ll v, ll type){
	if(start > end || start > r || end < l){
		return;
	}
	if(start >= l && end <= r){
		segTree[type][pos] += v;
		return;
	}
	ll mid = (start + end)/2;
	update(pos * 2, l, r, start, mid, v, type);
	update(pos * 2 + 1, l, r, mid + 1, end, v, type);
	segTree[type][pos] = segTree[type][pos << 1] + segTree[type][(pos << 1) | 1];;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin >> s;
	n = (int) s.size();
	fr(i, 0, 26) {
		init(0, n - 1, 1, i);
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x == 1) {
			int pos;
			char ch;
			cin >> pos >> ch;
			pos--;
			int prev = s[pos] - 'a';
			s[pos] = ch;
			update(1, pos, pos, 0, n - 1, -1, prev);
			update(1, pos, pos, 0, n - 1, 1, ch - 'a');
		} else {
			int l, r;
			cin >> l >> r;
			l--, r--;
			int count = 0;
			fr(i, 0, 26) {
				int temp = query(l, r, 0, n - 1, 1, i);
				count += (temp > 0);
			}
			cout << count << '\n';
		}
	}

	#ifdef SOMU
		cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}
