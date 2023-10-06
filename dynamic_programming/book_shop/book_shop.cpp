#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    /*
    * dp[n][x] = number of pages one can purchase with books 1...n and 
    * money x = max(dp[n - 1][x], dp[n - 1][x - prices[n]] + pages[n])
    */
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= x; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - prices[i - 1] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= x; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][x];
}
