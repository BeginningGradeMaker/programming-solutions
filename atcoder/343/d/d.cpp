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
  ll a, b, c; cin >> a, b, c;
  vector<vector<int>> n(2, vector<int>(2, 0));

  for (int i = 0; i < 60; i++) {
    n[a << i & 1][b << i & 1]++;
  }

  
}
