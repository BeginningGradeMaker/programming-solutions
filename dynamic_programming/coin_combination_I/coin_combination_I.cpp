#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod = 1000000007;

int main() {
    // solution goes here
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);

    dp[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - coins[j] >= 0) {
                dp[i] += dp[i - coins[j]];
                if (dp[i] >= mod) {
                    dp[i] -= mod;
                }
            }
        }
    }

    cout << dp[x];
}
