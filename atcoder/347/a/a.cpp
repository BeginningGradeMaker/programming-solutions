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
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x % k == 0) cout << x / k << ' ';
  }
  cout << endl;
}
