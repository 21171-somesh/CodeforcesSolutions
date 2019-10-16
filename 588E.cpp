//verma_ankit484
 
#include<bits/stdc++.h>
 
typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;
 
using namespace std; 
ll n, m, q;
vector<vector<ll>> adj;
vector<vector<ll>> pp;
ll lvl;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;
vector<ll> sum;
 
void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= lvl; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
 
    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
 
    tout[v] = ++timer;
}
 
bool is_ancestor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = lvl; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
 
void preprocess(ll root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    lvl = ceil(log2(n+1));
    up.assign(n+1, vector<ll>(lvl + 1));
    dfs(root, root);
}
 
struct Node {
  ll x;
  Node* l, *r;
  Node(Node* _l = NULL , Node* _r = NULL , ll _x = 0) {
    l = _l;
    r = _r;
    x = _x;
  }
};
 
Node* versions[200009];
void build(Node* tree , ll l , ll r) {
  if(r < l) return;
  if(l == r) {
    tree->x = 0;
    return;
  }
  ll mid = (l + r) >> 1;
  tree->l = new Node();
  tree->r = new Node();
  build(tree->l , l , mid);
  build(tree->r , mid + 1 , r);
  tree->x = tree->l->x + tree->r->x;
}
void update(Node* old, Node* curr, ll l , ll r , ll idx , ll val) {
  if(idx < l || idx > r || r < l) return;
  if(l == r) {
   curr->x = old->x+val;
   return;
  }
  ll mid = (l + r) >> 1;
  if(idx <= mid) {
   curr->r = old->r;
   curr->l = new Node();
   update(old->l , curr->l , l , mid , idx , val);
  } else {
   curr->l = old->l;
   curr->r = new Node();
   update(old->r , curr->r , mid + 1 , r , idx , val);
  }
  curr->x = curr->l->x + curr->r->x;
}
 
ll query(Node* u, Node* v, Node* lc, Node* pr, ll l, ll r, ll k) {
  if (l == r) return l;
  ll o;
  if (pr == NULL) o = 0;
  else o = pr->l->x;
  ll p = u->l->x + v->l->x - lc->l->x - o;
  ll mid = (l+r)>>1;
  if (p >= k) {
    return query(u->l, v->l, lc->l, pr == NULL? NULL: pr->l, l, mid, k);
  } else {
    return query(u->r, v->r, lc->r, pr == NULL? NULL: pr->r, mid+1, r, k-p); 
  }
}
 
 
ll k1, k2;
 
void dfs2(ll s, ll p, ll sm) {
  sum[s] = sm + pp[s].size();
  ll pk = 0;
  for (auto i : pp[s]) {
    ll o = p;
    if (p == -1) o = 0;
    if (pk == 0) {
      versions[k1] = new Node();
      update(versions[o], versions[k1], 0, m, i, 1);
      k1++;
      pk = 1;
    } else {
      versions[k1] = new Node();
      update(versions[k1-1], versions[k1], 0, m, i, 1);
      k1++;
    }
  }
  if (pk != 0) {
    versions[s] = new Node();
    update(versions[k1-1], versions[s], 0, m, 1, 0);
  } else {
    versions[s] = new Node();
    ll o = p;
    if (p == -1) o = 0;
    update(versions[o], versions[s], 0, m, 0, 0);
  }
  for (auto i : adj[s]) {
    if (i != p) {
      dfs2(i, s, sm + pp[s].size());
    }
  }
}
 
int main() {
  IOS
  #ifdef AV
  freopen("int.txt", "r", stdin);
  #endif
  k1 = 100002;
  cin >> n >> m >> q;
  adj.resize(n+1);
  pp.resize(n+1);
  sum.resize(n+1);
  for (ll i = 0; i < n-1; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  ll k;
  for (ll i = 1; i <= m; i++) {
    cin >> k;
    pp[k].pb(i);
  }
  preprocess(1);
  versions[0] = new Node();
  build(versions[0], 0, m);
  dfs2(1, -1, 0);
  for (ll i = 0; i < q; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll lc = lca(a, b);
    ll pr = up[lc][0];
    ll o2 = pr == lc? 0 : sum[pr];
    ll o = sum[a]+sum[b]-sum[lc] - o2;
    k = min(c, o);
    vector<ll> vc;
    for(ll j = 1; j <= k; j++) {
      o = query(versions[a], versions[b], versions[lc], pr == lc ? NULL: versions[pr], 0, m, j);
      vc.pb(o);
    }
    cout << vc.size() << ' ';
    for (auto j : vc) cout << j << ' ';
    cout << endl;
  }
  return 0;
}
