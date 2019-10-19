#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long x,y,z;
    cin>>x>>y>>z;
    int buy = (x + y) / z;
    int k = x/z + y/z;
    if(k == buy){
        cout<<(x/z + y/z)<<" 0";
    }else{
        long long O_o = min(z - (x % z), z - (y % z));
        cout<<(x/z + y/z + 1)<<" "<<O_o;
    }
    return 0;
}
