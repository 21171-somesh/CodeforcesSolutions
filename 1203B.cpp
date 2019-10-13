#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[402];
map<int,int> mp;
int mult;

int main() {
	int t, n;
	int aux;
	scanf("%d", &t);
	while(t--) {
	    scanf("%d", &n);
	    for (int i = 0; i < 4*n; ++i)
	    {
	    	scanf("%d", &arr[i]);
	    	if (mp.find(arr[i])==mp.end()){
	    		mp[arr[i]] = 1;
	    	}
	    	else
	    	{
	    		mp[arr[i]]++;
	    	}
	    }
	    bool ans = true;
	    for (auto p: mp)
	    {
	    	if (p.second %2 ==1)
	    	{
				ans = false;
	    		break;
	    	}
	    }
	    mp.clear();

	    if (ans)
	    {

	    	sort(arr,arr+4*n,greater<int>());
	    	mult = arr[0]*arr[4*n-1];
	    	for (int i = 0; i < 2*n; i = i+2)
	    	{
	    		
	    		if (mult == arr[i]*arr[4*n-i-1]) continue;
	    		ans = false;
	    	}
	    }
	    if (ans) printf("YES\n");
	    else printf("NO\n");
	}
}
