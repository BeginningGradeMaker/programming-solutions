#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  k *= 2;

  vector<int> a(2 * n), o(n+1);

  for (auto &x : a) cin >> x;
  for (int i = 0; i < n; i++) o[a[i]]++;

  vector<int> g0, g1, g2;
  for (int i = 1; i <= n; i++) {
    if (o[i] == 0) g0.push_back(i);
    else if (o[i] == 1) g1.push_back(i);
    else g2.push_back(i);
  }

  int t = 0;
  for (auto x : g2) {
    if (t >= k) {
      break;
    }
    cout << x << ' ' << x << ' ';
    t += 2;
  }
  for (auto x : g1) {
    if (t >= k) {
      break;
    }
    cout << x << ' ';
    t += 1;
  }
  cout << endl;

  t = 0;
  for (auto x : g0) {
    if (t < k) {
      t += 2;
      cout << x << ' ' << x << ' ';
    }
  }
  for (auto x : g1) {
    if (t < k) {
      t++;
      cout << x << ' ';
    }
  }
  cout << endl;
}

int main() {
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
