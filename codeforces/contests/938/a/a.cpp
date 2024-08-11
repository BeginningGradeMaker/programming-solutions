#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
  // Solution goes here
  int n, a, b; cin >> n >> a >> b;
  cout << n / 2 * min(b, a * 2) + n % 2 * a << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // Input handling goes here
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
