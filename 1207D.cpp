//verma_ankit484
 
#include<bits/stdc++.h>
 
typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = 998244353;
 
using namespace std;
 
ll fact[300005];
 
void doit() {
  fact[0] = 1;
  for (ll i = 1; i <= 300001; i++) {
    fact[i] = fact[i-1]*i;
    fact[i] %= mod;
  }
}
 
int main() {
  IOS
  #ifdef AV
  freopen("int.txt", "r", stdin);
  #endif
  doit();
  ll n;
  cin >> n;
  vector<pair<ll, ll> > vc(n);
  for (ll i = 0; i < n; i++) {
    cin >> vc[i].first >> vc[i].second;
  }
  sort(vc.begin(), vc.end(), less<pair<ll, ll>>());
  unordered_map<ll, ll> mp1, mp2;
  for (ll i = 0; i < n; i++) {
    mp1[vc[i].first]++;
    mp2[vc[i].second]++;
  }
  ll ans1 = 1;
  ll ans2 = 1;
  for (auto i : mp1) {
      ans1 *= fact[i.second];
    ans1 %= mod;
  }
  for (auto i : mp2) {
      ans2 *= fact[i.second];
    ans2 %= mod;
  }
  map<pair<ll, ll>, ll> mp;
  for (ll i = 0; i < n; i++) {
    mp[{vc[i].first, vc[i].second}]++;
  }
  bool chk = true;
  for (ll i = 0; i < n-1; i++) {
    if (vc[i].second > vc[i+1].second) {
      chk = false;
      break;
    }
  }
  ll bt = 0;
  if (chk) bt = 1;
  for (auto i : mp) {
    bt *= fact[i.second];
    bt %= mod;
  }
  ll ans = (ans1+ans2-bt+mod)%mod;
  cout << (fact[n]-ans+mod)%mod << endl;
  return 0;
}
