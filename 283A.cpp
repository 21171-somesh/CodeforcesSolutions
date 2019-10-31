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
	int n;
	cin >> n;
	vector<pair<int, int>> numbers(1);
	double sum = 0, total = 1;
	while (n--) {
		int queryType;
		cin >> queryType;
		if (queryType == 1) {
			int x, a;
			cin >> a >> x;
			sum += x * a;
			a -= 1;
			numbers[a].second += x;
		} else if (queryType == 2) {
			int x;
			cin >> x;
			numbers.push_back(pair<int, int> (x, 0));
			sum += x;
			total++;
		} else {
			total--;
			sum -= numbers.back().first + numbers.back().second;
			int inc = numbers.back().second;
			numbers.pop_back();
			numbers.back().second += inc;
		}
		cout << fixed << setprecision(10);
		cout << sum / total << '\n';
	}
	return 0;
}
