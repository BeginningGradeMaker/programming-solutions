#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, m;
    cin >> n >> m;
    vector<ll> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    /*
    * dp[n][m] 
    * = the number of beautiful arrays of size n that ends
    * with m = dp[n - 1][m - 1] + dp[n - 1][m] + dp[n - 1][m + 1]
    */
    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    /* initial conditions:
    *   dp[0][i] = 0 if nums[0] != i and nums[0] != 0
    *   dp[0][i] = 1 if nums[0] == i or nums[0] == 0
    */
    for (int i = 0; i < m; i++) {
        if (nums[0] != i + 1 && nums[0] != 0) {
            dp[0][i] = 0;
        } else {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nums[i] == 0 || nums[i] == j + 1) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
                } else if (j == m - 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
                    if (dp[i][j] >= mod) {
                        dp[i][j] -= mod;
                    }
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
            if (dp[i][j] >= mod) {
                dp[i][j] -= mod;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    ll ans = 0;
    for (ll num : dp[n - 1]) {
        ans += num;
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans;
}
