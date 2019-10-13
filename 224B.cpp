#include <iostream>

using namespace std;

const int maxN = 1e5 + 2;

int arr[maxN];
int c[maxN];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if ( k > n )
	{
		printf("-1 -1\n");
		return 0;
	}
	if ( n==1 && k==1)
	{
		printf("1 1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
		c[ arr[i] ] = 0;
	}
	int start, end;
	int count = 0;
	pair<int,int> ans = {-1,-1};
	start = end = 0;
	while( end <= n) {
		//printf("%d %d %d\n", start, end, count);
		while( c[ arr[start] ] > 1 ) {
		    c[ arr[start] ]--;
		    start++;
		}
		if ( count == k && ( ans.first == -1 || end - start < ans.second - ans.first )) ans = {start,end-1};
		if ( end == n) break;
		if ( count < k ) {
			if ( c[ arr[end] ] == 0 ) count++;
			c[ arr[end] ]++;
			end++;
		}
		else {
			c[ arr[start] ]--;
			start++;
			count--;
		}
	}
	if (ans.second==-1) {
		printf("-1 -1\n");
	}
	else {
		printf("%d %d\n", ans.first+1, ans.second+1);
	}
}
