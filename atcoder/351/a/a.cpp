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
  int n = 9;

  vector<int> a(n), b(n-1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) cin >> b[i];

  cout << accumulate(a.begin(), a.end(), 0) - accumulate(b.begin(), b.end(), 0) + 1 << endl;
}
