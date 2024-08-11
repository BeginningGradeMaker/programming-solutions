#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

void solve() {
  int n; cin >> n;
  string R1, R2;
  cin >> R1 >> R2;

  for (int i = 0; i < n-1; i++) {
    if (i % 2 == 0 && R2[i] == '<' && R1[i+1] == '<') {
      cout << "NO" << endl;
      return;
    } else if (i % 2 == 1 && R1[i] == '<' && R2[i+1] == '<') {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  // solution goes here
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
