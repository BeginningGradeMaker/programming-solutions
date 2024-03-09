#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;
vector<vector<int>> out;
vector<vector<int>> in;
vector<int> dp;

int solve(int i, int p) {
  int ans = 0;
  for (int n : out[i]) {
    if (n != p) {
      ans += solve(n, i);
    }
  }
  for (int n : in[i]) {
    if (n != p) {
      ans += solve(n, i) + 1;
    }
  }

  return ans;
}

void dfs(int i, int p, bool o) {
  // if (i == 2) {
  //   cout << p << ' ' << dp[p] << endl;
  // }
  if (i != p) {
    if (o) {
      dp[i] = dp[p] + 1;
    } else {
      dp[i] = dp[p] - 1;
    }
  }
  
  for (int n : out[i]) {
    if (n != p) {
      dfs(n, i, true);
    }
  }
  for (int n : in[i]) {
    if (n != p) {
      dfs(n, i, false);
    }
  }
}

int main() {
  // solution goes here
  int n; cin >> n;
  out = vector<vector<int>>(n+1);
  in = vector<vector<int>>(n+1);
  dp = vector<int>(n+1, 0);
  for (int i = 0; i < n-1;i++) {
    int s, t; cin >> s >> t;
    out[s].push_back(t);
    in[t].push_back(s);
  }
  dp[1] = solve(1, 0);
  dfs(1, 1, false);

  dp[0] = INT_MAX;
  int m = (*min_element(dp.begin(), dp.end()));
  cout << m << endl;
  for (int i = 1; i <= n; i++) {
    if (dp[i] == m) {
      cout << i << ' ';
    }
  }
  cout << endl;
  
}
