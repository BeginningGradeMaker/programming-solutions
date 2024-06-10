#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

vector<unordered_set<int, int>> cnt;
int ans = 0;

void solve(int u, int p, vector<vector<int>> &nbr) {
  for (int v : nbr[u]) {
    if (v != p) {
      solve(v, u, nbr);
    }
  }
  for (int v : nbr[u]) {

  }
}

int main() {
  // solution goes here
  int n, k; cin >> n >> k;
  vector<vector<int>> nbr;

  for (int i = 0; i < n-1; i++) {
    int u, v; cin >> u >> v;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  solve(1, 1, nbr);
}
