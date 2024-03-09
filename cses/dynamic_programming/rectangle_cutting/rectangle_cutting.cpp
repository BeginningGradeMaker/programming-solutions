#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int m, n;
    cin >> m >> n;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= m; i++) {
        dp[i][1] = i - 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[1][i] = i - 1;
    }
    for (int i = 1; i <= min(m, n); i++) {
        dp[i][i] = 0;
    }

    // dp[i][j] = the minimum number of moves to cut a (i + 1) * (j + 1) rectangle into squares
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= n; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }

    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[m][n] << endl;
}
