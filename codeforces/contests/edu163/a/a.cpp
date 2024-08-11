#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
  // solution goes here
  int t; cin >> t;
  for (int j = 0; j < t; j++) {
    int n; cin >> n;
    if (n % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (i % 4 == 0 || i % 4 == 1) cout << 'A';
      else cout << 'B';
    }
    cout << endl;
  }
}
