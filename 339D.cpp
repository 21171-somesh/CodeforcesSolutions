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

const int ARR = 140000;
const int MAX = 4 * ARR + 2;
int N;

vl segTree(MAX, 0), arr(ARR, 0);

void init(ll l, ll  r, ll pos, int type){
	if(l == r) {
		segTree[pos] = (arr[l]);
		return;
	}
	ll mid = (l + r) >> 1;
	//cout<<type<<endl;
	init(l , mid , pos << 1, type + 1);
	//cout<<type<<endl;
	init(mid + 1 , r , (pos << 1) | 1, type + 1);
	if(type % 2 == 0){
		//cout<<type<<" "<<pos<<endl;
		segTree[pos] = (segTree[pos * 2] | segTree[pos * 2 + 1]);
	}else{
		//cout<<type<<" "<<pos<<endl;
		segTree[pos] = (segTree[pos * 2] ^ segTree[pos * 2 + 1]);
	}
}

void update(ll pos, ll l, ll r, ll start, ll end, ll v, int type){
	if(start > end || start > r || end < l){
		return;
	}
	if(start >= l && end <= r){
		segTree[pos] = v;
		return;
	}
	ll mid = (start + end)/2;
	update(pos * 2, l, r, start, mid, v, type + 1);
	update(pos * 2 + 1, l, r, mid + 1, end, v, type + 1);
	if(type % 2 == 0){
		segTree[pos] = (segTree[pos * 2] | segTree[pos * 2 + 1]);
	}else
		segTree[pos] = (segTree[pos * 2] ^ segTree[pos * 2 + 1]);
}

void display(){
	fr(i,0,16){
		cout<<segTree[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	io
	#ifdef SOMU
		clock_t startTime = clock();
		freopen("input.txt","r",stdin);
	#endif

	int n, m;
	cin>>n>>m;
	N = (int)pow(2, n);
	fr(i,0,N){
		cin>>arr[i];
	}
	int type = (n%2 == 0)?1:0;
	init(0, N - 1, 1, type);
	//display();
	while(m--){
		int a, b;
		cin>>a>>b;
		update(1, a - 1, a - 1, 0, N - 1, b, type);
		//display();
		cout<<segTree[1]<<'\n';
	}

	#ifdef SOMU
		cout << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	#endif
	return 0;
}