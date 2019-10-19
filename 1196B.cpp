#include<bits/stdc++.h>
 
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define print(x) cout<<x<<"\n"
#define For(i,x,y) for(i = x; i < y; i++)
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef long long ll;
int INF = 999999;
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    int q,n,k;
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>n>>k;
        int arr[2 * 100000];
        int odds = 0;
        int y = 0;
        for(int j = 0;j < n; j++){
            int x;
            cin>>x;
            if(x % 2 != 0){
                odds++;
                arr[y] = j + 1;
                y++;
            }
        }
        if (k > odds) {
            cout<<"NO\n";
        } else if ((odds - (k - 1)) % 2 == 0) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
            for (int j = 0; k - 1 > 0; j++) {
                cout<<arr[j]<<" ";
                k--;
            }
            cout<<n<<endl;
        }
    }
}
