//verma_ankit484

#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;

int main() {
  IOS
  #ifdef AV
  freopen("int.txt", "r", stdin);
  #endif
  ll n;
  cin >> n;
  unordered_map<ll, ll> mpe;
  unordered_map<ll, ll> mpo;
  mpe[0]++;
  vector<ll> vc(n);
  ll ans = 0;
  for (ll i = 0; i < n; i++) cin >> vc[i];
  ll p = 0;
  for (ll i = 0; i < n; i++) {
    p ^= vc[i];
    if (i%2 == 0) {
      ans += mpo[p];
      mpo[p]++;
    } else {
      ans += mpe[p];
      mpe[p]++;
    }
  }
  cout << ans << endl;
  return 0;
}
