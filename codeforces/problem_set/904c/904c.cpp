#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> l(n), r(n);

  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }

  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    if (l[i] != 1) {
      arr.emplace_back(l[i], 1);
      arr.emplace_back(r[i] + 1, -1);
    }
  }
  sort(arr.begin(), arr.end());
  int ans = 0, cur = 0, lst = 0;
  for (auto [x, y] : arr) {
    if (x > lst) {
      ans = max(ans, cur);
    }
    cur += y;
    lst = x;
  }

  arr.clear();
  for (int i = 0; i < n; i++) {
    if (r[i] != m) {
      arr.emplace_back(l[i], 1);
      arr.emplace_back(r[i] + 1, -1);
    }
  }
  sort(arr.begin(), arr.end());
  cur = 0; lst = 0;
  for (auto [x, y] : arr) {
    if (x > lst) {
      ans = max(ans, cur);
    }
    cur += y;
    lst = x;
  }
  cout << ans << endl;
}

int main() {
  // solution goes here
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
