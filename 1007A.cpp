#include <bits/stdc++.h>
using namespace std ; 
#define ll long long
#define flp(i ,a ,b) for(int  i = a ; i<b ; i++)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define blp(i, a , b) for(int  i = a ; i<=b ; i--)

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}



int main()
{	int n ; 
	cin>>n ; 
	vector <int> v ; 
	flp(i,0,n)
	{
		int x ; 
		cin>>x ; 
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int ans =0 ; 
	int j = 1  ; 
	for(int i = 0 ; i<n && j<n ; )
	{	
		if(v[i]<v[j])
		{	
			
			i++;
			j++;
			ans++;
		}
		else
		{
			j++;
		}

	}
	cout<<ans ; 
}