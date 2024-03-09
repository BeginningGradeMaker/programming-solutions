#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 5000));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
            dp[i][j] = min(dp[i][j], min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[a.length()][b.length()];
}
