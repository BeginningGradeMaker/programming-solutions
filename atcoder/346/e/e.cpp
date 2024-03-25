#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll INF = 0x3f3f3f3f;
ll mod = 1e9 + 7;
ll N = 200005;

void solve() {
  // Solution goes here
}

int main() {
  // Input handling goes here
  ll h, w, m; cin >> h >> w >> m;
  vector<vector<ll>> vec(m, vector<ll>(3));

  for (auto &v : vec) {
    cin >> v[0] >> v[1] >> v[2];
  }

  ll rc = 0, cc = 0;
  map<ll, ll> color;
  unordered_set<ll> cols, rows;

  for (ll i = m-1; i >= 0; i--) {
    vector<ll> &op = vec[i];
    if (op[0] == 1) {
      if (!rows.count(op[1])) {
        rows.insert(op[1]);
        color[op[2]] += (w - cc);
        rc++;
      } 
    } else {
      if (!cols.count(op[1])) {
        cols.insert(op[1]);
        color[op[2]] += (h - rc);
        cc++;
      }
    }
  }

  ll paint = 0;
  for (auto pair : color) {
    paint += pair.second;
  }
  color[0] += (w * h - pall);

  ll cnt = 0;
  for (auto pair : color) {
    if (pair.second != 0) {
      cnt++;
    }
  }

  cout << cnt << endl;
  for (auto pair : color) {
    if (pair.second != 0) cout << pair.first << ' ' << pair.second << endl;
  }
}
