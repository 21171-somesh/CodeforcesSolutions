#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[3];
    arr[0] = arr[1] = arr[2] = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr[x]++;
    }
    int twos = arr[2] , ones = arr[1];
    if(arr[1] == 0){
        while(twos--)
            cout<<2<<" ";
        return 0;
    }else if(arr[2] == 0){
        while(ones--)
            cout<<1<<" ";
        return 0;
    }else{
        cout<<"2 1 ";
        twos--, ones--;
        while(twos--){
            cout<<2<<" ";
        }
        while(ones--){
            cout<<1<<" ";
        }
    }
}
