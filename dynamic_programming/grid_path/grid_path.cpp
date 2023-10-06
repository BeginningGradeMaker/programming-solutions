#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n;
    cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }

    if (grid[n - 1][n - 1] == false) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n));

    bool h = true, v = true;
    for (int i = n - 1; i >= 0; i--) {
        if (grid[n - 1][i] == false) {
            h = false;
        }
        if (grid[i][n - 1] == false) {
            v = false;
        }
        dp[i][n - 1] = v ? 1 : 0;
        dp[n - 1][i] = h ? 1 : 0;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (grid[i][j] == false) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                if (dp[i][j] >= mod) {
                    dp[i][j] -= mod;
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[0][0];
}
