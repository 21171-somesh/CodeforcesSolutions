#include <iostream>

using namespace std;

int order[201];

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) 
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
		   	scanf("%d", &order[i]);
		}
		bool dance = true;
		for (int i = 0; i < n; ++i)
		{
			if ( i==n-1){
				if (order[i] == n && order[0]==1) continue;
				if (order[i]==order[0]-1) continue;
			}
			if ( order[i] == n && order[i+1] == 1 ) continue;
		    if ( order[i] == order[i + 1] -1 ) continue;
		    //printf("en el indice %d salio \n", i);
		    dance = false;
		    break;
		}
		if (dance)
		{
			printf("YES\n");
			continue;
		}
		dance = true;
		for (int i = 0; i < n; ++i)
		{
			if ( i==n-1){
				if (order[i]==order[0]+1) continue;
				if (order[i]==1 && order[0]==n) continue;
			}
			if ( order[i] == 1 && order[i+1] == n ) continue;
		    if ( order[i] == order[i + 1] +1 ) continue;
		    //printf("en el indice %d salio \n", i);
			dance = false;
			break;
		}
		if (dance)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");    
	}
}
