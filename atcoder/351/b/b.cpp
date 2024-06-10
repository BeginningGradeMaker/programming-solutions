#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
  // Solution goes here
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // Input handling goes here
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j];
    }
  }

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for (int j = 0; j < n; j++) {
      b[i][j] = s[j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != b[i][j]) {
        cout << i + 1 << ' ' << j + 1 << endl;
        return 0;
      }
    }
  }
}
