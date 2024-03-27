#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = INT_MAX;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
  // Solution goes here
}

int main() {
  // Input handling goes here
  int n; cin >> n;
  vector<ll> q(n), a(n), b(n);

  for (ll &x : q) cin >> x;
  for (ll &x : a) cin >> x;
  for (ll &x : b) cin >> x;

  ll max_a = INF;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) max_a = min(max_a, q[i] / a[i]);
  }

  // enumerate number of dish A
  ll ans = 0;
  for (int i = 0; i <= max_a; i++) {
    ll max_b = INF;
    for (int j = 0; j < n; j++) {
      if (b[j] > 0) max_b = min(max_b, (q[j] - i * a[j]) / b[j]);
    }
    ans = max(ans, i + max_b);
  }

  cout << ans << endl;
}
