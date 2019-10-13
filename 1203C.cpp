#include <iostream>
#include <math.h>
#include <algorithm>


using namespace std;

long long arr[4*(int)1e5 + 5];



int main() {
	int n;
	long long mn = 1e12 + 5;
	long long mn2 = mn;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &arr[i]);
		if (arr[i]<mn) {
			mn = arr[i];
			mn2 = mn;
		}
		else if (arr[i]<mn2) {
			mn2 = arr[i];
		}
	}
	long long mini = __gcd(mn,mn2);
		for (int i = 0; i < n; ++i)
		{
			if (arr[i]%mini==0) continue;
			mini = __gcd(arr[i],mini);
		}
		long long count = 0;
		for (int i = 1; i <= sqrt(mini); ++i)
		{
			if (mini%i==0) {
				if (mini/i==i) count++;
				else count += 2;
			}
		}
		
		printf("%lld\n", count);
}

