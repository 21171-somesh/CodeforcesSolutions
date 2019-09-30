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

const int ARR = 100010;
const int MAX = 4 * ARR + 2;

vector<vector<pll>> segTree(20, vector<pll>(MAX, {0, 0}));
vector<vi> lazy(20, vi(MAX, 0));
vi arr(ARR, 0);
vector<vi> mat(20, vi(ARR, 0));
int n;

pll merge(pll left, pll right){
	pll a;
	a.first = left.first + right.first;
	a.second = left.second + right.second;
	return a;
}

void push(ll pos, ll l, ll r, ll i){
	if(lazy[i][pos] != 0){
		if(lazy[i][pos] % 2 != 0){
			swap(segTree[i][pos].first, segTree[i][pos].second);
		}
		if(l != r){
			lazy[i][pos * 2] = (lazy[i][pos * 2] + lazy[i][pos]) % 2;
			lazy[i][pos * 2 + 1] = (lazy[i][pos * 2 + 1] + lazy[i][pos]) % 2;
		}
		lazy[i][pos] = 0;
	}
}

pll query(ll l, ll r, ll start, ll end, ll pos, ll i){
	push(pos, start, end, i);
	if(start > r || end < l){
		return {0, 0};
	}
	if(start >= l && end <= r){
		return segTree[i][pos];
	}
	else{
		ll mid = (start + end)/2;
		return merge(query(l, r, start, mid, pos * 2, i), query(l, r, mid + 1, end, pos * 2 + 1, i));
	}
}

void init(ll l, ll  r, ll pos, ll i){
	if(l == r) {
		if(mat[i][l] == 1)
			segTree[i][pos] = {1, 0};
		else
			segTree[i][pos] = {0, 1};
		lazy[i][pos] = 0;
		return;
	}
	ll mid = (l + r) >> 1;
	init(l , mid , pos << 1, i);
	init(mid + 1 , r , (pos << 1) | 1, i);
	segTree[i][pos] = merge(segTree[i][(pos << 1)], segTree[i][((pos << 1) | 1)]);
}

void update(ll pos, ll l, ll r, ll start, ll end, int i){
	push(pos, start, end, i);
	if(start > end || start > r || end < l){
		return;
	}
	if(start >= l && end <= r){
		swap(segTree[i][pos].first, segTree[i][pos].second);
		if(start != end){
			lazy[i][pos * 2] = (lazy[i][pos * 2] + 1) % 2;
			lazy[i][pos * 2 + 1] = (lazy[i][pos * 2 + 1] + 1) % 2;
		}
		return;
	}
	ll mid = (start + end)/2;
	update(pos * 2, l, r, start, mid, i);
	update(pos * 2 + 1, l, r, mid + 1, end, i);
	segTree[i][pos] = merge(segTree[i][pos * 2], segTree[i][pos * 2 + 1]);
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	cin>>n;
	fr(i,0,n) cin>>arr[i];
	fr(i,0,20){
		fr(j,0,n){
			mat[i][j] = (arr[j] & (1<<i)) ? 1 : 0;
		}
	}
	fr(i,0,20){
		init(0, n - 1, 1, i);
	}
	int m;
	cin >> m;
	while(m--){
		int type;
		cin >> type;
		if(type == 1){
			int l, r;
			cin >> l >> r;
			l--, r--;
			ll ans = 0;
			fr(i,0,20){
				pll a = query(l, r, 0, n - 1, 1, i);
				ans += (ll)a.first * (ll)(1 << i);
			}
			cout<<ans<<'\n';
		}
		else{
			int l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			fr(i,0,20){
				if(x & (1 << i)){
					update(1, l, r, 0, n - 1, i);
				}
			}
		}
	}


	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}