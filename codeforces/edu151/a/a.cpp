#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
  int n, k, x; cin >> n >> k >> x;

  if (x != 1) {
    cout << "YES" << endl << n << endl;
    for (int i = 0; i < n; i++) {
      cout << 1 << ' ';
    }
    cout << endl;
  } else {
    if (k == 1) {
      cout << "NO" << endl;
      return;
    }

    if (n % 2 == 0) {
      cout << "YES" << endl << n / 2 << endl;
      for (int i = 0; i < n / 2; i++) {
        cout << 2 << ' ';
      }
      cout << endl;
      return;
    }

    if (k == 2 && n % 2) {
      cout << "NO" << endl;
      return;
    }

    int cnt = (n - 3) / 2;
    cout << "YES" << endl << cnt + 1 << endl;
    for (int i = 0; i < cnt; i++) {
      cout << 2 << ' ';
    }
    cout << 3 << ' ' << endl;
  }
}

int main() {
  // Input handling goes here
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
