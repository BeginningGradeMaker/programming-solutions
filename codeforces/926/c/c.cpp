#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  // solution goes here
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll k, x, a;
    cin >> k >> x >> a;
    // suppose we lost z coins, then next win must earn us
    // y (k - 1) > z, otherwise we both lose the promotion
    // and decrease the a.
    ll z = 0;
    bool yes = true;
    for (int j = 0; j <= x; j++) {
      ll y = (z / (k - 1)) + 1;
      z += y;
      if (z > a) {
        yes = false;
        break;
      }
    }
    cout << (yes ? "YES" : "NO") << endl;
  }
}
