#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
}

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> cost(n);
  for (int &x : cost) {
    cin >> x;
  }

  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2, 0)));

  // dp[i][j][k] := the minimum cost required to modify 1st to ith bit characters
  // such that first i characters has exactly j pairs with same value, and the ith
  // character is k
  // If s[i] == 0, then dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j][1]),
  //                    dp[i][j][1] = min(dp[i-1][j-1][1], dp[i-1][j][0]) + C_i
  // If s[i] == 1, then dp[i][j][0] = min(dp[i-1][j-1][0], dp[i-1][j][1]) + C_i
  //                    dp[i][j][1] = min(dp[i-1][j-1][1], dp[i-1][j][0])
  // Note that dp[i][0][k] can be computed as inital values.

  dp[0][0][0] = s[0] == '0' ? 0 : cost[0];
  dp[0][0][1] = s[0] == '1' ? 0 : cost[0];
  for (int i = 1; i < n; i++) {
    dp[i][0][0] = dp[i-1][0][1];
    dp[i][0][1] = dp[i-1][0][0];

    if (s[i] == '0') dp[i][0][1] += cost[i];
    else dp[i][0][0] += cost[i];
  }

  dp[0][1][0] = INF;
  dp[0][1][1] = INF;
  for (int i = 1; i < n; i++) {
    if (s[i] == '0') {
      dp[i][1][0] = min(dp[i-1][0][0], dp[i-1][1][1]);
      dp[i][1][1] = min(dp[i-1][1][0], dp[i-1][0][1]) + cost[i];
    } else {
      dp[i][1][0] = min(dp[i-1][0][0], dp[i-1][1][1]) + cost[i];
      dp[i][1][1] = min(dp[i-1][1][0], dp[i-1][0][1]);
    }
  }

  cout << min(dp[n-1][1][0], dp[n-1][1][1]) << endl;
}
