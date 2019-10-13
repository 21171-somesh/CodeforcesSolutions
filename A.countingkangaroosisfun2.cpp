#include <iostream>
#include <algorithm>

using namespace std;

int arr[5*(int)1e5 + 5];

bool bs( int m, int i ) {
	if ( 2*arr[m] <= arr[i] ) return true;
	return false;
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr,arr+n);

	int ans = n;

	int start = 0;
	int end = n/2 - ( n % 2 == 0 ? 1 : 0 );
	int end2 = end;
	
	
	int k = -1;
	int mid;
	for (int i = n-1; i > end2; --i)
	{
		
		while( start <= end ) {
			mid = ( start + end ) / 2;
		    if ( bs( mid , i ) )
		    {
		    	start = mid + 1;
		    	k = mid;
		    }
		    else
		    {
		    	end = mid - 1;
		    }
		}

		if ( k == -1 ) {
			
			break;
		}
		else {
			
			end = k - 1;
			k = -1;
			start = 0;
			ans--;
			
		}
	}


	
	printf("%d\n", ans);
}
