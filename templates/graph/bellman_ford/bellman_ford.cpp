#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

struct Edge {
  int u, v, w;
};

vector<ll> bellman_ford(vector<Edge> &edges, int n, int s) {
  vector<ll> d(n+1, INT_MAX);
  d[s] = 0;

  for (int i = 1; i < n; i++) {
    bool any = false;
    for (auto e : edges) {
      if (d[e.u] + e.w < d[e.v]) {
        d[e.v] = d[e.u] + e.w;
        any = true;
      }
    }
    if (!any) break;
  }

  return d;
}

int main() {
  // Input handling goes here
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<Edge> edges;
  int n, m, s; cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  auto d = bellman_ford(edges, n, s);
  for (int i = 0; i < n; i++) {
    cout << d[i+1] << ' ';
  }
  cout << endl;
}
