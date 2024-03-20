#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

// NOTE: The algorithm is 0-indexed
class Dijkstra {
  vector<vector<pair<int, int>>> graph;
  int n;

public:
  void build(int n, vector<vector<int>> &edges) {
    this->n = n;
    graph.resize(n);
    for (auto edge : edges) {
      graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
  }

  vector<int> run(int s) {
    vector<int> d(n, INT_MAX);
    vector<bool> vis(n, false);

    d[s] = 0;
    priority_queue<pair<int, int>> Q;
    Q.push({0, s});

    while (!Q.empty()) {
      int u = Q.top().second;
      Q.pop();

      if (vis[u]) {
        continue;
      }
      vis[u] = true;

      for (auto p : graph[u]) {
        int v = p.first, w = p.second;
        if (d[v] > d[u] + w) {
          d[v] = d[u] + w;
          if (!vis[v]) {
            Q.push({-d[v], v});
          }
        }
      }
    }

    return d;
  }
};

void solve() {
  // Solution goes here
}

int main() {
  // Input handling goes here
  int n, m, s;
  cin >> n >> m >> s;
  vector<vector<int>> edges;
  for (int i = 0; i < m; i++) {
    vector<int> edge(3);
    cin >> edge[0] >> edge[1] >> edge[2];
    edge[0]--; edge[1]--;
    edges.push_back(edge);
  }

  Dijkstra djk;
  djk.build(n, edges);
  vector<int> d = djk.run(s-1);

  for (int x : d) {
    cout << x << ' ';
  }
  cout << endl;
}
