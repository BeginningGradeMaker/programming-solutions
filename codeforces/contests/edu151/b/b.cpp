#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
  // Solution goes here
  int x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  int xb = x2 - x1, yb = y2 - y1;
  int xc = x3 - x1, yc = y3 - y1;

  int ans = 0;
  if ((xb > 0 && xc > 0) || (xb < 0 && xc < 0)) {
    ans += min(abs(xb), abs(xc));
  }
  if ((yb > 0 && yc > 0) || (yb < 0 && yc < 0)) {
    ans += min(abs(yb), abs(yc));
  }

  cout << ans + 1 << endl;
}

int main() {
  // Input handling goes here
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
