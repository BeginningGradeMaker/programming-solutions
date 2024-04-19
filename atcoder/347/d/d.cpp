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
  int a, b, c; cin >> a >> b >> c;

  vector<vecotor<vector<pair<int, int>>>> dp(n, vector<vector<pair<int, int>>>>(a, vector<pair<int, int>>(b, {-1, -1})));

  bitset<60> C(c);
  if (C[0]) {
    dp[0][1][0] = {1, 0};
    dp[0][0][1] = {0, 1};
  } else {
    dp[0][0][0] = {0, 0};
    dp[0][1][1] = {1, 1};
  }

  for (int i = 1; i < 60; i++) {
    for (int j = 0; j <= )
  }
}
