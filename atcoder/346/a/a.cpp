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

  int a; cin >> a;
  int prev = a;
  for (int i = 1; i < n; i++) {
    cin >> a;
    cout << a * prev << endl;
    prev = a;
  }
}
