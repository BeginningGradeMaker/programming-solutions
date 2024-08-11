#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int INF = 0x3f3f3f3f;
int mod = 1e9 + 7;
int N = 200005;

void solve() {
    // Solution goes here
    int n, m, b, mod; cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // dp[i][j][t] = the number of good plans for the first i+1 players
    // to write m lines of code with exactly b bugs
    // = dp[i][j][t] + dp[i][j-1][t-a[i]]
    vector<vector<int>> dp(m+1, vector<int>(b+1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = a[i]; k <= b; k++) {
                dp[j][k] += dp[j-1][k - a[i]];
                dp[j][k] %= mod;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= b; i++) {
        ans = (ans + dp[m][i]) % mod;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Input handling goes here
    solve();
}
