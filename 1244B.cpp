#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;

int main() {
  IOS
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    if (str[0] == '1' or str[n-1] == '1') {
      cout << str.length()*2 << endl;
    } else {
      ll ans = str.length();
      for (ll i = 0; i < n; i++) {
        if (str[i] == '1') {
          ans = max(ans, (i+1)*2);
          ll p = str.length();
          p -= i;
          ans = max(ans, 2*p);
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
