//verma_ankit484
 
#include<bits/stdc++.h>
 
typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;
 
using namespace std;
 
ll n, k;
 
vector<vector<ll> > adj;
vector<vector<ll> > dist;
 
ll ans;
 
void dfs(ll s, ll p) {
  dist[s][0] = 1;
  for (auto i : adj[s]) {
    if (i != p) {
      dfs(i, s);
      for (ll q = 0; q < k; q++) {
        ans += dist[s][q]*dist[i][k-q-1];
      }
      for (ll q = 1; q <= k; q++) {
        dist[s][q] += dist[i][q-1];
      }
    }
  }
}
 
int main() {
  IOS
  #ifdef AV
  freopen("int.txt", "r", stdin);
  #endif
  cin >> n >> k;
  adj.resize(n+1);
  dist.assign(n+1, vector<ll> (k+1, 0));
  for (ll i = 0; i < n-1; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1, -1);
  cout << ans << endl;
  return 0;
}
