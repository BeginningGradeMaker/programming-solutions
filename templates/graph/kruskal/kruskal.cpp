#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e9 + 7;
ll N = 200005;

struct DisjoinSet {
  ll n;
  vector<ll> parent;
  vector<ll> size;

  DisjoinSet(ll n) : n{n + 1} {
    parent.resize(n + 1);
    size.resize(n + 1);

    for (ll i = 1; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  ll find(ll x) {
    if (x == parent[x]) {
      return x;
    }

    return parent[x] = find(parent[x]);
  }

  bool same(ll a, ll b) { return find(a) == find(b); }

  void union_sets(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      size[a] += size[b];
      parent[b] = a;
    }
  }
};

struct Kruskal {
  static ll run(ll n, vector<vector<ll>> &edges) {
    sort(edges.begin(), edges.end(), [&](vector<ll> &v1, vector<ll> &v2) {
      // sort by weight
      return v1[2] < v2[2];
    });

    DisjoinSet ds(n);
    ll ans = 0;
    int cnt = 0;
    for (vector<ll> edge : edges) {
      ll a = edge[0], b = edge[1];
      if (!ds.same(a, b)) {
        ans += edge[2];
        ds.union_sets(a, b);
        cnt++;
      }
    }

    return cnt == n - 1 ? ans : -1;
  }
};

int main() {
  // Input handling goes here
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> edges(m, vector<ll>(3));

  for (ll i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
  }
  
  ll ans = Kruskal::run(n, edges);
  if (ans >= 0) {
    cout << ans << endl;
  } else {
    cout << "orz" << endl;
  }
}
