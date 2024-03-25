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
  // Input handling goes here
  int n; cin >> n;
  vector<int> p(n);

  for (int &x : p) {
    cin >> x;
  }
  vector<int> m(n);
  for (int i = 0; i < n; i++) {
    m[p[i] - 1] = i;
  }

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    cout << (m[a] > m[b] ? b + 1 : a + 1) << endl;
  }
}
